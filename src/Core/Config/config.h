#ifndef CONFIG
#define CONFIG

#include "configItem.h"
#include <map>
#include <string>

class Config {
public:
    static Config &Instance()
    {
        static Config instance;
        return instance;
    }

    Config(const Config &) = delete;
    Config(Config &&) = delete;

    bool Init(const std::string &configFile);

    std::string GetConfig(ConfigItem configItem);
    void SetConfig(ConfigItem configItem, const std::string &value);

private:
    Config() = default;
    ~Config() = default;

private:
    std::map<ConfigItem, std::string> configs;
};

#endif // CONFIG
