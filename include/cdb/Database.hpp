#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "Opcode.hpp"
#include "Engine.hpp"

namespace cdb 
{

class Database
{
public:
    void run();
private:
    Engine engine;
};

}
