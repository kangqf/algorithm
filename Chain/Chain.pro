TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    chain.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    chain.h \
    except.h

