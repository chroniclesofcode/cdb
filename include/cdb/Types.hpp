#pragma once
#include <variant>

namespace cdb
{

    using Value = std::variant<int, double, std::string*, int64_t>;

}