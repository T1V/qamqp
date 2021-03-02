#ifndef TSTQAMQPEXCHANGE
#define TSTQAMQPEXCHANGE

#include <QtTest/QtTest>

#include "qamqptestcase.h"

#include "qamqpclient.h"
#include "qamqpexchange.h"
#include "qamqpqueue.h"

class tst_QAMQPExchange : public TestCase
{
    Q_OBJECT
private Q_SLOTS:
    void init();
    void cleanup();

    void standardTypes_data();
    void standardTypes();
    void invalidStandardDeclaration_data();
    void invalidStandardDeclaration();
    void invalidDeclaration();
    void invalidRedeclaration();
    void removeIfUnused();
    void invalidMandatoryRouting();
    void invalidImmediateRouting();
    void confirmsSupport();
    void confirmDontLoseMessages();
    void passiveDeclareNotFound();
    void cleanupOnDeletion();
    void testQueuedPublish();
    void referenceCountExchanges();

private:
    QScopedPointer<QAmqpClient> client;

};

#endif
