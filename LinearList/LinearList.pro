TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    linearlist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    linearlist.h \
    except.h

