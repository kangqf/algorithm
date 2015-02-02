TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sequentialsearch.cpp \
    binarysearch.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sequentialsearch.h \
    binarysearch.h

