#include "cdb/Database.hpp"

void cdb::Database::run()
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
            std::cin >> table >> key >> value;
            if (engine.tableExists(table))
            {
                engine.addTableEntry(table, key, value);
            }
            else
            {
                std::cout << "Table does not exist!" << std::endl;
            }
            break;
        case Opcode::GetEntry:
            std::cin >> table >> key;
            if (engine.tableExists(table))
            {
                std::cout << "value: " << engine.getTableEntry(table, key) << std::endl;
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