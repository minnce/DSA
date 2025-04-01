#pragma once
#include <iostream>
#include <memory>
#include <optional>

namespace dataStructures
{
template <typename T> class Vector
{
  public:
    Vector() { allocateMem(2); }

    void Push_Back(T item)
    {
        if (currSize == capacity)
        {
            allocateMem(capacity + capacity / 2);
        }
        data[currSize] = item;
        currSize++;
    }

    std::optional<T> operator[](unsigned int index)
    {
        if (index >= currSize)
        {
            return std::nullopt;
        }
        return data[index];
    }

    unsigned int Size() { return currSize; }

    unsigned int getCapacity() { return capacity; }

  private:
    void allocateMem(unsigned int newCapacity)
    {
        std::cout << "Allocating memory " << newCapacity << "\n";
        auto newData = std::make_unique<T[]>(newCapacity);
        for (int i = 0; i < capacity; i++)
        {
            newData[i] = data[i];
        }
        data = std::move(newData);
        capacity = newCapacity;
    }

    std::unique_ptr<T[]> data;
    unsigned int currSize = 0;
    unsigned int capacity = 0;
};
} // namespace dataStructures