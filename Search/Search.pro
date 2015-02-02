TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sequentialsearch.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sequentialsearch.h

