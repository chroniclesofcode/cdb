#pragma once

namespace cdb
{

enum class Opcode
{
    AddEntry = 'A',
    GetEntry = 'G',
    CreateTable = 'C', 
    DeleteTable = 'D',
    NoCommand = 'N'
};

inline Opcode string_to_opcode(std::string s) {
    if (s == "add") return Opcode::AddEntry;
    if (s == "get") return Opcode::GetEntry;
    if (s == "createtable") return Opcode::CreateTable;
    if (s == "deletetable") return Opcode::DeleteTable;
    return Opcode::NoCommand;
}

}