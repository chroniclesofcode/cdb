#include "cdb/Table.hpp"

namespace cdb
{
    Table::Table() : Table::Table({"sym", "price", "size"}, {"string", "int", "int"}) {}

    Table::Table(std::vector<std::string> _columns, std::vector<std::string> _dtypes) : columns{std::move(_columns)}, dtypes{std::move(_dtypes)} {}

    void Table::addEntry(std::string key, int32_t value)
    {
        data[key] = value;
    }

    int32_t Table::getEntry(std::string key)
    {
        return data[key];
    }
}