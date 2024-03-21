#include "cdb/Table.hpp"

namespace cdb
{
    Table::Table() : Table::Table({"sym", "price", "size"}, {"string", "int", "int"}) {}

    Table::Table(std::vector<std::string> _names, std::vector<std::string> types) : num_entries{0}, names{std::move(_names)}
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
                data.push_back(DecimalCol());
                dtypes.push_back(DataType::DecimalType);
            }
        }
    }

    void Table::addEntry(std::vector<Value> row)
    {
        size_t sz = dtypes.size();
        for (size_t j = 0; j < sz; j++)
        {
            switch (dtypes[j])
            {
                case DataType::IntType:
                    std::get<IntCol>(data[j]).push_back(std::get<int>(row[j]));
                    break;
                case DataType::StringRef:
                    std::get<StringCol>(data[j]).push_back(std::get<const std::string*>(row[j]));
                    break;
                case DataType::LongType:
                    std::get<LongCol>(data[j]).push_back(std::get<int64_t>(row[j]));
                    break;
                case DataType::DecimalType:
                    std::get<DecimalCol>(data[j]).push_back(std::get<double>(row[j]));
                    break;
                default:
                    break;
            }
        }
        ++num_entries;
    }

    std::vector<DataType>& Table::getDTypes(void)
    {
        return dtypes;
    }

    void Table::printTable(std::ostream &os)
    {
        for (auto &name : names)
        {
            os << name << ' ';
        }
        os << '\n';
        for (size_t i = 0; i < num_entries; i++)
        {
            printRow(os, i);
        }
        std::flush(os);
    }

    inline void Table::printRow(std::ostream &os, size_t i)
    {
        size_t sz = dtypes.size();
        for (size_t j = 0; j < sz; j++)
        {
            switch (dtypes[j])
            {
                case DataType::IntType:
                {
                    os << std::get<IntCol>(data[j])[i];
                    break;
                }
                case DataType::StringRef:
                {
                    os << *std::get<StringCol>(data[j])[i];
                    break;
                }
                case DataType::LongType:
                {
                    os << std::get<LongCol>(data[j])[i];
                    break;
                }
                case DataType::DecimalType:
                {
                    os << std::get<DecimalCol>(data[j])[i];
                    break;
                }
                default:
                    break;
            }
            os << ' ';
        }
        os << '\n';
    }
}