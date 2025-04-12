#pragma once
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace dataStructures
{
template <typename T> class PriorityQueue
{
  public:
    PriorityQueue()
    {
        sz = 0;
        reallocate(4);
    }

    void Push(T item)
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

    const T &Top() const
    {
        if (sz == 0)
        {
            throw std::out_of_range("No items in Priority Queue.");
        }
        return tree[0];
    }

    T Pop()
    {
        if (sz == 0)
        {
            throw std::out_of_range("No items in Priority Queue.");
        }
        T toRet = tree[0];
        tree[0] = std::move(tree[sz - 1]);
        sz--;
        refactor(0);
        return toRet;
    }

    bool Empty() const { return sz == 0; }

    size_t Size() const { return sz; }

  private:
    void refactor(size_t currInd)
    {
        size_t left = currInd * 2 + 1;
        size_t right = currInd * 2 + 2;
        size_t newLargest = currInd;
        if (left < sz && tree[left] > tree[newLargest])
            newLargest = left;
        if (right < sz && tree[right] > tree[newLargest])
            newLargest = right;
        if (newLargest != currInd)
        {
            std::swap(tree[currInd], tree[newLargest]);
            refactor(newLargest);
        }
    }

    void reallocate(size_t newSize)
    {
        std::unique_ptr<T[]> newTree = std::make_unique<T[]>(newSize);
        for (size_t i = 0; i < sz; i++)
        {
            newTree[i] = std::move(tree[i]);
        }
        tree = std::move(newTree);
        maxSz = newSize;
    }

    std::unique_ptr<T[]> tree;
    size_t sz;
    size_t maxSz;
};
} // namespace dataStructures