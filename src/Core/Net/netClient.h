#ifndef NET_CLIENT
#define NET_CLIENT
#include <string>

namespace Net {
class Client {
public:
    Client();
    Client(Client &&rhs);
    ~Client();

    bool ConnectTo(const std::string &ip, int port);
    bool Send(const std::string &sendData);
    bool Recv(const std::string &sendData);
    void Shutdown();

private:
    bool ReConnectTo();

private:
    std::string remoteIp;
    int remotePort;
    int remoteFd;
};
} // namespace Net
#endif // NET_CLIENT
