#-------------------------------------------------
#
# Project created by QtCreator 2017-09-11T00:20:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testQT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    foodlist.cpp \
    programming.cpp \
    simplex_copy.cpp

HEADERS += \
        mainwindow.h \
    foodlist.h \
    programming.h

FORMS += \
        mainwindow.ui \
    foodlist.ui \
    programming.ui

INCLUDEPATH += \
        /opt/gurobi751/linux64/include

LIBS += -L /opt/gurobi751/linux64/lib -lgurobi_c++

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../opt/gurobi751/linux64/lib/release/ -lgurobi75
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../opt/gurobi751/linux64/lib/debug/ -lgurobi75
else:unix: LIBS += -L$$PWD/../../../opt/gurobi751/linux64/lib/ -lgurobi75

INCLUDEPATH += $$PWD/../../../opt/gurobi751/linux64/include
DEPENDPATH += $$PWD/../../../opt/gurobi751/linux64/include
