#include "tst_qamqpchannel.h"
#include "tst_qamqpclient.h"
#include "tst_qamqpexchange.h"
#include "tst_qamqpqueue.h"

int main(int argc, char *argv[])
{
   int status = 0;
   QCoreApplication app(argc, argv);

   {
       tst_QAMQPChannel ta;
       status |= QTest::qExec(&ta, argc, argv);
   }
   {
       tst_QAMQPClient ta;
       status |= QTest::qExec(&ta, argc, argv);
   }
   {
       tst_QAMQPExchange ta;
       status |= QTest::qExec(&ta, argc, argv);
   }
   {
       tst_QAMQPQueue ta;
       status |= QTest::qExec(&ta, argc, argv);
   }

   if (status != 0) {
     qWarning("TESTS FAILED");
   }
   return status;
}
