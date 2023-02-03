#include "netServer.h"
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Core/Log/logger.h"

namespace {
const int MESSAGE_LEN = 256;
}

namespace Net {
Server::Server() : listenFd(-1), threadFd(-1), status(STATUS::STOP)
{}

bool Server::Start(const std::string &ip, int port)
{
    if (status != STATUS::STOP) {
        return true;
    }

    // Check the ip.
    if (ip.empty() || port == 0) {
        ERRORLOG("Net has error value with ip and port. [ip=%s][port=%s]", ip.c_str(), std::to_string(port).c_str());
        return false;
    }
    // Init socket fd.
    if((listenFd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        ERRORLOG("Net init failed. [error=%d]", errno);
        return false;
    }

    // Bind the address which dedicated by params.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(sockaddr_in));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip.c_str());
    servaddr.sin_port = htons(port);
    if(bind(listenFd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        ERRORLOG("Net Bind failed. [error=%d]", errno);
        return false;
    }

    // Listen the server fd.
    if(listen(listenFd, 10) == -1) {
        ERRORLOG("Net listen failed. [error=%d]", errno);
        return false;
    }

    // Start the server.
    status = STATUS::RUNNING;
    if (pthread_create(&threadFd, nullptr, StartServer, this) == -1) {
        ERRORLOG("Net start failed. [error=%d]", errno);
        status = STATUS::STOP;
        return false;
    }
    INFOLOG("Net server start successed.");
    return true;
}

void *Server::StartServer(void *param)
{
    Server *server = reinterpret_cast<Server *>(param);
    while(server->status == STATUS::RUNNING){
        int connfd;
        if((connfd = accept(server->listenFd, (struct sockaddr*)NULL, NULL)) == -1) {
            ERRORLOG("Net accept a broken client. [error=%s]", errno);
            continue;
        }

        // TODO: 
        close(connfd);
    }

    close(server->listenFd);
    return nullptr;
}

void *Server::DealMessage(void *)
{
    return nullptr;
}

void Server::Stop()
{
    INFOLOG("asdfasdfasdfasdf   %d", listenFd);
    status = STATUS::STOP;
    pthread_join(listenFd, nullptr);
    listenFd = -1;
    INFOLOG("Net stop succeed.");
    return;
}
} // namesapce Net
