#include <Data_Structures/RB_Tree.hpp>
#include <gtest/gtest.h>

namespace mystd
{
TEST(RBTreeTest, BasicInit) { auto rb = RBTree(5); }
} // namespace mystd