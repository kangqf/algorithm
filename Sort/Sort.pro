TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    selectionsort.cpp \
    bubblesort.cpp \
    insertionsort.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    selectionsort.h \
    Functions.h \
    bubblesort.h \
    insertionsort.h

