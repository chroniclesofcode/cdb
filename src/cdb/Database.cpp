#include "cdb/Database.hpp"

namespace cdb
{

inline std::vector<Value> Database::createRow(std::string name)
{
    auto& dtypes = engine.getDTypes(name);
    std::vector<Value> row;
    for (DataType d : dtypes)
    {
        switch (d)
        {
            case DataType::IntType:
            {
                int eInt; 
                std::cin >> eInt;
                row.push_back(eInt);
                break;
            }
            case DataType::StringRef:
            {
                std::string eStr; 
                std::cin >> eStr;
                row.push_back(engine.internString(std::move(eStr)));
                break;
            }
            case DataType::LongType:
            {
                int64_t eLong;
                std::cin >> eLong;
                row.push_back(eLong);
                break;
            }
            case DataType::DecimalType:
            {
                double eDouble;
                std::cin >> eDouble;
                row.push_back(eDouble);
                break;
            }
            default:
                row.push_back(0);
                break;
        }
    }
    return row;
}

void Database::run()
{
    while (1)
    {
        std::string opc;
        std::cin >> opc;
        Opcode cmd = string_to_opcode(std::move(opc));

        std::string table, key;
        Value value;
        switch (cmd)
        {
        case Opcode::AddEntry:
            // Obtain data types and insert
            std::cin >> table;
            if (engine.tableExists(table))
            {
                engine.addTableEntry(std::move(table), createRow(std::move(table)));
            }
            else
            {
                std::cout << "Table does not exist!" << std::endl;
            }
            break;
        case Opcode::CreateTable:
            std::cin >> table;
            if (engine.tableExists(table))
            {
                std::cout << "Table already exists!" << std::endl;
            }
            else
            {
                engine.createTable(table);
            }
            break;
        case Opcode::DeleteTable:
            std::cin >> table;
            if (engine.tableExists(table))
            {
                engine.deleteTable(table);
            }
            break;
        case Opcode::PrintTable:
            std::cin >> table;
            if (engine.tableExists(table))
            {
                engine.printTable(table, std::cout);
            }
            else
            {
                std::cout << "Table does not exist!" << std::endl;
            }
            break;
        default:
            std::cout << "Command does not exist." << std::endl;
            break;
        }
    }
}

}