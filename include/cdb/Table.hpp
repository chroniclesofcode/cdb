#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
#include <ostream>
#include "Types.hpp"

namespace cdb
{

class Table
{
private:
    using IntCol = std::vector<int>;
    using DoubleCol = std::vector<double>;
    using StringCol = std::vector<std::string*>;
    using LongCol = std::vector<int64_t>;

    using ColumnVar = std::variant<IntCol, DoubleCol, StringCol, LongCol>;
public:

    Table();

    Table(std::vector<std::string> _names, std::vector<std::string> _dtypes);
    
    void addEntry(std::string key, Value value);

    Value getEntry(std::string key);

    void printTable(std::ostream &os);

private:
    std::vector<std::string> names;
    std::vector<std::string> dtypes;
    std::vector<ColumnVar> data;
};

}