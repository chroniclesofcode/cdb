#pragma once
#include <variant>

namespace cdb
{
    using StringID = const std::string*;
    using Value = std::variant<int, double, StringID, int64_t>;

    enum class DataType
    {
        IntType,
        DecimalType,
        StringRef,
        LongType
    };

}