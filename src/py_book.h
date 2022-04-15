#pragma once
#include <memory>
#include <functional>
#include <string>
#include <vector>
#include <stdint.h>

using OrderId        = uint64_t;
using MarkerCallback = std::function<int(int)>;
enum class eSide { BID, ASK };

class PyBook
    : public std::enable_shared_from_this<PyBook>
{
public:
    PyBook(std::string const& a_market, std::string const& a_symbol)
    {
    }
};

using PyBookPtr  = std::shared_ptr<PyBook>;
using PyBookList = std::vector<PyBookPtr>;
