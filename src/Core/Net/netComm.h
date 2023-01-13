#include <sys/socket.h>

namespace Net {
enum class Status {
    CONNECTED,
    UNCONNECTED
};
} // namespace Net

class NetComm {
public:
    static NetComm &Instance()
    {
        static NetComm instance;
        return instance;
    }

    NetComm(const NetComm &) = delete;
    NetComm(NetComm &&) = delete;
    Net::Status GetStatus();

private:
    NetComm() = default;
    ~NetComm() = default;
};