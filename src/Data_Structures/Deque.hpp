#pragma once
#include <Data_Structures/Array.hpp>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace mystd
{
template <typename T>
class deque
{
  public:
    deque() : buffer(4)
    {
        head = 0;
        tail = 0;
        maxSize = 4;
        currSize = 0;
    }

    T &front()
    {
        if (currSize == 0)
        {
            throw std::out_of_range("No items in Deque.");
        }
        return buffer[tail];
    }

    T &back()
    {
        if (currSize == 0)
        {
            throw std::out_of_range("No items in Deque.");
        }
        return buffer[head];
    }

    void push_back(T item)
    {
        if (currSize == maxSize)
        {
            resize();
        }
        if (currSize == 0)
        {
            buffer[head] = item;
        }
        else
        {
            head = (head + 1) % maxSize;
            buffer[head] = item;
        }
        currSize++;
    }

    void push_front(T item)
    {
        if (currSize == maxSize)
        {
            resize();
        }
        if (currSize == 0)
        {
            buffer[tail] = item;
        }
        else
        {
            tail = (tail - 1 + maxSize) % maxSize;
            buffer[tail] = item;
        }
        currSize++;
    }

    const T &pop_front()
    {
        if (currSize == 0)
        {
            throw std::out_of_range("No items to get.");
        }
        T &toRet = buffer[tail];
        tail = (tail + 1) % maxSize;
        currSize--;
        return toRet;
    }

    const T &pop_back()
    {
        if (currSize == 0)
        {
            throw std::out_of_range("No items to get.");
        }
        T &toRet = buffer[head];
        head = (head + maxSize - 1) % maxSize;
        currSize--;
        return toRet;
    }

    void dump_buffer()
    {
        int dumpTail = tail;
        for (int i = 0; i < currSize; i++)
        {
            std::cout << buffer[dumpTail] << " ";
            dumpTail = (dumpTail + 1) % maxSize;
        }
        std::cout << "\n";
    }

    void dump_buffer_raw()
    {
        for (int i = 0; i < maxSize; i++)
        {
            std::cout << buffer[i] << " ";
        }
        std::cout << "\n";
    }

    bool empty() const { return currSize == 0; }

    size_t size() const { return currSize; }

    const T &operator[](size_t index) const
    {
        if (index < 0 || index >= currSize)
        {
            throw std::out_of_range("Index not in range.");
        }
        return buffer[(tail + index) % maxSize];
    }

  private:
    size_t head;
    size_t tail;
    size_t currSize;
    size_t maxSize;
    array<T> buffer;

    void resize()
    {
        auto newBuffer = array<T>(maxSize * 2);
        for (int i = 0; i < currSize; i++)
        {
            newBuffer[i] = buffer[tail];
            tail = (tail + 1) % maxSize;
        }
        buffer = std::move(newBuffer);
        tail = 0;
        head = maxSize - 1;
        maxSize *= 2;
    }
};
} // namespace mystd