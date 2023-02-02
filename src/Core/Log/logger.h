
#ifndef LOGGER
#define LOGGER

#include <map>
#include <fstream>

#define RUNNING_LOG "branchDb"
#define INFOLOG(fmt, ...) Logger::Instance().WriteLog(RUNNING_LOG, fmt, ##__VA_ARGS__)
#define ERRORLOG(fmt, ...) Logger::Instance().WriteLog(RUNNING_LOG, fmt, ##__VA_ARGS__)

namespace Log {
enum class STATUS {
    INITED,
    UNINITED
};

struct Hanlder {
    std::string filePath;
    std::fstream stream;
};
}

class Logger {
public:
    static Logger &Instance()
    {
        static Logger instance;
        return instance;
    }

    Logger(const Logger &) = delete;
    Logger(Logger &&) = delete;

    bool Init(const std::string &path);
    void UnInit();
    bool Register(const std::string &name);
    void WriteLog(const std::string &name, const std::string &fmt, ...);

private:
    Logger();
    ~Logger() = default;

private:
    Log::STATUS status;
    std::string logPath;
    std::map<std::string, Log::Hanlder> logMap;
};

#endif // LOGGER