#pragma once
#include <variant>

namespace cdb
{

    using Value = std::variant<int, double, const std::string*, int64_t>;

    enum class DataType
    {
        IntType,
        DecimalType,
        StringRef,
        LongType
    };

}