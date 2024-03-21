#include "cdb/Engine.hpp"
#include <iostream>

namespace cdb 
{

void Engine::addTableEntry(std::string name, std::vector<Value> row)
{
    tables.get(name).addEntry(std::move(row));
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

const std::string* Engine::internString(std::string str)
{
    return s_pool.intern(std::move(str));
}

std::vector<DataType>& Engine::getDTypes(std::string name)
{
    return tables.get(name).getDTypes();
}

}