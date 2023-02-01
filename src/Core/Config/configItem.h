#ifndef CONFIGITEM
#define CONFIGITEM

#include <map>
#include <string>

enum class ConfigItem {
    LISTEN_IP,
    LISTEN_PORT
};

const std::map<std::string, ConfigItem> CONFIG_MAP = {
    {"LISTEN_IP", ConfigItem::LISTEN_IP},
    {"LISTEN_PORT", ConfigItem::LISTEN_PORT}
};

#endif
