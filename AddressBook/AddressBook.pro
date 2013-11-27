#-------------------------------------------------
#
# Project created by QtCreator 2013-11-27T15:57:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AddressBook
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    TableModel.cpp \
    AddressWidget.cpp

HEADERS  += MainWindow.h \
    TableModel.h \
    AddressWidget.h
