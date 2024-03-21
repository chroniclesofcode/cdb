#include "cdb/Table.hpp"

namespace cdb
{
    Table::Table() : Table::Table({"sym", "price", "size"}, {"string", "int", "int"}) {}

    Table::Table(std::vector<std::string> _names, std::vector<std::string> types) : names{std::move(_names)}
    {
        for (size_t i = 0; i < types.size(); i++) 
        {
            if (types[i] == "int")
            {
                data.push_back(IntCol());
                dtypes.push_back(DataType::IntType);
            }
            else if (types[i] == "string")
            {
                data.push_back(StringCol());
                dtypes.push_back(DataType::StringRef);
            }
            else if (types[i] == "long")
            {
                data.push_back(LongCol());
                dtypes.push_back(DataType::LongType);
            }
            else if (types[i] == "double")
            {
                data.push_back(DoubleCol());
                dtypes.push_back(DataType::DecimalType);
            }
        }
    }

    void Table::addEntry(std::vector<Value> row)
    {
        std::cout << "Adding!" << std::endl;
    }

    std::vector<DataType>& Table::getDTypes(void)
    {
        return dtypes;
    }

    void Table::printTable(std::ostream &os)
    {
        os << "Hello world!\n";
    }
}