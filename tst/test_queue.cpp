#include <Data_Structures/Queue.hpp>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace dataStructures;

TEST(QueueTest, BasicInitializeTest)
{
    auto q = Queue<int>();
    q.Push(2);
    ASSERT_EQ(q.Size(), 1);
    ASSERT_FALSE(q.Empty());
    ASSERT_EQ(q.Pop(), 2);
    ASSERT_THROW(q.Pop(), std::out_of_range);
    ASSERT_TRUE(q.Empty());
    ASSERT_EQ(q.Size(), 0);
}