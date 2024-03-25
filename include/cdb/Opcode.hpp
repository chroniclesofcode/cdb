#pragma once
#include <string>

namespace cdb
{

enum class Opcode
{
    AddEntry = 'A',
    CreateTable = 'C', 
    DeleteTable = 'D',
    PrintTable = 'P',
    QuitCommand = 'Q',
    NoCommand = 'N'
};

inline Opcode string_to_opcode(std::string s) {
    if (s == "add") return Opcode::AddEntry;
    if (s == "printtable") return Opcode::PrintTable;
    if (s == "createtable") return Opcode::CreateTable;
    if (s == "deletetable") return Opcode::DeleteTable;
    if (s == "quit") return Opcode::QuitCommand;
    return Opcode::NoCommand;
}

}