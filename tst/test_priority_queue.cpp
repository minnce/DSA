#include <Data_Structures/Priority_Queue.hpp>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace mystd;

TEST(PriorityTest, InitializeEmpty)
{
    priority_queue<int> pq;
    ASSERT_EQ(pq.size(), 0);
    ASSERT_TRUE(pq.empty());
    ASSERT_THROW(pq.pop(), std::out_of_range);
}

TEST(PriorityTest, PushPopSingle)
{
    priority_queue<int> pq;
    pq.push(42);
    ASSERT_EQ(pq.size(), 1);
    ASSERT_EQ(pq.pop(), 42);
    ASSERT_TRUE(pq.empty());
}

TEST(PriorityTest, PushMultipleMaintainsOrder)
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    pq.push(30);

    ASSERT_EQ(pq.size(), 5);
    ASSERT_EQ(pq.pop(), 50);
    ASSERT_EQ(pq.pop(), 40);
    ASSERT_EQ(pq.pop(), 30);
    ASSERT_EQ(pq.pop(), 20);
    ASSERT_EQ(pq.pop(), 10);
    ASSERT_TRUE(pq.empty());
}

TEST(PriorityTest, HandlesDuplicatesCorrectly)
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(5);
    pq.push(5);
    ASSERT_EQ(pq.size(), 3);

    ASSERT_EQ(pq.pop(), 5);
    ASSERT_EQ(pq.pop(), 5);
    ASSERT_EQ(pq.pop(), 5);
    ASSERT_TRUE(pq.empty());
}

TEST(PriorityTest, HandlesNegativeNumbers)
{
    priority_queue<int> pq;
    pq.push(-10);
    pq.push(0);
    pq.push(-5);
    pq.push(5);

    ASSERT_EQ(pq.pop(), 5);
    ASSERT_EQ(pq.pop(), 0);
    ASSERT_EQ(pq.pop(), -5);
    ASSERT_EQ(pq.pop(), -10);
    ASSERT_TRUE(pq.empty());
}

TEST(PriorityTest, StressTestLargeNumberOfElements)
{
    priority_queue<int> pq;
    int N = 1000;

    for (int i = 0; i < N; ++i)
    {
        pq.push(i);
    }
    ASSERT_EQ(pq.size(), N);

    for (int i = N - 1; i >= 0; --i)
    {
        ASSERT_EQ(pq.pop(), i);
    }
    ASSERT_TRUE(pq.empty());
}

TEST(PriorityTest, InterleavedPushPopOperations)
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    ASSERT_EQ(pq.pop(), 20);
    pq.push(15);
    ASSERT_EQ(pq.pop(), 15);
    pq.push(30);
    pq.push(25);
    ASSERT_EQ(pq.pop(), 30);
    ASSERT_EQ(pq.pop(), 25);
    ASSERT_EQ(pq.pop(), 10);
    ASSERT_TRUE(pq.empty());
}
