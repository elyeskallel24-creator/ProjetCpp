QT += core gui sql widgets printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    employe.cpp \
    databasemanager.cpp \
    employedao.cpp

HEADERS += \
    mainwindow.h \
    employe.h \
    databasemanager.h \
    employedao.h

FORMS += \
    mainwindow.ui

# Robust copy command for Windows to copy files directly to the debug folder
win32 {
    QMAKE_POST_LINK += $$QMAKE_COPY $$shell_path($$PWD/theme.qss) $$shell_path($$OUT_PWD/debug/) $$escape_expand(\n\t)
    QMAKE_POST_LINK += $$QMAKE_COPY $$shell_path($$PWD/logo.png) $$shell_path($$OUT_PWD/debug/) $$escape_expand(\n\t)
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target