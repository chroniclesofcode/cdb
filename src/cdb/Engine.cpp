#include "cdb/Engine.hpp"
#include <iostream>

namespace cdb 
{

void Engine::addTableEntry(std::string name, std::string key, Value value)
{
    tables[name].addEntry(key, value);
}

int32_t Engine::getTableEntry(std::string name, std::string key)
{
    return tables[name].getEntry(key);
}

void Engine::createTable(std::string name)
{
    tables[name] = Table({"sym", "price", "size"}, {"string", "int", "int"});
}

void Engine::deleteTable(std::string name)
{
    tables.erase(name);
}

void Engine::printTable(std::string name, std::ostream &os)
{
    tables[name].printTable(os);
}

bool Engine::tableExists(std::string name)
{
    return tables.find(name) != tables.end();
}

}