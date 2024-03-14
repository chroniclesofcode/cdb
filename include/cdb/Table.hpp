#include <unordered_map>
#include <string>

namespace cdb
{

class Table
{
public:
    
    void addEntry(std::string key, int32_t value);

    int32_t getEntry(std::string key);

private:
    std::unordered_map<std::string, int32_t> data;
};

}