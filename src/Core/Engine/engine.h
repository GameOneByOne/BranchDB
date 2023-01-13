

class Engine {
public:
    static Engine &Instance()
    {
        static Engine engine;
        return engine;
    }

    Engine(const Engine &) = delete;
    Engine(Engine &&) = delete;

    bool Init();
    bool DeInit();

private:
    Engine() = default;
    ~Engine() = default;

    bool Add();
    bool Remove();
    bool Update();
    bool Query();
};

