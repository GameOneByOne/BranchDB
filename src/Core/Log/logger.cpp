#include "logger.h"
#include <unistd.h>
#include <stdarg.h>
#include <time.h>
#include <stdio.h>

namespace {
const int MAX_LOG_LENGTH = 1024;
}

Logger::Logger() : status(Log::STATUS::UNINITED)
{}

bool Logger::Init(const std::string &path)
{
    if (path.empty() || (access(path.c_str(), 0) == -1)) {
        return false;
    }
    if (status == Log::STATUS::INITED) {
        return false;
    }

    logPath = path;
    status = Log::STATUS::INITED;
    return true;
}

void Logger::UnInit()
{
    logPath = "";
    status = Log::STATUS::UNINITED;
    for (auto &iter : logMap) {
        iter.second.stream.close();
    }
    logMap.clear();

    return;
}

bool Logger::Register(const std::string &name)
{
    if (name.empty() || (status != Log::STATUS::INITED)) {
        return false;
    }

    auto &handler = logMap[name];
    handler.filePath = logPath + "/" + name + ".log";
    handler.stream.open(handler.filePath, std::ios::out | std::ios::app);
    if (!handler.stream.is_open()) {
        logMap.erase(name);
        return false;
    }

    return true;
}

void Logger::WriteLog(const std::string &name, const std::string &fmt, ...)
{
    const auto &handler = logMap.find(name);
    if (handler == logMap.end()) {
        return;
    }

    va_list args;
    va_start(args, fmt);
    char buffer[MAX_LOG_LENGTH] = { 0 };
    if (vsnprintf(buffer, MAX_LOG_LENGTH - 1, fmt.c_str(), args) == -1) {
        return;
    }
    va_end(args);

    handler->second.stream << buffer << std::endl;
    return;
}
