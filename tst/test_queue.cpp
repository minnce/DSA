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

TEST(QueueTest, PushAndPopMultipleItems)
{
    Queue<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);

    ASSERT_EQ(q.Size(), 3);
    ASSERT_EQ(q.Pop(), 1);
    ASSERT_EQ(q.Pop(), 2);
    ASSERT_EQ(q.Pop(), 3);
    ASSERT_TRUE(q.Empty());
}

TEST(QueueTest, FrontAndBackTest)
{
    Queue<int> q;
    q.Push(10);
    q.Push(20);
    q.Push(30);

    ASSERT_EQ(q.Front(), 10);
    ASSERT_EQ(q.Back(), 30);

    q.Pop();
    ASSERT_EQ(q.Front(), 20);
    ASSERT_EQ(q.Back(), 30);
}

TEST(QueueTest, PopFromEmptyQueueThrows)
{
    Queue<int> q;
    ASSERT_THROW(q.Pop(), std::out_of_range);

    q.Push(5);
    q.Pop();
    ASSERT_THROW(q.Pop(), std::out_of_range);
}

TEST(QueueTest, FrontOnEmptyQueueThrows)
{
    Queue<int> q;
    ASSERT_THROW(q.Front(), std::out_of_range);

    q.Push(42);
    q.Pop();
    ASSERT_THROW(q.Front(), std::out_of_range);
}

TEST(QueueTest, BackOnEmptyQueueThrows)
{
    Queue<int> q;
    ASSERT_THROW(q.Back(), std::out_of_range);

    q.Push(100);
    q.Pop();
    ASSERT_THROW(q.Back(), std::out_of_range);
}

TEST(QueueTest, SizeConsistencyTest)
{
    Queue<int> q;
    ASSERT_EQ(q.Size(), 0);

    for (int i = 0; i < 5; ++i)
    {
        q.Push(i);
        ASSERT_EQ(q.Size(), i + 1);
    }

    for (int i = 5; i > 0; --i)
    {
        q.Pop();
        ASSERT_EQ(q.Size(), i - 1);
    }
}

TEST(QueueTest, EmptyCheck)
{
    Queue<int> q;
    ASSERT_TRUE(q.Empty());

    q.Push(123);
    ASSERT_FALSE(q.Empty());

    q.Pop();
    ASSERT_TRUE(q.Empty());
}
