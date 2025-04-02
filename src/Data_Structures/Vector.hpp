#pragma once

#include <iostream>
#include <memory>
#include <optional>

namespace dataStructures
{
template <typename T> class Vector
{
  public:
    Vector() { reallocate(2); }

    std::optional<T> operator[](unsigned int index)
    {
        if (index < 0 || index >= currSize)
        {
            return std::nullopt;
        }
        return data[index];
    }

    void Push_Back(T item)
    {
        if (currSize == capacity)
        {
            reallocate(capacity + capacity / 2);
        }
        data[currSize] = item;
        currSize++;
    }

    std::optional<T> Pop_Back()
    {
        if (currSize == 0)
        {
            // std::cout << "No items in vector\n";
            return std::nullopt;
        }
        T ret = data[currSize - 1];
        currSize--;
        return ret;
    }

    size_t Size() { return currSize; }

    size_t getCapacity() { return capacity; }

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
} // namespace dataStructures