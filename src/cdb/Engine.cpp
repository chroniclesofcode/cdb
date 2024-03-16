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

void Engine::createTable(std::string name)
{
    tables[name] = Table();
}

void Engine::deleteTable(std::string name)
{
    tables.erase(name);
}

bool Engine::tableExists(std::string name)
{
    if (tables.find(name) == tables.end())
    {
        return false;
    }
    return true;
}

}