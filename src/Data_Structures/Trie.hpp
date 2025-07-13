#include <memory>
#include <stack>
#include <vector>

namespace mystd
{
class Trie
{
  public:
    Trie() : root(std::make_shared<Node>(char())) {}

    bool find(const std::string &toFind) const
    {
        auto currNode = root;
        for (int i = 0; i < toFind.size(); i++)
        {
            auto e = toFind[i];
            bool found = false;
            for (const auto &child : currNode->children)
            {
                if (child->value == e)
                {
                    found = true;
                    currNode = child;
                    break;
                }
            }
            if (!found || (i == toFind.size() - 1 && found && !currNode->isLast))
                return false;
        }
        return true;
    }

    void add_item(const std::string &toAdd)
    {
        auto currNode = root;

        for (int i = 0; i < toAdd.size(); i++)
        {
            auto e = toAdd[i];
            bool found = false;
            for (const auto &child : currNode->children)
            {
                if (child->value == e)
                {
                    found = true;
                    currNode = child;
                    break;
                }
            }
            if (!found)
            {
                auto newNode = std::make_shared<Node>(e);
                newNode->parent = currNode;
                currNode->children.push_back(newNode);
                currNode = newNode;
            }
            if (i == toAdd.size() - 1)
                currNode->isLast = true;
        }
    }

    bool delete_item(const std::string &toDelete)
    {
        if (!find(toDelete) || toDelete.size() == 0)
            return false;
        std::stack<std::shared_ptr<Node>> removes;
        auto currNode = root;
        for (int i = 0; i < toDelete.size(); i++)
        {
            for (const auto &child : currNode->children)
            {
                if (child->value == toDelete[i])
                {
                    removes.push(child);
                    currNode = child;
                }
            }
        }
        removes.top()->isLast = false;
        while (!removes.empty())
        {
            auto currNode = removes.top();
            removes.pop();
            if (currNode->children.size() > 0 || currNode->isLast == true)
            {
                break;
            }
            auto par = currNode->parent.lock();
            for (int i = 0; i < par->children.size(); i++)
            {
                if (par->children[i] == currNode)
                {
                    par->children.erase(par->children.begin() + i);
                }
            }
            currNode->parent.reset();
        }
        return true;
    }

  private:
    struct Node
    {
        Node(const char &init) : value(init), isLast(false) {}

        std::weak_ptr<Node> parent;
        std::vector<std::shared_ptr<Node>> children;
        char value;
        bool isLast;
    };

    std::shared_ptr<Node> root;
};
} // namespace mystd