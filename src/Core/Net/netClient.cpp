#include "netClient.h"
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Core/Log/logger.h"

namespace {
const int BUFSIZE = 256;
}

namespace Net {
Client::Client() : remotePort(-1), remoteFd(-1)
{}

Client::Client(Client &&rhs)
{
    remotePort = rhs.remotePort;
    remoteFd = rhs.remoteFd;
    remoteIp = rhs.remoteIp;
    rhs.remotePort = -1;
    rhs.remoteFd = -1;
    rhs.remoteIp = "";
}

Client::~Client()
{
    Client::Shutdown();
}

bool Client::ConnectTo(const std::string &ip, int port)
{
    if (ip.empty() || port < 0) {
        ERRORLOG("Net client receive error params to connect. [ip=%s][port=%d]", ip.c_str(), port);
        return false;
    }
    sockaddr_in remoteAddr;
    remoteAddr.sin_family = AF_INET;
    remoteAddr.sin_port = htons(port);
    remoteAddr.sin_addr.s_addr = inet_addr(ip.c_str());

    if((remoteFd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        ERRORLOG("Net client init failed. [error=%d]", errno);
        return false;
    }
    if (connect(remoteFd, (struct sockaddr *)&remoteAddr, sizeof(remoteAddr)) == -1) {
        ERRORLOG("Net client connect failed. [error=%d]", errno);
        return false;
    }
    return true;
}

bool Client::Send(const std::string &sendData)
{
    const int flags = MSG_DONTWAIT | MSG_NOSIGNAL;
    char buf[BUFSIZE] = { 0 };
    memcpy(buf, sendData.c_str(), sendData.size());
    if (send(remoteFd, buf, sendData.size(), flags) == -1) {
        ERRORLOG("Net client send message failed. [error=%d]", errno);
        return false;
    }
    return true;
}

bool Client::Recv(const std::string &sendData)
{
    char buf[BUFSIZE] = { 0 };
    if (recv(remoteFd, buf, BUFSIZE, MSG_DONTWAIT) == -1) {
        ERRORLOG("Net client recv message failed. [error=%d]", errno);
        return false;
    }
    return true;
}

void Client::Shutdown()
{
    if (remoteFd > 0) {
        close(remoteFd);
        remoteFd = -1;
    }
    remotePort = -1;
    remoteIp = "";
    
    return;
}

bool Client::ReConnectTo()
{
    return true;
}
} // namesapce Net
