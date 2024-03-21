#pragma once
#include <iostream>
#include <string>
#include "Opcode.hpp"
#include "Types.hpp"
#include "Engine.hpp"

namespace cdb 
{

class Database
{
public:
    void run();
private:
    inline std::vector<Value> createRow(std::string name);

    Engine engine;
};

}
