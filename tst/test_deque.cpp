#include <Data_Structures/Deque.hpp>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace mystd;

TEST(DequeTest, BasicPushBackPopFront)
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);

    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d.front(), 1);
    ASSERT_EQ(d.back(), 3);

    ASSERT_EQ(d.pop_front(), 1);
    ASSERT_EQ(d.pop_front(), 2);
    ASSERT_EQ(d.pop_front(), 3);
    ASSERT_TRUE(d.empty());
}

TEST(DequeTest, BasicPushFrontPopBack)
{
    deque<int> d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);

    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d.front(), 3);
    ASSERT_EQ(d.back(), 1);

    ASSERT_EQ(d.pop_back(), 1);
    ASSERT_EQ(d.pop_back(), 2);
    ASSERT_EQ(d.pop_back(), 3);
    ASSERT_TRUE(d.empty());
}

TEST(DequeTest, MixedPushesAndPops)
{
    deque<int> d;
    d.push_back(10);
    d.push_front(20);
    d.push_back(30);
    d.push_front(40);

    ASSERT_EQ(d.size(), 4);
    ASSERT_EQ(d.front(), 40);
    ASSERT_EQ(d.back(), 30);

    ASSERT_EQ(d.pop_front(), 40);
    ASSERT_EQ(d.pop_back(), 30);
    ASSERT_EQ(d.pop_front(), 20);
    ASSERT_EQ(d.pop_back(), 10);
    ASSERT_TRUE(d.empty());
}

TEST(DequeTest, ThrowsWhenEmptyPopFront)
{
    deque<int> d;
    ASSERT_THROW(d.pop_front(), std::out_of_range);
}

TEST(DequeTest, ThrowsWhenEmptyPopBack)
{
    deque<int> d;
    ASSERT_THROW(d.pop_back(), std::out_of_range);
}

TEST(DequeTest, ThrowsWhenAccessFrontEmpty)
{
    deque<int> d;
    ASSERT_THROW(d.front(), std::out_of_range);
}

TEST(DequeTest, ThrowsWhenAccessBackEmpty)
{
    deque<int> d;
    ASSERT_THROW(d.back(), std::out_of_range);
}

TEST(DequeTest, PushMoreThanInitialCapacity)
{
    deque<int> d;
    for (int i = 0; i < 10; ++i)
    {
        d.push_back(i);
    }

    ASSERT_EQ(d.size(), 10);
    for (int i = 0; i < 10; ++i)
    {
        ASSERT_EQ(d[i], i);
    }
}

TEST(DequeTest, OperatorIndexing)
{
    deque<int> d;
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);

    ASSERT_EQ(d[0], 100);
    ASSERT_EQ(d[1], 200);
    ASSERT_EQ(d[2], 300);

    d.pop_front();
    ASSERT_EQ(d[0], 200);
    ASSERT_EQ(d[1], 300);
}

TEST(DequeTest, IndexOutOfRangeThrows)
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);

    ASSERT_THROW(d[2], std::out_of_range);
    ASSERT_THROW(d[5], std::out_of_range);
}

TEST(DequeTest, StressTestLargeNumberOfElements)
{
    deque<int> d;
    const int N = 1000;

    for (int i = 0; i < N; ++i)
    {
        d.push_back(i);
    }
    ASSERT_EQ(d.size(), N);

    for (int i = 0; i < N; ++i)
    {
        ASSERT_EQ(d[i], i);
    }

    for (int i = 0; i < N; ++i)
    {
        ASSERT_EQ(d.pop_front(), i);
    }
    ASSERT_TRUE(d.empty());
}
