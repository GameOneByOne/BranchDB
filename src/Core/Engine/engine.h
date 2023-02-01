#include <pthread.h>

class Engine {
public:
    static Engine &Instance()
    {
        static Engine engine;
        return engine;
    }

    Engine(const Engine &) = delete;
    Engine(Engine &&) = delete;

    bool Start();
    bool Stop();

private:
    Engine() = default;
    ~Engine() = default;

    bool Add();
    bool Delete();
    bool Update();
    bool Query();
};

