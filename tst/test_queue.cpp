#include <Data_Structures/Queue.hpp>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace mystd;

TEST(QueueTest, BasicInitializeTest)
{
    auto q = queue<int>();
    q.push(2);
    ASSERT_EQ(q.size(), 1);
    ASSERT_FALSE(q.empty());
    ASSERT_EQ(q.pop(), 2);
    ASSERT_THROW(q.pop(), std::out_of_range);
    ASSERT_TRUE(q.empty());
    ASSERT_EQ(q.size(), 0);
}

TEST(QueueTest, PushAndPopMultipleItems)
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    ASSERT_EQ(q.size(), 3);
    ASSERT_EQ(q.pop(), 1);
    ASSERT_EQ(q.pop(), 2);
    ASSERT_EQ(q.pop(), 3);
    ASSERT_TRUE(q.empty());
}

TEST(QueueTest, FrontAndBackTest)
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    ASSERT_EQ(q.front(), 10);
    ASSERT_EQ(q.back(), 30);

    q.pop();
    ASSERT_EQ(q.front(), 20);
    ASSERT_EQ(q.back(), 30);
}

TEST(QueueTest, PopFromEmptyQueueThrows)
{
    queue<int> q;
    ASSERT_THROW(q.pop(), std::out_of_range);

    q.push(5);
    q.pop();
    ASSERT_THROW(q.pop(), std::out_of_range);
}

TEST(QueueTest, FrontOnEmptyQueueThrows)
{
    queue<int> q;
    ASSERT_THROW(q.front(), std::out_of_range);

    q.push(42);
    q.pop();
    ASSERT_THROW(q.front(), std::out_of_range);
}

TEST(QueueTest, BackOnEmptyQueueThrows)
{
    queue<int> q;
    ASSERT_THROW(q.back(), std::out_of_range);

    q.push(100);
    q.pop();
    ASSERT_THROW(q.back(), std::out_of_range);
}

TEST(QueueTest, SizeConsistencyTest)
{
    queue<int> q;
    ASSERT_EQ(q.size(), 0);

    for (int i = 0; i < 5; ++i)
    {
        q.push(i);
        ASSERT_EQ(q.size(), i + 1);
    }

    for (int i = 5; i > 0; --i)
    {
        q.pop();
        ASSERT_EQ(q.size(), i - 1);
    }
}

TEST(QueueTest, EmptyCheck)
{
    queue<int> q;
    ASSERT_TRUE(q.empty());

    q.push(123);
    ASSERT_FALSE(q.empty());

    q.pop();
    ASSERT_TRUE(q.empty());
}
