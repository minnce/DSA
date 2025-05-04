#pragma once

#include <iostream>
#include <memory>
#include <optional>

namespace mystd
{
template <typename T> class array
{
  public:
    array(const size_t &initSize)
    {
        Size = initSize;
        data = std::make_unique<T[]>(initSize);
    }

    T &operator[](const size_t &index)
    {
        if (index >= Size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T &operator[](const size_t &index) const
    {
        if (index >= Size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

  private:
    std::unique_ptr<T[]> data;
    size_t Size;
};
} // namespace mystd