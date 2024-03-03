TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15

SOURCES += \
        dbmanagement-tests.cpp \
        keyvalue-tests.cpp

include(../kvdb/Defines.pri)

macx:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../kvdb/ -lkvdb
else: macx:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../kvdb/ -lkvdb

HEADERS += \
    catch.hpp \
    tests.h
