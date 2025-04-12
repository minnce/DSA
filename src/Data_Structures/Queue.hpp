#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

namespace mystd
{
template <typename T> class queue
{
  public:
    queue()
    {
        buffer = std::make_unique<T[]>(4);
        head = 0;
        tail = 0;
        maxSize = 4;
        currSize = 0;
    }

    T &front()
    {
        if (currSize == 0)
        {
            throw std::out_of_range("No items in queue.");
        }
        return buffer[tail];
    }

    T &back()
    {
        if (currSize == 0)
        {
            throw std::out_of_range("No items in queue.");
        }
        return buffer[(head + maxSize - 1) % maxSize];
    }

    void push(T item)
    {
        if (currSize == maxSize)
        {
            resize();
        }
        buffer[head] = item;
        head = (head + 1) % maxSize;
        currSize++;
    }

    const T &pop()
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

    const bool empty() const { return currSize == 0; }

    const size_t size() const { return currSize; }

  private:
    unsigned int head;
    unsigned int tail;
    std::unique_ptr<T[]> buffer;
    unsigned int currSize;
    unsigned int maxSize;

    void resize()
    {
        auto newBuffer = std::make_unique<T[]>(maxSize * 2);
        for (int i = 0; i < currSize; i++)
        {
            newBuffer[i] = buffer[tail];
            tail = (tail + 1) % maxSize;
        }
        buffer = std::move(newBuffer);
        tail = 0;
        head = maxSize;
        maxSize *= 2;
    }
};
} // namespace mystd