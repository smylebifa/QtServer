#include "thread.h"

Thread::Thread(int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void Thread::run()
{
    // thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if (!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    exec();

}

void Thread::readyRead()
{
    QByteArray Data = socket->readAll();

    qDebug() <<socketDescriptor << " Data in: " << Data;

    socket->write(Data);
}

void Thread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";

    socket->deleteLater();
    exit(0);

}

