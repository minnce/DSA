#pragma once

#include <iostream>
#include <memory>
#include <optional>

namespace dataStructures {
template<typename T>
class Array {
public:
    Array(size_t initSize) {
        Size = initSize;
        data = std::make_unique<T[]>(initSize);
    }

    T& operator[](size_t index) {
        if (index >= Size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

private:
    std::unique_ptr<T[]> data;
    size_t Size;
};
}