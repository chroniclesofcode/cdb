#pragma once
#include <string>
#include <ostream>
#include "Table.hpp"
#include "chronicode/hashmap.hpp"

namespace cdb
{

class Engine
{
public:

    void addTableEntry(std::string name, std::string key, Value value);    

    Value getTableEntry(std::string name, std::string key);

    void createTable(std::string name);

    void deleteTable(std::string name);

    void printTable(std::string name, std::ostream &os);

    bool tableExists(std::string name);

private:
    chronicode::hashmap<std::string, Table> tables;
};

}