#pragma once
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

namespace dataStructures
{
class Ringbuffer
{
  public:
    Ringbuffer(unsigned int initSize)
    {
        buffer = new int[initSize];
        head = 0;
        tail = 0;
        maxSize = initSize;
        currSize = 0;
    }

    ~Ringbuffer() { delete[] buffer; }

    void add_item(unsigned int item)
    {
        if (currSize == maxSize)
        {
            std::cout << "Resizing\n";
            resize();
        }
        buffer[head] = item;
        head = (head + 1) % maxSize;
        currSize++;
    }

    std::optional<unsigned int> get_item()
    {
        if (currSize == 0)
        {
            return std::nullopt;
        }
        int toRet = buffer[tail];
        tail = (tail + 1) % maxSize;
        currSize--;
        return toRet;
    }

    void dump_buffer()
    {
        for (int i = 0; i < maxSize; i++)
        {
            std::cout << buffer[i] << " ";
        }
        std::cout << "\n";
    }

  private:
    unsigned int head;
    unsigned int tail;
    int *buffer;
    unsigned int currSize;
    unsigned int maxSize;

    void resize()
    {
        int *newBuffer = new int[maxSize * 2];
        for (int i = 0; i < currSize; i++)
        {
            newBuffer[i] = buffer[tail];
            tail = (tail + 1) % maxSize;
        }
        delete[] buffer;
        buffer = newBuffer;
        tail = 0;
        head = maxSize;
        maxSize *= 2;
    }
};
} // namespace dataStructures