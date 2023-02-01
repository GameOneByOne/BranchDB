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

    std::string GetConfig(const std::string &key);
    void SetConfig(const std::string &key, const std::string &value);

private:
    Config() = default;
    ~Config() = default;

private:
    std::map<ConfigItem, std::string> configs;
};

#endif // CONFIG
