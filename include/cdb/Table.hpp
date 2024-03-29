#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
#include <iostream>
#include <ostream>
#include "Types.hpp"

namespace cdb
{

class Table
{
private:
    using IntCol = std::vector<int>;
    using DecimalCol = std::vector<double>;
    using StringCol = std::vector<StringID>;
    using LongCol = std::vector<int64_t>;

    using ColumnVar = std::variant<IntCol, DecimalCol, StringCol, LongCol>;
public:

    Table();

    Table(std::vector<std::string> _names, std::vector<std::string> types);
    
    void addEntry(std::vector<Value> row);

    std::vector<DataType>& getDTypes(void);

    void printTable(std::ostream &os);

private:
    void printRow(std::ostream &os, size_t i);

    size_t num_entries;
    std::vector<std::string> names;
    std::vector<DataType> dtypes;
    std::vector<ColumnVar> data;
};

}