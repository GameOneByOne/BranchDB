#include "netClient.h"
#include <sys/socket.h>

namespace Net {
Client::Client() : port(-1), remoteFd(-1)
{}

Client::Client(Client &&rhs)
{

}

Client::~Client()
{

}

bool Client::ConnectTo(const std::string &ip, int port)
{
    return true;
}

bool Client::Send(const std::string &sendData)
{
    return true;
}

bool Client::Recv(const std::string &sendData)
{
    return true;
}

void Client::Shutdown()
{
    return;
}

bool Client::ReConnectTo()
{
    return true;
}
} // namesapce Net
