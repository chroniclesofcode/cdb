#include "cdb/Engine.hpp"
#include <iostream>

namespace cdb 
{

void Engine::addTableEntry(std::string name, std::string key, Value value)
{
    tables.get(name).addEntry(key, value);
}

Value Engine::getTableEntry(std::string name, std::string key)
{
    return tables.get(name).getEntry(key);
}

void Engine::createTable(std::string name)
{
    tables.set(name, Table({"sym", "price", "size"}, {"string", "int", "int"}));
}

void Engine::deleteTable(std::string name)
{
    tables.erase(name);
}

void Engine::printTable(std::string name, std::ostream &os)
{
    tables.get(name).printTable(os);
}

bool Engine::tableExists(std::string name)
{
    return tables.exists(name);
}

}