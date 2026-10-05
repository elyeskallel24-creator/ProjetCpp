QT += widgets sql charts printsupport svg
CONFIG += c++17

SOURCES += \
    customdialog.cpp \
    databasemanager.cpp \
    fournisseur.cpp \
    fournisseurdao.cpp \
    main.cpp \
    mainwindow.cpp \
    mockcommandesprovider.cpp \
    supplierrecommender.cpp \
    badgedelegate.cpp \
    icondelegate.cpp

HEADERS += \
    customdialog.h \
    databasemanager.h \
    fournisseur.h \
    fournisseurdao.h \
    mainwindow.h \
    mockcommandesprovider.h \
    supplierrecommender.h \
    badgedelegate.h \
    icondelegate.h

FORMS += mainwindow.ui
RESOURCES += resources.qrc