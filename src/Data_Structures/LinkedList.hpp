#pragma once
#include <iostream>
#include <memory>
#include <vector>

namespace mystd
{
template <typename T> class linked_list
{
  public:
    linked_list()
    {
        head = std::make_shared<Node>(T{});
        tail = std::make_shared<Node>(T{});
        head->next = tail;
        tail->prev = head;
    }

    void add_item(T item)
    {
        auto toAdd = std::make_shared<Node>(item);
        auto temp = tail->prev.lock();
        temp->next = toAdd;
        toAdd->prev = temp;
        toAdd->next = tail;
        tail->prev = toAdd;
    }

    void print_list()
    {
        auto printer = head->next;
        while (printer != tail)
        {
            std::cout << printer->value << " ";
            printer = printer->next;
        }
        // std::cout << "print done!\n";
    }

    std::vector<T> convert_to_vector()
    {
        std::vector<T> convertedList;
        auto printer = head->next;
        while (printer != tail)
        {
            convertedList.push_back(printer->value);
            printer = printer->next;
        }
        return convertedList;
    }

  private:
    struct Node
    {
        T value;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;

        Node(const T &val) { value = val; }
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
};
} // namespace mystd