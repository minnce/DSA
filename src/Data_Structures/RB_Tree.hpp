#pragma once
#include <Data_Structures/Queue.hpp>
#include <memory>

enum Color
{
    RED,
    BLACK
};

namespace mystd
{
template <typename T>

class RBTree
{
  public:
    RBTree(T init) { root = std::make_unique<Node>(init, BLACK); }

    // ~RBTree()
    // {
    //     auto q = queue<Node *>();
    //     q.push(root);
    //     while (!q.empty())
    //     {
    //         auto it = q.front();
    //         q.pop();
    //         if (it->left != nullptr)
    //             q.push(it->left);
    //         if (it->right != nullptr)
    //             q.push(it->right);
    //         delete it;
    //     }
    // }

    bool find(T val)
    {
        auto searcher = root;
        while (searcher != nullptr && searcher->value != val)
        {
            if (searcher->value < val)
            {
                searcher = searcher->left;
            }
            else
            {
                searcher = searcher->right;
            }
        }
        return true;
    }

    void insert(T val)
    {
        auto newNode = std::make_unique<Node>(val, RED);
        auto searcher = root;
        auto par = root;
        while (searcher != nullptr)
        {
            if (val < searcher->value)
            {
                par = searcher;
                searcher = searcher->left;
            }
            else
            {
                par = searcher;
                searcher = searcher->right;
            }
        }
        newNode->parent = par;
        if (val < par->value)
        {
            par->left = newNode;
        }
        else
        {
            par->right = newNode;
        }
        // violation checks
        if (par->color == RED)
            fixInsertViolations(newNode);
    }

  private:
    struct Node
    {
        Color color; // false red, true black
        T value;
        Node *parent;
        Node *left;
        Node *right;

        Node(T val, Color col) : color(col), value(val) {}
    };

    std::unique_ptr<Node> root;

    void fixInsertViolations(Node *toCheck)
    {
        Node *par = toCheck->parent;
        Node *grandparent = par->par;
        Node *uncle;
        if (par->par->right != par)
            uncle = par->par->left;
        else
            uncle = par->par->right;
        if (uncle->color == RED)
        {
            par->color = BLACK;
            uncle->color = BLACK;
            grandparent->color = RED;
            fixInsertViolations(grandparent);
        }
        else
        {
            if (par->right == toCheck)
            {
                leftRotation(par);
            }
            else
            {
                rightRotation(grandparent);
            }
        }
    }

    void leftRotation(Node *x)
    {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotation(Node *x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
};

} // namespace mystd