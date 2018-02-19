#-------------------------------------------------
#
# Project created by QtCreator 2016-08-12T05:59:12
#
#-------------------------------------------------

QT += core
QT += gui
QT += widgets

TARGET = NeuralNetwork

TEMPLATE = app

CONFIG += console
CONFIG += c++14



SOURCES += \
    $$PWD/neuralNetwork.cpp \
    $$PWD/perceptron.cpp \
    $$PWD/neuralNetworkGettersAndSetters.cpp \

HEADERS += $$PWD/perceptron.h \
    $$PWD/neuralNetwork.h \

Matthieu {

INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.16299.0/ucrt" \

QMAKE_LIBDIR += "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x64/" \
                "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/ucrt/x64" \


QMAKE_CFLAGS_RELEASE += /MT
QMAKE_CXXFLAGS_RELEASE += /MT

QMAKE_CFLAGS_DEBUG += /MTd
QMAKE_CXXFLAGS_DEBUG += /MTd

CONFIG(release, debug|release) {

    QMAKE_CXXFLAGS += /O2
    QMAKE_LFLAGS_RELEASE += /NODEFAULTLIB:msvcrt.lib \

}
CONFIG(debug, debug|release) {

    QMAKE_CXXFLAGS += /O0
    DEFINES += _DEBUG
    QMAKE_LFLAGS_DEBUG   += /NODEFAULTLIB:msvcrtd.lib \
                            /NODEFAULTLIB:libcmt.lib
}

}

Theo {

blabla

}
