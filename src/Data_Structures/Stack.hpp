#pragma once

#include <Data_Structures/Vector.hpp>
#include <iostream>
#include <optional>
#include <stdexcept>

namespace dataStructures
{
template <typename T> class Stack
{
  public:
    Stack() { data = Vector<T>(); }

    void Push(T item) { data.Push_Back(item); }

    const T &Pop() { return data.Pop_Back(); }

    T &Top()
    {
        if (data.Size() == 0)
        {
            throw std::out_of_range("No items in stack.");
        }
        return data[0];
    }

    bool Empty() { return data.Size() == 0; }

    size_t Size() { return data.Size(); }

  private:
    Vector<T> data;
};
} // namespace dataStructures