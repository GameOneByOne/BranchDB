#include "config.h"
#include <vector>
#include <fstream>
#include "Core/Log/logger.h"
#include "Utils/dataProcess.h"

namespace {
// Show the config which user should dedicate in config file.
const std::string SERVER_IP = "serverIp";
const std::string SERVER_PORT = "serverPort";
}

bool Config::Init(const std::string &configFile)
{
    std::ifstream configStream(configFile, std::ios::in);
    if (!configStream.is_open()) {
        ERRORLOG("Config file open failed. [filePath=%s][error=%d]", configFile.c_str(), errno);
        return false;
    }

    std::string line;
    while (std::getline(configStream, line)) {
        std::vector<std::string> keyAndValue = StringProcess::Split(line, "=");
        if (keyAndValue.size() != 2) {
            continue;
        }
        const auto &item = CONFIG_MAP.find(keyAndValue[0]);
        if (item != CONFIG_MAP.end()) {
            configs[item->second] = keyAndValue[1]; 
        }
    }

    return true;
}

std::string Config::GetConfig(ConfigItem configItem)
{
    return configs[configItem];
}

void Config::SetConfig(const std::string &key, const std::string &value)
{
    return;
}

