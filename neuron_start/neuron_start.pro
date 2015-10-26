#-------------------------------------------------
#
# Project created by QtCreator 2015-10-26T13:27:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = neuron_start
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    Config.cpp \
    Environment.cpp \
    Logger.cpp \
    Neuron.cpp \
    NeuronPool.cpp \
    OutNeuron.cpp \
    SensorNeuron.cpp

HEADERS  += mainwindow.h \
    Config.h \
    Environment.h \
    INeuron.h \
    Logger.h \
    Neuron.h \
    NeuronPool.h \
    OutNeuron.h \
    SensorNeuron.h

FORMS    += mainwindow.ui
