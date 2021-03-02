#ifndef TSTQAMQPQUEUE
#define TSTQAMQPQUEUE

#include <float.h>

#include <QScopedPointer>

#include <QtTest/QtTest>
#include "qamqptestcase.h"

#include "qamqpclient.h"
#include "qamqpqueue.h"
#include "qamqpexchange.h"

class tst_QAMQPQueue : public TestCase
{
    Q_OBJECT
private Q_SLOTS:
    void init();
    void cleanup();

    void defaultExchange();
    void standardExchanges_data();
    void standardExchanges();
    void invalidDeclaration_data();
    void invalidDeclaration();
    void invalidBind();
    void unnamed();
    void exclusiveAccess();
    void exclusiveRemoval();
    void notFound();
    void remove();
    void removeIfUnused();
    void removeIfEmpty();
    void bindUnbind();
    void delayedBind();
    void purge();
    void canOnlyStartConsumingOnce();
    void ensureConsumeOnlySentOnce();
    void cancel();
    void invalidCancelBecauseNotConsuming();
    void invalidCancelBecauseInvalidConsumerTag();
    void getEmpty();
    void get();
    void verifyContentEncodingIssue33();
    void defineQos();
    void invalidQos();
    void qos();
    void invalidRoutingKey();
    void tableFieldDataTypes();
    void messageProperties();
    void emptyMessage();
    void cleanupOnDeletion();

private:
    QScopedPointer<QAmqpClient> client;

};

#endif
