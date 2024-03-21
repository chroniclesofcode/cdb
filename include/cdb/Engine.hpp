#pragma once
#include <string>
#include <ostream>
#include "Table.hpp"
#include "chronicode/Hashmap.hpp"
#include "chronicode/StringPool.hpp"

namespace cdb
{

class Engine
{
public:

    void addTableEntry(std::string name, std::vector<Value> row);    

    void createTable(std::string name);

    void deleteTable(std::string name);

    void printTable(std::string name, std::ostream &os);

    bool tableExists(std::string name);

    const std::string* internString(std::string str);

    std::vector<DataType>& getDTypes(std::string name);

private:
    chronicode::StringPool s_pool;    
    chronicode::Hashmap<std::string, Table> tables;
};

}