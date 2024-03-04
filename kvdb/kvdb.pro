CONFIG -= qt

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/database.cpp \
    src/kvdb.cpp

HEADERS += \
    include/database.h \
    include/extensions/databaseext.h \
    include/kvdb.h

INCLUDEPATH += include

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Defines.pri
