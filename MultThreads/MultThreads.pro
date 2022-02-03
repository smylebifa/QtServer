QT += core
QT += network
QT -= gui

TARGET = MultThreads
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp \
    thread.cpp

HEADERS += \
    server.h \
    thread.h

