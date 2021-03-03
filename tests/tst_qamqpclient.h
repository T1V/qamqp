#ifndef TSTQAMQPClient
#define TSTQAMQPClient

#include <QtTest/QtTest>
#include <QProcess>
#include <QSslKey>

#include "qamqptestcase.h"
#include "qamqpauthenticator.h"
#include "qamqpexchange.h"
#include "qamqpqueue.h"
#include "qamqpclient_p.h"
#include "qamqpclient.h"

class tst_QAMQPClient : public TestCase
{
    Q_OBJECT
private Q_SLOTS:
    void connect();
    void connectProperties();
    void connectHostAddress();
    void connectDisconnect();
    void invalidAuthenticationMechanism();
    void tune();
    void socketError();
    void validateUri_data();
    void validateUri();
    void issue38();
    void issue38_take2();
    void referenceCountExchanges();

public Q_SLOTS:     // temporarily disabled
    void autoReconnect();
    void autoReconnectTimeout();
    void sslConnect();

private:
    QSslConfiguration createSslConfiguration();
    void issue38_helper(QAmqpClient *client);

};

#endif
