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
        sz = initSize;
    }

    ~Ringbuffer() { delete[] buffer; }

    void add_item(unsigned int item)
    {
        buffer[head] = item;
        head = (head + 1) % sz;
        sz++;
    }

    std::optional<unsigned int> get_item()
    {
        if (tail == head)
        {
            std::cout << "No items in ringbuffer\n";
            return std::nullopt;
        }
        unsigned int toRet = buffer[tail];
        tail = (tail + 1) % sz;
        sz--;
        return toRet;
    }

  private:
    unsigned int head;
    unsigned int tail;
    int *buffer;
    unsigned int sz;

    void resize() {}
};
} // namespace dataStructures