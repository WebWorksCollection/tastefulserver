#pragma once

#include <QAbstractSocket>

#include <tastefulserver/tastefulserver_api.h>

#include <tastefulserver/Task.h>

namespace tastefulserver {

class AbstractSocket;

class TASTEFULSERVER_API Connection : public Task
{
    Q_OBJECT

public:
    Connection(qintptr socketDescriptor);
    ~Connection();

    void setSocket(AbstractSocket * socket);

    void startUp();

protected:
    qintptr m_socketDescriptor;
    AbstractSocket * m_socket;

    void createSocket();

private slots:
    void disconnected();
};

} // namespace tastefulserver
