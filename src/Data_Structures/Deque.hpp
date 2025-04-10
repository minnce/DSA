#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

namespace dataStructures
{
template <typename T> class Deque
{
  public:
    Deque()
    {
        buffer = std::make_unique<T[]>(4);
        head = 0;
        tail = 0;
        maxSize = 4;
        currSize = 0;
    }

    T &Front()
    {
        if (currSize == 0)
        {
            throw std::out_of_range("No items in Deque.");
        }
        return buffer[tail];
    }

    T &Back()
    {
        if (currSize == 0)
        {
            throw std::out_of_range("No items in Deque.");
        }
        return buffer[head];
    }

    void Push_Back(T item)
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

    void Push_Front(T item)
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

    const T &Pop_Front()
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

    const T &Pop_Back()
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

    void Dump_Buffer()
    {
        int dumpTail = tail;
        for (int i = 0; i < currSize; i++)
        {
            std::cout << buffer[dumpTail] << " ";
            dumpTail = (dumpTail + 1) % maxSize;
        }
        std::cout << "\n";
    }

    void Dump_Buffer_Raw()
    {
        for (int i = 0; i < maxSize; i++)
        {
            std::cout << buffer[i] << " ";
        }
        std::cout << "\n";
    }

    const bool Empty() const { return currSize == 0; }

    const size_t Size() const { return currSize; }

    const T &operator[](size_t index) const
    {
        if (index < 0 || index >= currSize)
        {
            throw std::out_of_range("Index not in range.");
        }
        return buffer[(tail + index) % maxSize];
    }

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
        head = maxSize - 1;
        maxSize *= 2;
    }
};
} // namespace dataStructures