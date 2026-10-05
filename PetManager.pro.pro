QT       += core gui widgets

TARGET    = PetManager
TEMPLATE  = app

CONFIG   += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# /utf-8 uniquement pour MSVC (Visual Studio)
msvc {
    QMAKE_CXXFLAGS += /utf-8
}