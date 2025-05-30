#pragma once
#include <Data_Structures/Array.hpp>
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace mystd
{
template <typename T> class priority_queue
{
  public:
    priority_queue() : tree(4)
    {
        sz = 0;
        maxSz = 4;
    }

    void push(T item)
    {
        if (sz == maxSz)
        {
            reallocate(maxSz + maxSz / 2);
        }
        tree[sz] = item;
        size_t currInd = sz;
        while (currInd != 0 && tree[(currInd - 1) / 2] < tree[currInd])
        {
            std::swap(tree[currInd], tree[(currInd - 1) / 2]);
            currInd = (currInd - 1) / 2;
        }
        sz++;
    }

    const T &top() const
    {
        if (sz == 0)
        {
            throw std::out_of_range("No items in Priority Queue.");
        }
        return tree[0];
    }

    T pop()
    {
        if (sz == 0)
        {
            throw std::out_of_range("No items in Priority Queue.");
        }
        T toRet = tree[0];
        tree[0] = std::move(tree[sz - 1]);
        sz--;
        heapify(0);
        return toRet;
    }

    bool empty() const { return sz == 0; }

    size_t size() const { return sz; }

  private:
    void heapify(size_t currInd)
    {
        const size_t left = currInd * 2 + 1;
        const size_t right = currInd * 2 + 2;
        size_t newLargest = currInd;
        if (left < sz && tree[left] > tree[newLargest])
            newLargest = left;
        if (right < sz && tree[right] > tree[newLargest])
            newLargest = right;
        if (newLargest != currInd)
        {
            std::swap(tree[currInd], tree[newLargest]);
            heapify(newLargest);
        }
    }

    void reallocate(size_t newSize)
    {
        array<T> newTree = array<T>(newSize);
        for (size_t i = 0; i < sz; i++)
        {
            newTree[i] = std::move(tree[i]);
        }
        tree = std::move(newTree);
        maxSz = newSize;
    }

    array<T> tree;
    size_t sz;
    size_t maxSz;
};
} // namespace mystd