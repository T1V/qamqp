#include "tst_qamqpchannel.h"

void tst_QAMQPChannel::init()
{
    client.reset(new QAmqpClient);
    client->connectToHost();
    QVERIFY(waitForSignal(client.data(), SIGNAL(connected())));
}

void tst_QAMQPChannel::cleanup()
{
    if (client->isConnected()) {
        client->disconnectFromHost();
        QVERIFY(waitForSignal(client.data(), SIGNAL(disconnected())));
    }
}

void tst_QAMQPChannel::close()
{
    // exchange
    QAmqpExchange *exchange = client->createExchange("test-close-channel");
    QVERIFY(waitForSignal(exchange, SIGNAL(opened())));
    exchange->declare(QAmqpExchange::Direct);
    QVERIFY(waitForSignal(exchange, SIGNAL(declared())));
    exchange->close();
    QVERIFY(waitForSignal(exchange, SIGNAL(closed())));
    exchange->reopen();
    QVERIFY(waitForSignal(exchange, SIGNAL(opened())));
    exchange->remove(QAmqpExchange::roForce);
    QVERIFY(waitForSignal(exchange, SIGNAL(removed())));

    // queue
    QAmqpQueue *queue = client->createQueue("test-close-channel");
    QVERIFY(waitForSignal(queue, SIGNAL(opened())));
    declareQueueAndVerifyConsuming(queue);
    queue->close();
    QVERIFY(waitForSignal(queue, SIGNAL(closed())));
}

void tst_QAMQPChannel::resume()
{
    QAmqpQueue *queue = client->createQueue("test-resume");
    QVERIFY(waitForSignal(queue, SIGNAL(opened())));
    declareQueueAndVerifyConsuming(queue);

    queue->resume();
    QVERIFY(waitForSignal(queue, SIGNAL(resumed())));
}

void tst_QAMQPChannel::sharedChannel()
{
    QString routingKey = "test-shared-channel";
    QAmqpQueue *queue = client->createQueue(routingKey);
    declareQueueAndVerifyConsuming(queue);

    QAmqpExchange *defaultExchange = client->createExchange("", queue->channelNumber());
    defaultExchange->publish("first message", routingKey);
    QVERIFY(waitForSignal(queue, SIGNAL(messageReceived())));
    QAmqpMessage message = queue->dequeue();
    verifyStandardMessageHeaders(message, routingKey);
    QCOMPARE(message.payload(), QByteArray("first message"));
}

void tst_QAMQPChannel::defineWithChannelNumber()
{
    QString routingKey = "test-specific-channel-number";
    QAmqpQueue *queue = client->createQueue(routingKey, 25);
    declareQueueAndVerifyConsuming(queue);
    QCOMPARE(queue->channelNumber(), 25);
}
