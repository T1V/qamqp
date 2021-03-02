QT += testlib network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
  main.cpp \
    tst_qamqpchannel.cpp \
    tst_qamqpclient.cpp \
    tst_qamqpexchange.cpp \
    tst_qamqpqueue.cpp

RESOURCES = certs.qrc

INCLUDEPATH += common ../src
LIBS += -L../src -lqamqp

HEADERS += \
  common/qamqptestcase.h \
  tst_qamqpchannel.h \
  tst_qamqpclient.h \
  tst_qamqpexchange.h \
  tst_qamqpqueue.h
