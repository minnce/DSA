#include <Data_Structures/Pair.hpp>
#include <gtest/gtest.h>

using namespace mystd;

TEST(PairTest, BasicTest)
{
    auto p = pair(1, 2);
    ASSERT_EQ(p.first, 1);
    ASSERT_EQ(p.second, 2);
    auto p2 = make_pair(1, 4);
    ASSERT_EQ(p2.first, 1);
    ASSERT_EQ(p2.second, 4);
    auto p3 = make_pair(1, 2);
    ASSERT_EQ(p, p3);
}