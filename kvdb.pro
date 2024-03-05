TEMPLATE = subdirs

SUBDIRS += \
    kvdb \
    kvdb-cli \
    kvdb-tests

kvdb-tests.depends = kvdb
kvdb-cli.depends = kvdb

CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=

HEADERS +=
