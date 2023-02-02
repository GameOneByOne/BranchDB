#include "dataProcess.h"
#include <vector>

namespace StringProcess {
std::vector<std::string> Split(const std::string &src, const std::string &delim)
{
    int left = 0;
    int right = src.find(delim);
    std::string tmp;
    std::vector<std::string> result;
    while (right != std::string::npos) {
        tmp = src.substr(left, right - left);
        left = right + 1;
        right = src.find(delim, left);
        if (tmp.empty()) {
            continue;
        }
        result.push_back(tmp);
    }

    tmp = src.substr(left);
    if (!tmp.empty()) {
        result.push_back(tmp);
    }
    return result;
}
} // namespace StringProcess