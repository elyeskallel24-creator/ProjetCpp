QT += widgets sql charts printsupport svg
CONFIG += c++17

# Accents et emojis du code bien lus avec le compilateur MSVC
msvc: QMAKE_CXXFLAGS += /utf-8

SOURCES += \
    accueilpage.cpp \
    animauxpage.cpp \
    parametrespage.cpp \
    customdialog.cpp \
    databasemanager.cpp \
    fournisseur.cpp \
    fournisseurdao.cpp \
    main.cpp \
    mainwindow.cpp \
    mockcommandesprovider.cpp \
    supplierrecommender.cpp \
    badgedelegate.cpp \
    icondelegate.cpp \
    graphiques.cpp

HEADERS += \
    accueilpage.h \
    animauxpage.h \
    parametrespage.h \
    customdialog.h \
    databasemanager.h \
    fournisseur.h \
    fournisseurdao.h \
    mainwindow.h \
    mockcommandesprovider.h \
    supplierrecommender.h \
    badgedelegate.h \
    icondelegate.h \
    graphiques.h

FORMS += mainwindow.ui
RESOURCES += resources.qrc \
    ressources.qrc
