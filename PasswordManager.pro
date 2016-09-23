#-------------------------------------------------
#
# Project created by QtCreator 2016-09-23T15:31:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PasswordManager
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        passwordmanager.cpp \
    base.cpp

HEADERS  += passwordmanager.h \
    record.h \
    base.h

FORMS    += passwordmanager.ui

RESOURCES += \
    resources.qrc
