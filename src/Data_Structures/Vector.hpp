#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

namespace mystd
{
template <typename T> class vector
{
  public:
    vector() { reallocate(2); }

    T &operator[](unsigned int index)
    {
        if (index < 0 || index >= currSize)
        {
            throw std::out_of_range("Index out of bounds.");
        }
        return data[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index < 0 || index >= currSize)
        {
            throw std::out_of_range("Index out of bounds.");
        }
        return data[index];
    }

    void push_back(T item)
    {
        if (currSize == capacity)
        {
            reallocate(capacity + capacity / 2);
        }
        data[currSize] = item;
        currSize++;
    }

    T pop_back()
    {
        if (currSize == 0)
        {
            // std::cout << "No items in vector\n";
            throw std::out_of_range("No items.");
        }
        T ret = data[currSize - 1];
        currSize--;
        return ret;
    }

    size_t size() { return currSize; }

  private:
    void reallocate(size_t newSize)
    {
        auto newData = std::make_unique<T[]>(newSize);
        for (size_t i = 0; i < currSize; i++)
        {
            newData[i] = std::move(data[i]);
        }
        data = std::move(newData);
        capacity = newSize;
    }

    std::unique_ptr<T[]> data;
    size_t currSize = 0;
    size_t capacity = 0;
};
} // namespace mystd