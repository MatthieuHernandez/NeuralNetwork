# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = GUI
DESTDIR = ./bin/debug
QT += core gui widgets printsupport
CONFIG += debug console
DEFINES += _CONSOLE _UNICODE WIN64 QT_PRINTSUPPORT_LIB QT_WIDGETS_LIB
INCLUDEPATH += "$(ProjectDir)/../../NeuralNetwork/src/Header Files" \
    "$(ProjectDir)/../Data/src/Header Files" \
    "$(ProjectDir)/src/Header Files" \
    "$(ProjectDir)/src/Source Files" \
    ./GeneratedFiles/$(ConfigurationName) \
    ./GeneratedFiles \
    . \
    ./../../src \
    ./../../lib \
    ./debug \
    ../../../../../../include \
    $(QTDIR)/mkspecs/win32-msvc
DEPENDPATH += .
#MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += "./src/Header Files/Controller.h" \
    "./src/Header Files/mainwindow.h" \
    "./External Library/qcustomplot.h"
SOURCES += "./src/Source Files/Controller.cpp" \
    "./src/Source Files/main.cpp" \
    "./src/Source Files/mainwindow.cpp" \
    "./External Library/qcustomplot.cpp"
FORMS += ./mainwindow.ui
