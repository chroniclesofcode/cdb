#include <unordered_map>
#include <string>
#include "Table.hpp"

namespace cdb
{

class Engine
{
public:

    void addTableEntry(std::string name, std::string key, int32_t value);    

    int32_t getTableEntry(std::string name, std::string key);

    bool tableExists(std::string name);

private:
    std::unordered_map<std::string, Table> tables;
};

}