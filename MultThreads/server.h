#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QDebug>
#include "thread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void StartServer();

protected:
    void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
