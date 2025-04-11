#include <Data_Structures/Priority_Queue.hpp>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace dataStructures;

TEST(PriorityTest, InitializeEmpty)
{
    PriorityQueue<int> pq;
    ASSERT_EQ(pq.Size(), 0);
    ASSERT_TRUE(pq.Empty());
    ASSERT_THROW(pq.Pop(), std::out_of_range);
}

TEST(PriorityTest, PushPopSingle)
{
    PriorityQueue<int> pq;
    pq.Push(42);
    ASSERT_EQ(pq.Size(), 1);
    ASSERT_EQ(pq.Pop(), 42);
    ASSERT_TRUE(pq.Empty());
}

TEST(PriorityTest, PushMultipleMaintainsOrder)
{
    PriorityQueue<int> pq;
    pq.Push(10);
    pq.Push(50);
    pq.Push(20);
    pq.Push(40);
    pq.Push(30);

    ASSERT_EQ(pq.Size(), 5);
    ASSERT_EQ(pq.Pop(), 50);
    ASSERT_EQ(pq.Pop(), 40);
    ASSERT_EQ(pq.Pop(), 30);
    ASSERT_EQ(pq.Pop(), 20);
    ASSERT_EQ(pq.Pop(), 10);
    ASSERT_TRUE(pq.Empty());
}

TEST(PriorityTest, HandlesDuplicatesCorrectly)
{
    PriorityQueue<int> pq;
    pq.Push(5);
    pq.Push(5);
    pq.Push(5);
    ASSERT_EQ(pq.Size(), 3);

    ASSERT_EQ(pq.Pop(), 5);
    ASSERT_EQ(pq.Pop(), 5);
    ASSERT_EQ(pq.Pop(), 5);
    ASSERT_TRUE(pq.Empty());
}

TEST(PriorityTest, HandlesNegativeNumbers)
{
    PriorityQueue<int> pq;
    pq.Push(-10);
    pq.Push(0);
    pq.Push(-5);
    pq.Push(5);

    ASSERT_EQ(pq.Pop(), 5);
    ASSERT_EQ(pq.Pop(), 0);
    ASSERT_EQ(pq.Pop(), -5);
    ASSERT_EQ(pq.Pop(), -10);
    ASSERT_TRUE(pq.Empty());
}

TEST(PriorityTest, StressTestLargeNumberOfElements) {
    PriorityQueue<int> pq;
    int N = 1000;

    for (int i = 0; i < N; ++i) {
        pq.Push(i);
    }
    ASSERT_EQ(pq.Size(), N);

    for (int i = N - 1; i >= 0; --i) {
        ASSERT_EQ(pq.Pop(), i);
    }
    ASSERT_TRUE(pq.Empty());
}

TEST(PriorityTest, InterleavedPushPopOperations)
{
    PriorityQueue<int> pq;
    pq.Push(10);
    pq.Push(20);
    ASSERT_EQ(pq.Pop(), 20);
    pq.Push(15);
    ASSERT_EQ(pq.Pop(), 15);
    pq.Push(30);
    pq.Push(25);
    ASSERT_EQ(pq.Pop(), 30);
    ASSERT_EQ(pq.Pop(), 25);
    ASSERT_EQ(pq.Pop(), 10);
    ASSERT_TRUE(pq.Empty());
}
