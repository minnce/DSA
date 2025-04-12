#pragma once

#include <Data_Structures/Vector.hpp>
#include <iostream>
#include <optional>
#include <stdexcept>

namespace mystd
{
template <typename T> class stack
{
  public:
    stack() { data = vector<T>(); }

    void push(T item) { data.push_back(item); }

    T pop() { return data.pop_back(); }

    T &top()
    {
        if (data.size() == 0)
        {
            throw std::out_of_range("No items in stack.");
        }
        return data[0];
    }

    bool empty() { return data.size() == 0; }

    size_t size() { return data.size(); }

  private:
    vector<T> data;
};
} // namespace mystd