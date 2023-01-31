#include <iostream>
#include "Core/Config/Config.h"

namespace {
const int PARAMS_NUM = 2;
}

int main(int argc, const char *argv[]) {
    if (argc != PARAMS_NUM) {
        std::cout << "[Help] ./branchDB configFile" << std::endl;
        return 0;
    }

    if (!Config::Instance().Init(argv[1])) {
        return 0;
    }

    std::cout << "Hello!" << std::endl;
    return 0;
}
