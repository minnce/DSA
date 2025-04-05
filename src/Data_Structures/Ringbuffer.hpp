#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

namespace dataStructures
{
template <typename T> class Ringbuffer
{
  public:
    Ringbuffer(unsigned int initSize)
    {
        buffer = std::make_unique<T[]>(initSize);
        head = 0;
        tail = 0;
        maxSize = initSize;
        currSize = 0;
    }

    void Add_Item(T item)
    {
        if (currSize == maxSize)
        {
            resize();
        }
        buffer[head] = item;
        head = (head + 1) % maxSize;
        currSize++;
    }

    const T &Get_Item()
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

    void Dump_Buffer()
    {
        int dumpTail = tail;
        for (int i = 0; i < maxSize; i++)
        {
            std::cout << buffer[dumpTail] << " ";
            dumpTail = (dumpTail + 1) % maxSize;
        }
        std::cout << "\n";
    }

    const T Get_Head() const { return head; }

    const T Get_Tail() const { return tail; }

    const T Get_Size() const { return currSize; }

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
} // namespace dataStructures