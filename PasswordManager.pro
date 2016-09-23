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
    base.cpp \
    mainwindow.cpp

HEADERS  += \
    record.h \
    base.h \
    mainwindow.h

FORMS    += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
