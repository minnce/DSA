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
    }

    unsigned int add_item(unsigned int item) {}

    std::optional<unsigned int> get_item()
    {
        if (tail == head)
        {
            std::cout << "No items in ringbuffer\n";
            return std::nullopt;
        }
        else
        {
        }
    }

  private:
    unsigned int head;
    unsigned int tail;
    int *buffer;

    void resize() {}
};
} // namespace dataStructures