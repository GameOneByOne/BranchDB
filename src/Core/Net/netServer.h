#include <string>
#include <pthread.h>

namespace Net {
enum class STATUS {
    RUNNING,
    STOP
};

class Server {
public:
    static Server &Instance()
    {
        static Server instance;
        return instance;
    }

    Server(const Server &) = delete;
    Server(Server &&) = delete;

    bool Start(const std::string &ip, int port);
    void Stop();

private:
    Server() = default;
    ~Server() = default;

    static void *StartServer(void *);
    static void *DealMessage(void *);

private:
    int listenFd;
    pthread_t threadFd;
    STATUS status;

};
} // namespace Net