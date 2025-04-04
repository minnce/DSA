#pragma once
#include <Data_Structures/Ringbuffer.hpp>
#include <stdexcept>

namespace dataStructures
{
template <typename T> class Queue
{
  public:
    Queue() : data(5) {}

    T &Front()
    {
        if (data.get_size() == 0)
        {
            throw std::out_of_range("No items in queue.");
        }
        return data[data.get_head()];
    }

    T &Back()
    {
        if (data.get_size() == 0)
        {
            throw std::out_of_range("No items in queue.");
        }
        return data[data.get_tail()];
    }

    const bool Empty() const { return data.get_size() == 0; }

    const size_t Size() const { return data.get_size(); }

    void Push(T item) { data.add_item(item); }

    const T &Pop() { return data.get_item(); }

  private:
    Ringbuffer<T> data;
};
} // namespace dataStructures