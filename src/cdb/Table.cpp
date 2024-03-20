#include "cdb/Table.hpp"

namespace cdb
{
    Table::Table() : Table::Table({"sym", "price", "size"}, {"string", "int", "int"}) {}

    Table::Table(std::vector<std::string> _names, std::vector<std::string> _dtypes) : names{std::move(_names)}, dtypes{std::move(_dtypes)}
    {
        for (size_t i = 0; i < dtypes.size(); i++) 
        {
            if (dtypes[i] == "int")
            {
                data.push_back(IntCol());
            }
            else if (dtypes[i] == "string")
            {
                data.push_back(StringCol());
            }
            else if (dtypes[i] == "long")
            {
                data.push_back(LongCol());
            }
            else if (dtypes[i] == "double")
            {
                data.push_back(DoubleCol());
            }
        }
    }

    void Table::addEntry(std::string key, Value value)
    {
        // data[key] = value;
    }

    Value Table::getEntry(std::string key)
    {
        // return data[key];
        return 0;
    }

    void Table::printTable(std::ostream &os)
    {
        os << "Hello world!\n";
    }
}