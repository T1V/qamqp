#ifndef TSTQAMQPChannel
#define TSTQAMQPChannel

#include <QtTest/QtTest>

#include "qamqptestcase.h"

#include "qamqpclient.h"
#include "qamqpexchange.h"
#include "qamqpqueue.h"

class tst_QAMQPChannel : public TestCase
{
    Q_OBJECT
private Q_SLOTS:
    void init();
    void cleanup();

    void close();
    void resume();
    void sharedChannel();
    void defineWithChannelNumber();

private:
    QScopedPointer<QAmqpClient> client;

};
#endif
