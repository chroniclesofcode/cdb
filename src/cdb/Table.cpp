#include "cdb/Table.hpp"

namespace cdb
{
    void Table::addEntry(std::string key, int32_t value)
    {
        data[key] = value;
    }

    int32_t Table::getEntry(std::string key)
    {
        return data[key];
    }
}