#pragma once
#include <unordered_map>

namespace chronicode
{

template<typename Key, typename Val>
class hashmap
{
public:
    Val& get(Key k)
    {
        return data[k];
    }

    void set(Key k, Val v)
    {
        data[k] = v;
    }

    void erase(Key k)
    {
        data.erase(k);
    }

    inline bool exists(Key k)
    {
        return data.find(k) == data.end();
    }
private:
    std::unordered_map<Key, Val> data;
};

}