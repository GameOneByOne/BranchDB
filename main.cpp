#include <string>
#include <cstdlib>
#include <iostream>
#include "Core/Config/Config.h"
#include "Core/Net/netServer.h"
#include "Core/Engine/engine.h"
#include "Core/Log/logger.h"

namespace {
const int PARAMS_NUM = 2;
}

int main(int argc, const char *argv[]) {
    if (argc != PARAMS_NUM) {
        std::cout << "[Help] ./branchDB configFile" << std::endl;
        return 0;
    }

    if (!Config::Instance().Init(argv[1])) {
        return 0;
    }
    
    std::string logPath = Config::Instance().GetConfig(ConfigItem::LOG_PATH);
    if (!Logger::Instance().Init(logPath)) {
        return 0;
    }
    if (!Logger::Instance().Register(RUNNING_LOG)) {
        return 0;
    }

    std::string ip = Config::Instance().GetConfig(ConfigItem::LISTEN_IP);
    std::string port = Config::Instance().GetConfig(ConfigItem::LISTEN_PORT);
    if (!Net::Server::Instance().Start(ip, std::atoi(port.c_str()))) {
        return 0;
    }

    Engine::Instance().Start(); // is a circle.
    Net::Server::Instance().Stop();
    return 0;
}
