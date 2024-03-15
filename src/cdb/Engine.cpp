#include "cdb/Engine.hpp"
#include <iostream>

namespace cdb 
{

void Engine::addTableEntry(std::string name, std::string key, int32_t value)
{
    tables[name].addEntry(key, value);
}

int32_t Engine::getTableEntry(std::string name, std::string key)
{
    return tables[name].getEntry(key);
}

bool Engine::tableExists(std::string name)
{
    if (tables.find(name) == tables.end())
    {
        std::cout << "Table does not exist" << std::endl;
        return false;
    }
    return true;
}

}