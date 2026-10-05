#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseurdao.h"
#include "mockcommandesprovider.h"
#include "supplierrecommender.h"
#include "badgedelegate.h"

#include <QTableWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QPixmap>
#include <QIcon>
#include <QHeaderView>
#include <algorithm>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QPageLayout>
#include <QPageSize>
#include <QTextStream>
#include <QStringConverter>
#include <QDate>
#include <QAbstractAxis>
#include <QScrollBar>
#include <QMap>
#include <QColor>
#include <QRegularExpression>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), m_currentId(0) {
    ui->setupUi(this);

    // 1. TABLE SETUP (Fix 1: Column widths & modes)
    ui->tableWidget_fournisseurs->setColumnCount(10);
    ui->tableWidget_fournisseurs->setHorizontalHeaderLabels({"Nom", "Type", "Téléphone", "Email", "Quantité", "Prix unitaire", "Statut", "Date contrat", "Fiabilité", "Actions"});

    ui->tableWidget_fournisseurs->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_fournisseurs->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->tableWidget_fournisseurs->horizontalHeader()->setMinimumSectionSize(60);
    ui->tableWidget_fournisseurs->horizontalHeader()->setStretchLastSection(false);

    QFont headerFont = ui->tableWidget_fournisseurs->horizontalHeader()->font();
    headerFont.setPointSize(11);
    ui->tableWidget_fournisseurs->horizontalHeader()->setFont(headerFont);
    ui->tableWidget_fournisseurs->verticalHeader()->setVisible(false);
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionsMovable(false);
    ui->tableWidget_fournisseurs->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_fournisseurs->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_fournisseurs->verticalHeader()->setDefaultSectionSize(50);

    // Set resize modes AFTER columns exist
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // Nom
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch); // Email
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Fixed);
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(8, QHeaderView::Fixed);
    ui->tableWidget_fournisseurs->horizontalHeader()->setSectionResizeMode(9, QHeaderView::Fixed);

    // Reduced fixed widths (Total ~775px)
    ui->tableWidget_fournisseurs->setColumnWidth(1, 120); // Type
    ui->tableWidget_fournisseurs->setColumnWidth(2, 100); // Tel
    ui->tableWidget_fournisseurs->setColumnWidth(4, 80);  // Qty
    ui->tableWidget_fournisseurs->setColumnWidth(5, 105); // Prix
    ui->tableWidget_fournisseurs->setColumnWidth(6, 85);  // Statut
    ui->tableWidget_fournisseurs->setColumnWidth(7, 100); // Date
    ui->tableWidget_fournisseurs->setColumnWidth(8, 85);  // Fiabilité
    ui->tableWidget_fournisseurs->setColumnWidth(9, 100); // Actions

    // Minimums for Stretch columns
    ui->tableWidget_fournisseurs->horizontalHeader()->setMinimumSectionSize(60); // Global min
    // Note: Stretch columns will take remaining space. If space < 130+160, they might squeeze, but 1150-775=375 is enough.

    // 2. LAYOUT STRETCH (Fix 2: Table height)
    // Items: header(0), kpis(0), toolbar(0), table(3), bottom(2)
    ui->layout_content->setStretch(0, 0); // header
    ui->layout_content->setStretch(1, 0); // kpis
    ui->layout_content->setStretch(2, 0); // toolbar
    ui->layout_content->setStretch(3, 3); // table
    ui->layout_content->setStretch(4, 2); // bottom
    if (ui->frame_bottom) ui->frame_bottom->setMaximumHeight(240);

    // 3. CHART SETUP
    m_chartView = new QChartView();
    m_chartView->setRenderHint(QPainter::Antialiasing);
    if (ui->layout_chart_container) ui->layout_chart_container->addWidget(m_chartView);

    // 4. DELEGATES
    ui->tableWidget_fournisseurs->setItemDelegateForColumn(1, new BadgeDelegate(this));
    ui->tableWidget_fournisseurs->setItemDelegateForColumn(6, new BadgeDelegate(this));
    ui->tableWidget_fournisseurs->setItemDelegateForColumn(8, new BadgeDelegate(this));

    // 5. UI FIXES
    if (ui->layout_right) ui->layout_right->setStretch(1, 1);
    if (ui->scrollArea_form) ui->scrollArea_form->verticalScrollBar()->setValue(0);
    if (ui->label_notif_badge) ui->label_notif_badge->setVisible(false);
    if (ui->label_alerts_badge) ui->label_alerts_badge->setFixedSize(18, 18);

    if (ui->lineEdit_recherche) ui->lineEdit_recherche->setFixedHeight(40);
    if (ui->comboBox_tri) ui->comboBox_tri->setFixedHeight(40);

    auto setupKPI = [](QHBoxLayout *layout, QLabel *iconLabel) {
        if (!layout || !iconLabel) return;
        iconLabel->setFixedSize(48, 48);
        iconLabel->setAlignment(Qt::AlignCenter);
        layout->setStretch(0, 0);
        layout->setStretch(1, 1);
        layout->addStretch();
        layout->setContentsMargins(16, 8, 16, 8);
    };
    setupKPI(ui->layout_kpi1, ui->label_kpi1_icon);
    setupKPI(ui->layout_kpi2, ui->label_kpi2_icon);
    setupKPI(ui->layout_kpi3, ui->label_kpi3_icon);
    if (ui->layout_kpi1_txt) ui->layout_kpi1_txt->setSpacing(0);
    if (ui->layout_kpi2_txt) ui->layout_kpi2_txt->setSpacing(0);
    if (ui->layout_kpi3_txt) ui->layout_kpi3_txt->setSpacing(0);

    // Icons
    if (ui->btn_menu_accueil) ui->btn_menu_accueil->setText(QString::fromUtf8("\xF0\x9F\x8F\xA0 Accueil"));
    if (ui->btn_menu_animaux) ui->btn_menu_animaux->setText(QString::fromUtf8("\xF0\x9F\x90\xBE Animaux"));
    if (ui->btn_menu_rdv) ui->btn_menu_rdv->setText(QString::fromUtf8("\xF0\x9F\x93\x85 Rendez-vous"));
    if (ui->btn_menu_stock) ui->btn_menu_stock->setText(QString::fromUtf8("\xF0\x9F\x93\xA6 Stock"));
    if (ui->btn_menu_commandes) ui->btn_menu_commandes->setText(QString::fromUtf8("\xF0\x9F\x9B\x92 Commandes"));
    if (ui->btn_menu_fournisseurs) ui->btn_menu_fournisseurs->setText(QString::fromUtf8("\xF0\x9F\x9A\x9A Fournisseurs"));
    if (ui->btn_menu_employes) ui->btn_menu_employes->setText(QString::fromUtf8("\xF0\x9F\x91\xA5 Employés"));
    if (ui->btn_menu_parametres) ui->btn_menu_parametres->setText(QString::fromUtf8("\xE2\x9A\x99\xEF\xB8\x8F Paramètres"));

    if (ui->btn_enregistrer) ui->btn_enregistrer->setText(QString::fromUtf8("\xF0\x9F\x92\xBE Enregistrer"));
    if (ui->btn_modifier) ui->btn_modifier->setText(QString::fromUtf8("\xE2\x9C\x8F\xEF\xB8\x8F Modifier"));
    if (ui->btn_annuler) ui->btn_annuler->setText(QString::fromUtf8("\xE2\x9D\x8C Annuler"));
    if (ui->btn_supprimer) ui->btn_supprimer->setText(QString::fromUtf8("\xF0\x9F\x97\x91\xEF\xB8\x8F Supprimer"));
    if (ui->label_export_title) ui->label_export_title->setText(QString::fromUtf8("\xF0\x9F\x93\xA4 Export"));
    if (ui->label_chart_title) ui->label_chart_title->setText(QString::fromUtf8("\xF0\x9F\x93\x8A Statistiques"));
    if (ui->label_alerts_title) ui->label_alerts_title->setText(QString::fromUtf8("\xE2\x9A\xA0\xEF\xB8\x8F Alertes contrat"));
    if (ui->label_sugg_title) ui->label_sugg_title->setText(QString::fromUtf8("\xF0\x9F\x92\xA1 Recommandations"));

    setWindowIcon(QIcon(":/resources/images/logo.png"));
    QPixmap logoPixmap(":/resources/images/logo.png");
    if (!logoPixmap.isNull() && ui->label_logo) {
        ui->label_logo->setPixmap(logoPixmap.scaled(160, 160, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->label_logo->setAlignment(Qt::AlignCenter);
    }

    if (ui->scrollArea_form) {
        ui->scrollArea_form->setStyleSheet("QScrollArea { background: transparent; border: none; }");
        ui->scrollArea_form->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    }

    if (ui->scrollArea_form) {
        QList<QLineEdit*> lineEdits = ui->scrollArea_form->findChildren<QLineEdit*>();
        for (QLineEdit* le : lineEdits) le->setFixedHeight(34);
        QList<QComboBox*> comboBoxes = ui->scrollArea_form->findChildren<QComboBox*>();
        for (QComboBox* cb : comboBoxes) cb->setFixedHeight(34);
        QList<QSpinBox*> spinBoxes = ui->scrollArea_form->findChildren<QSpinBox*>();
        for (QSpinBox* sb : spinBoxes) sb->setFixedHeight(34);
        QList<QDoubleSpinBox*> doubleSpinBoxes = ui->scrollArea_form->findChildren<QDoubleSpinBox*>();
        for (QDoubleSpinBox* dsb : doubleSpinBoxes) dsb->setFixedHeight(34);
        QList<QDateEdit*> dateEdits = ui->scrollArea_form->findChildren<QDateEdit*>();
        for (QDateEdit* de : dateEdits) de->setFixedHeight(34);

        QList<QLabel*> labels = ui->scrollArea_form->findChildren<QLabel*>();
        for (QLabel* lbl : labels) {
            lbl->setFixedHeight(16);
            QFont f = lbl->font(); f.setPointSize(11); lbl->setFont(f);
        }
        if (ui->layout_form) ui->layout_form->setSpacing(3);
    }

    if (ui->dateEdit_contrat) ui->dateEdit_contrat->setDate(QDate::currentDate());

    if (ui->comboBox_rec_type && ui->comboBox_type) {
        ui->comboBox_rec_type->clear();
        ui->comboBox_rec_type->addItem("Tous les types");
        for (int i = 0; i < ui->comboBox_type->count(); ++i) {
            ui->comboBox_rec_type->addItem(ui->comboBox_type->itemText(i));
        }
        connect(ui->comboBox_rec_type, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int){ mettreAJourRecommandations(m_fournisseurs); });
    }

    if (ui->layout_bottom) {
        ui->layout_bottom->setStretch(0, 3);
        ui->layout_bottom->setStretch(1, 2);
        ui->layout_bottom->setStretch(2, 3);
    }

    // Connect Supprimer button
    connect(ui->btn_supprimer, &QPushButton::clicked, this, &MainWindow::on_btn_supprimer_clicked);

    setFormMode(AddMode);
    chargerTableau();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::setFormMode(FormMode mode) {
    if (!ui->btn_enregistrer || !ui->btn_modifier || !ui->btn_annuler || !ui->btn_supprimer) return;

    if (mode == AddMode) {
        ui->btn_enregistrer->setEnabled(true);
        ui->btn_modifier->setEnabled(false);
        ui->btn_annuler->setEnabled(false);
        ui->btn_supprimer->setVisible(false);
        ui->label_form_title->setText("+  Ajouter un fournisseur");
        ui->btn_annuler->setText(QString::fromUtf8("\xE2\x9D\x8C Annuler"));
    } else if (mode == EditMode) {
        ui->btn_enregistrer->setEnabled(false);
        ui->btn_modifier->setEnabled(true);
        ui->btn_annuler->setEnabled(true);
        ui->btn_supprimer->setVisible(true); // Fix 3: Show in Edit mode
        ui->btn_supprimer->setEnabled(true);
        ui->label_form_title->setText(QString::fromUtf8("\xE2\x9C\x8F\xEF\xB8\x8F Modifier le fournisseur"));
        ui->btn_annuler->setText(QString::fromUtf8("\xE2\x9D\x8C Annuler"));
    } else if (mode == ViewMode) {
        ui->btn_enregistrer->setEnabled(false);
        ui->btn_modifier->setEnabled(false);
        ui->btn_annuler->setEnabled(true);
        ui->btn_supprimer->setVisible(false);
        ui->label_form_title->setText(QString::fromUtf8("\xF0\x9F\x91\x81 Consulter le fournisseur"));
        ui->btn_annuler->setText(QString::fromUtf8("\xE2\x9D\x8C Fermer"));
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    if (ui->tableWidget_fournisseurs) {
        // Fix 1: Hide Fiabilité only if viewport is narrow
        int viewportWidth = ui->tableWidget_fournisseurs->viewport()->width();
        bool hideFiab = viewportWidth < 1000;
        ui->tableWidget_fournisseurs->setColumnHidden(8, hideFiab);

        // Debugging (remove in final version if desired, but kept for now as requested)
        // qDebug() << "Viewport width:" << viewportWidth << "Hide Fiab:" << hideFiab;
    }
}

void MainWindow::showMessageBox(const QString &title, const QString &text, QMessageBox::Icon icon) {
    QMessageBox msgBox(this);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setIcon(icon);
    msgBox.addButton("OK", QMessageBox::AcceptRole);
    msgBox.exec();
}

bool MainWindow::showConfirmBox(const QString &text) {
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Confirmation");
    msgBox.setText(text);
    msgBox.setIcon(QMessageBox::Question);
    QAbstractButton* btnOui = msgBox.addButton("Oui", QMessageBox::YesRole);
    msgBox.addButton("Non", QMessageBox::NoRole);
    msgBox.exec();
    return msgBox.clickedButton() == btnOui;
}

void MainWindow::viderFormulaire() {
    m_currentId = 0;
    ui->lineEdit_nom->clear(); ui->lineEdit_contact->clear(); ui->lineEdit_tel->clear();
    ui->lineEdit_email->clear(); ui->lineEdit_adresse->clear();
    ui->comboBox_type->setCurrentIndex(0); ui->comboBox_status->setCurrentIndex(0);
    ui->spinBox_quantite->setValue(0); ui->doubleSpinBox_prix->setValue(0.0);
    if (ui->dateEdit_contrat) ui->dateEdit_contrat->setDate(QDate::currentDate());
    setFormMode(AddMode);
    if (ui->scrollArea_form) ui->scrollArea_form->verticalScrollBar()->setValue(0);
}

void MainWindow::chargerFormulaire(int id, bool readOnly) {
    Fournisseur f = FournisseurDAO::obtenirParId(id);
    if (f.idFournisseur() == 0) return;
    m_currentId = id;
    ui->lineEdit_nom->setText(f.nom()); ui->lineEdit_contact->setText(f.contact());
    ui->lineEdit_tel->setText(f.telephone()); ui->lineEdit_email->setText(f.email());
    ui->lineEdit_adresse->setText(f.adresse()); ui->comboBox_type->setCurrentText(f.typeProduit());
    ui->comboBox_status->setCurrentText(f.status()); ui->dateEdit_contrat->setDate(f.dateContrat());
    ui->spinBox_quantite->setValue(f.quantite()); ui->doubleSpinBox_prix->setValue(f.prixUnitaire());

    ui->lineEdit_nom->setReadOnly(readOnly); ui->lineEdit_contact->setReadOnly(readOnly);
    ui->lineEdit_tel->setReadOnly(readOnly); ui->lineEdit_email->setReadOnly(readOnly);
    ui->lineEdit_adresse->setReadOnly(readOnly);
    ui->comboBox_type->setEnabled(!readOnly); ui->comboBox_status->setEnabled(!readOnly);
    ui->spinBox_quantite->setEnabled(!readOnly); ui->doubleSpinBox_prix->setEnabled(!readOnly);
    ui->dateEdit_contrat->setEnabled(!readOnly);

    setFormMode(readOnly ? ViewMode : EditMode);
    if (ui->scrollArea_form) ui->scrollArea_form->verticalScrollBar()->setValue(0);
}

void MainWindow::on_btn_annuler_clicked() { viderFormulaire(); }

// Fix 3: Supprimer button slot
void MainWindow::on_btn_supprimer_clicked() {
    if (m_currentId == 0) {
        showMessageBox("Attention", "Sélectionnez d'abord un fournisseur.", QMessageBox::Warning);
        return;
    }
    supprimerFournisseur(m_currentId);
}

bool MainWindow::validateForm(QString &errorMsg, QWidget *&focusWidget) {
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString tel = ui->lineEdit_tel->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();
    int quantite = ui->spinBox_quantite->value();
    double prix = ui->doubleSpinBox_prix->value();

    if (nom.isEmpty()) { errorMsg = "Le champ 'Nom' est obligatoire."; focusWidget = ui->lineEdit_nom; return false; }
    if (tel.isEmpty()) { errorMsg = "Le champ 'Téléphone' est obligatoire."; focusWidget = ui->lineEdit_tel; return false; }

    QString digits = tel;
    digits.remove(QRegularExpression("\\D"));
    if (digits.length() < 8) { errorMsg = "Le téléphone doit contenir au moins 8 chiffres."; focusWidget = ui->lineEdit_tel; return false; }

    if (email.isEmpty()) { errorMsg = "Le champ 'Email' est obligatoire."; focusWidget = ui->lineEdit_email; return false; }

    int atPos = email.indexOf('@');
    int dotPos = email.indexOf('.', atPos + 1);
    if (atPos <= 0 || dotPos <= atPos + 1 || email.endsWith('.')) {
        errorMsg = "Format d'email invalide (ex: nom@domaine.com).";
        focusWidget = ui->lineEdit_email;
        return false;
    }

    if (quantite < 0) { errorMsg = "La quantité doit être >= 0."; focusWidget = ui->spinBox_quantite; return false; }
    if (prix < 0) { errorMsg = "Le prix unitaire doit être >= 0."; focusWidget = ui->doubleSpinBox_prix; return false; }

    return true;
}

void MainWindow::on_btn_modifier_clicked() {
    if (m_currentId == 0) { showMessageBox("Attention", "Sélectionnez d'abord un fournisseur.", QMessageBox::Warning); return; }
    QString errorMsg; QWidget *focusWidget = nullptr;
    if (!validateForm(errorMsg, focusWidget)) {
        showMessageBox("Champs invalides", errorMsg, QMessageBox::Warning);
        if (focusWidget) focusWidget->setFocus();
        return;
    }

    QString nom = ui->lineEdit_nom->text().trimmed(), contact = ui->lineEdit_contact->text().trimmed();
    QString tel = ui->lineEdit_tel->text().trimmed(), email = ui->lineEdit_email->text().trimmed();
    QString adresse = ui->lineEdit_adresse->text().trimmed(), typeProduit = ui->comboBox_type->currentText();
    QString status = ui->comboBox_status->currentText();
    QDate dateContrat = ui->dateEdit_contrat->date();
    int quantite = ui->spinBox_quantite->value(); double prix = ui->doubleSpinBox_prix->value();

    Fournisseur f(m_currentId, nom, contact, tel, email, adresse, typeProduit, status, dateContrat, prix, quantite);
    if (FournisseurDAO::modifier(f)) { showMessageBox("Succès", "Fournisseur mis à jour.", QMessageBox::Information); viderFormulaire(); chargerTableau(); }
    else { showMessageBox("Erreur", "Impossible de mettre à jour.", QMessageBox::Critical); }
}

void MainWindow::on_btn_enregistrer_clicked() {
    if (m_currentId != 0) { showMessageBox("Attention", "Mode modification.", QMessageBox::Warning); return; }
    QString errorMsg; QWidget *focusWidget = nullptr;
    if (!validateForm(errorMsg, focusWidget)) {
        showMessageBox("Champs invalides", errorMsg, QMessageBox::Warning);
        if (focusWidget) focusWidget->setFocus();
        return;
    }

    QString nom = ui->lineEdit_nom->text().trimmed(), contact = ui->lineEdit_contact->text().trimmed();
    QString tel = ui->lineEdit_tel->text().trimmed(), email = ui->lineEdit_email->text().trimmed();
    QString adresse = ui->lineEdit_adresse->text().trimmed(), typeProduit = ui->comboBox_type->currentText();
    QString status = ui->comboBox_status->currentText();
    QDate dateContrat = ui->dateEdit_contrat->date();
    int quantite = ui->spinBox_quantite->value(); double prix = ui->doubleSpinBox_prix->value();

    Fournisseur f(0, nom, contact, tel, email, adresse, typeProduit, status, dateContrat, prix, quantite);
    if (FournisseurDAO::inserer(f)) { showMessageBox("Succès", "Fournisseur ajouté.", QMessageBox::Information); viderFormulaire(); chargerTableau(); }
    else { showMessageBox("Erreur", "Impossible d'enregistrer.", QMessageBox::Critical); }
}

void MainWindow::supprimerFournisseur(int id) {
    if (showConfirmBox("Voulez-vous vraiment supprimer ce fournisseur ?")) {
        if (FournisseurDAO::supprimer(id)) { if (m_currentId == id) viderFormulaire(); chargerTableau(); }
        else { showMessageBox("Erreur", "Impossible de supprimer.", QMessageBox::Critical); }
    }
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &) { appliquerFiltreEtTri(); }
void MainWindow::on_comboBox_tri_currentIndexChanged(int) { appliquerFiltreEtTri(); }
void MainWindow::on_comboBox_chart_currentIndexChanged(int) { mettreAJourGraphique(m_fournisseurs); }

void MainWindow::appliquerFiltreEtTri() {
    QString filtre = ui->lineEdit_recherche->text();
    int triIndex = ui->comboBox_tri->currentIndex();
    QList<Fournisseur> listeFiltree;
    for (const Fournisseur &f : m_fournisseurs) { if (f.nom().contains(filtre, Qt::CaseInsensitive)) listeFiltree.append(f); }
    if (triIndex == 1) std::sort(listeFiltree.begin(), listeFiltree.end(), [](const Fournisseur &a, const Fournisseur &b) { return a.nom().toLower() < b.nom().toLower(); });
    else if (triIndex == 2) std::sort(listeFiltree.begin(), listeFiltree.end(), [](const Fournisseur &a, const Fournisseur &b) { return a.nom().toLower() > b.nom().toLower(); });
    remplirTableau(listeFiltree);
}

void MainWindow::chargerTableau() {
    m_fournisseurs = FournisseurDAO::obtenirTous();
    ui->lineEdit_recherche->clear(); ui->comboBox_tri->setCurrentIndex(0);
    appliquerFiltreEtTri();
}

void MainWindow::remplirTableau(const QList<Fournisseur> &liste) {
    ui->tableWidget_fournisseurs->setRowCount(0);
    ui->tableWidget_fournisseurs->setColumnCount(10);

    for (int i = 0; i < liste.size(); ++i) {
        const Fournisseur &f = liste.at(i);
        ui->tableWidget_fournisseurs->insertRow(i);

        QTableWidgetItem *itemNom = new QTableWidgetItem(f.nom());
        itemNom->setToolTip(f.nom());
        ui->tableWidget_fournisseurs->setItem(i, 0, itemNom);

        ui->tableWidget_fournisseurs->setItem(i, 1, new QTableWidgetItem(f.typeProduit()));
        ui->tableWidget_fournisseurs->setItem(i, 2, new QTableWidgetItem(f.telephone()));

        QTableWidgetItem *itemEmail = new QTableWidgetItem(f.email());
        itemEmail->setToolTip(f.email());
        ui->tableWidget_fournisseurs->setItem(i, 3, itemEmail);

        ui->tableWidget_fournisseurs->setItem(i, 4, new QTableWidgetItem(QString::number(f.quantite())));
        ui->tableWidget_fournisseurs->setItem(i, 5, new QTableWidgetItem(QString::number(f.prixUnitaire(), 'f', 3).replace(".", ",") + " TND"));
        ui->tableWidget_fournisseurs->setItem(i, 6, new QTableWidgetItem(f.status()));
        ui->tableWidget_fournisseurs->setItem(i, 7, new QTableWidgetItem(f.dateContrat().toString("dd/MM/yyyy")));

        int reliability = MockCommandesProvider::calculateReliability(f.idFournisseur());
        ui->tableWidget_fournisseurs->setItem(i, 8, new QTableWidgetItem(QString::number(reliability)));

        QWidget *actionWidget = new QWidget();
        QHBoxLayout *actionLayout = new QHBoxLayout(actionWidget);
        actionLayout->setContentsMargins(0, 0, 0, 0); actionLayout->setSpacing(2); actionLayout->addStretch();

        auto createIconButton = [](const QString &iconPath, const QString &tooltip) {
            QPushButton *btn = new QPushButton();
            btn->setIcon(QIcon(iconPath));
            btn->setIconSize(QSize(18, 18));
            btn->setFixedSize(26, 26); btn->setFlat(true); btn->setToolTip(tooltip);
            btn->setCursor(Qt::PointingHandCursor);
            btn->setStyleSheet("QPushButton { background: transparent; border: none; } QPushButton:hover { background-color: #E6F2F1; border-radius: 4px; }");
            return btn;
        };

        QPushButton *btnConsult = createIconButton(":/resources/icons/eye.svg", "Consulter");
        QPushButton *btnEdit = createIconButton(":/resources/icons/pencil.svg", "Modifier");
        QPushButton *btnDelete = createIconButton(":/resources/icons/trash.svg", "Supprimer");

        connect(btnConsult, &QPushButton::clicked, this, [this, id = f.idFournisseur()]() { chargerFormulaire(id, true); });
        connect(btnEdit, &QPushButton::clicked, this, [this, id = f.idFournisseur()]() { chargerFormulaire(id, false); });
        connect(btnDelete, &QPushButton::clicked, this, [this, id = f.idFournisseur()]() { supprimerFournisseur(id); });

        actionLayout->addWidget(btnConsult); actionLayout->addWidget(btnEdit); actionLayout->addWidget(btnDelete);
        ui->tableWidget_fournisseurs->setCellWidget(i, 9, actionWidget);
    }

    ui->label_table_footer->setText(QString("Affichage de %1 sur %2 fournisseurs").arg(liste.size()).arg(m_fournisseurs.size()));
    mettreAJourKPIs(m_fournisseurs);
    mettreAJourGraphique(m_fournisseurs);
    mettreAJourRecommandations(m_fournisseurs);
}

void MainWindow::mettreAJourKPIs(const QList<Fournisseur> &liste) {
    int total = liste.size(); int actifs = 0; int totalReliability = 0;
    for (const Fournisseur &f : liste) {
        if (f.status() == "Actif") actifs++;
        totalReliability += MockCommandesProvider::calculateReliability(f.idFournisseur());
    }
    ui->label_kpi1_value->setText(QString::number(total));
    ui->label_kpi2_value->setText(QString::number(actifs));
    if (total > 0) ui->label_kpi3_value->setText(QString::number(totalReliability / total));
    else ui->label_kpi3_value->setText("—");
}

void MainWindow::mettreAJourGraphique(const QList<Fournisseur> &liste) {
    if (!m_chartView) return;
    if (!m_chartView->chart()) m_chartView->setChart(new QChart());
    QChart *chart = m_chartView->chart();
    chart->setBackgroundBrush(QBrush(Qt::white));
    m_chartView->setStyleSheet("background: white; border: none;");
    chart->setMargins(QMargins(0,0,0,0));
    chart->removeAllSeries();
    QList<QAbstractAxis *> axes = chart->axes(); for (QAbstractAxis *axis : axes) chart->removeAxis(axis);
    chart->setTitle(""); chart->setAnimationOptions(QChart::NoAnimation);

    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Fournisseurs");
    set->setColor(QColor("#2A8C82"));
    QStringList categories; QMap<QString, int> counts;

    int mode = ui->comboBox_chart->currentIndex();
    for (const Fournisseur &f : liste) {
        QString key = (mode == 0) ? f.typeProduit() : f.status();
        counts[key]++;
    }

    // Fix 4: Shorten names for chart labels
    QMap<QString, QString> shortNames = {
        {"Alimentation", "Aliment."}, {"Soins et hygiène", "Soins"}, {"Équipement", "Équip."},
        {"Médicaments", "Médic."}, {"Accessoires", "Access."}
    };

    for (auto it = counts.constBegin(); it != counts.constEnd(); ++it) {
        QString label = it.key();
        if (shortNames.contains(label)) label = shortNames[label];
        categories << label;
        *set << it.value();
    }

    if (categories.isEmpty()) { categories << "Aucune"; *set << 0; }

    series->append(set); chart->addSeries(series);
    QBarCategoryAxis *axisX = new QBarCategoryAxis(); axisX->append(categories); chart->addAxis(axisX, Qt::AlignBottom); series->attachAxis(axisX);

    QFont axisFont; axisFont.setPointSize(8); // Fix 4: Smaller font
    axisX->setLabelsFont(axisFont);
    axisX->setLabelsAngle(0);

    QValueAxis *axisY = new QValueAxis(); axisY->setMin(0);
    int maxVal = 0; for (int v : counts.values()) { if (v > maxVal) maxVal = v; }
    axisY->setMax(maxVal + 1);
    axisY->setLabelFormat("%d");
    axisY->setTickCount(maxVal + 2);
    chart->addAxis(axisY, Qt::AlignLeft); series->attachAxis(axisY);
    chart->legend()->setVisible(false);
}

void MainWindow::mettreAJourRecommandations(const QList<Fournisseur> &liste) {
    ui->listWidget_alertes->clear(); int alertCount = 0;
    for (const Fournisseur &f : liste) {
        if (f.status() == "Suspendu" || f.status() == "Inactif") {
            alertCount++;
            QListWidgetItem *item = new QListWidgetItem(QString::fromUtf8("\xE2\x9A\xA0\xEF\xB8\x8F ") + f.nom() + " (" + f.status() + ")");
            item->setForeground(QColor("#B26A00")); ui->listWidget_alertes->addItem(item);
        }
    }
    if (alertCount == 0) { QListWidgetItem *item = new QListWidgetItem("Aucune alerte"); item->setForeground(QColor("#7B8A8A")); ui->listWidget_alertes->addItem(item); }

    if (ui->label_alerts_badge) {
        ui->label_alerts_badge->setText(QString::number(alertCount));
        ui->label_alerts_badge->setVisible(alertCount > 0);
    }
    if (ui->label_notif_badge) {
        ui->label_notif_badge->setText(QString::number(alertCount));
        ui->label_notif_badge->setVisible(alertCount > 0);
    }

    ui->listWidget_suggestions->clear();
    QString selectedType = ui->comboBox_rec_type->currentText();
    QList<Fournisseur> activeSuppliers;
    for (const Fournisseur &f : liste) {
        if (f.status() == "Actif") {
            if (selectedType == "Tous les types" || f.typeProduit() == selectedType) {
                activeSuppliers.append(f);
            }
        }
    }

    QList<Recommendation> recs = SupplierRecommender::getTop3(selectedType == "Tous les types" ? "" : selectedType, activeSuppliers);

    if (recs.isEmpty()) { QListWidgetItem *item = new QListWidgetItem("Aucune recommandation"); item->setForeground(QColor("#7B8A8A")); ui->listWidget_suggestions->addItem(item); }
    else { for (const Recommendation &r : recs) { QListWidgetItem *item = new QListWidgetItem(QString::fromUtf8("\xF0\x9F\x8F\x86 ") + r.nom + " (Score: " + QString::number(r.score) + ") - " + r.reason); item->setForeground(QColor("#2A8C82")); ui->listWidget_suggestions->addItem(item); } }
}

void MainWindow::on_btn_export_pdf_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageOrientation(QPageLayout::Landscape);

    QString html = "<h2>Liste des fournisseurs - " + QDate::currentDate().toString("dd/MM/yyyy") + "</h2>";
    html += "<table border='1' cellpadding='5' cellspacing='0' style='border-collapse: collapse; width: 100%; font-family: sans-serif;'>";
    html += "<tr><th>ID</th><th>Nom</th><th>Contact</th><th>Téléphone</th><th>Email</th><th>Adresse</th><th>Type</th><th>Quantité</th><th>Prix unitaire</th><th>Statut</th><th>Date contrat</th></tr>";

    for (const Fournisseur &f : m_fournisseurs) {
        html += "<tr>";
        html += "<td>" + QString::number(f.idFournisseur()) + "</td>";
        html += "<td>" + f.nom() + "</td>";
        html += "<td>" + f.contact() + "</td>";
        html += "<td>" + f.telephone() + "</td>";
        html += "<td>" + f.email() + "</td>";
        html += "<td>" + f.adresse() + "</td>";
        html += "<td>" + f.typeProduit() + "</td>";
        html += "<td>" + QString::number(f.quantite()) + "</td>";
        html += "<td>" + QString::number(f.prixUnitaire(), 'f', 3).replace(".", ",") + " TND</td>";
        html += "<td>" + f.status() + "</td>";
        html += "<td>" + f.dateContrat().toString("dd/MM/yyyy") + "</td>";
        html += "</tr>";
    }
    html += "</table>";

    QTextDocument doc;
    doc.setHtml(html);
    doc.print(&printer);
    showMessageBox("Succès", "PDF exporté avec succès.", QMessageBox::Information);
}

void MainWindow::on_btn_export_excel_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en CSV", "", "CSV Files (*.csv)");
    if (fileName.isEmpty()) return;
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out.setEncoding(QStringConverter::Utf8);
        out << QChar(0xFEFF);
        out << "ID;Nom;Contact;Téléphone;Email;Adresse;Type;Quantité;Prix unitaire;Statut;Date contrat\n";
        for (const Fournisseur &f : m_fournisseurs) {
            QString prixStr = QString::number(f.prixUnitaire(), 'f', 3).replace(".", ",");

            auto escape = [](const QString &s) -> QString {
                if (s.contains(";") || s.contains("\"") || s.contains("\n")) {
                    QString r = s;
                    return "\"" + r.replace("\"", "\"\"") + "\"";
                }
                return s;
            };

            out << f.idFournisseur() << ";" << escape(f.nom()) << ";" << escape(f.contact()) << ";" << escape(f.telephone()) << ";"
                << escape(f.email()) << ";" << escape(f.adresse()) << ";" << escape(f.typeProduit()) << ";"
                << f.quantite() << ";" << prixStr << ";" << escape(f.status()) << ";" << f.dateContrat().toString("dd/MM/yyyy") << "\n";
        }
        file.close();
        showMessageBox("Succès", "CSV exporté avec succès.", QMessageBox::Information);
    }
}