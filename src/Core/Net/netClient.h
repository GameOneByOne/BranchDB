#include <string>

namespace Net {
class Client {
public:
    static Client &Instance()
    {
        static Client instance;
        return instance;
    }

    Client(const Client &) = delete;
    Client(Client &&) = delete;

    bool SendTo(const std::string &ip, int port, const std::string &data);

private:
    Client() = default;
    ~Client() = default;
};
} // namespace Net