#pragma once
#include <unordered_set>

namespace chronicode
{

class StringPool
{
public:
    const std::string* intern(const std::string& str)
    {
        auto it = pool.find(str);
        if (it != pool.end())
        {
            return &(*it);
        }
        else
        {
            const std::string &added_str = *pool.emplace(str).first;
            return &added_str;
        }
    }
private:
    std::unordered_set<std::string> pool;
};

}