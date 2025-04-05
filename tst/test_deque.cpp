#include <Data_Structures/Deque.hpp>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace dataStructures;

TEST(DequeTest, BasicPushBackPopFront)
{
    Deque<int> d;
    d.Push_Back(1);
    d.Push_Back(2);
    d.Push_Back(3);

    ASSERT_EQ(d.Size(), 3);
    ASSERT_EQ(d.Front(), 1);
    ASSERT_EQ(d.Back(), 3);

    ASSERT_EQ(d.Pop_Front(), 1);
    ASSERT_EQ(d.Pop_Front(), 2);
    ASSERT_EQ(d.Pop_Front(), 3);
    ASSERT_TRUE(d.Empty());
}

TEST(DequeTest, BasicPushFrontPopBack)
{
    Deque<int> d;
    d.Push_Front(1);
    d.Push_Front(2);
    d.Push_Front(3);

    ASSERT_EQ(d.Size(), 3);
    ASSERT_EQ(d.Front(), 3);
    ASSERT_EQ(d.Back(), 1);

    ASSERT_EQ(d.Pop_Back(), 1);
    ASSERT_EQ(d.Pop_Back(), 2);
    ASSERT_EQ(d.Pop_Back(), 3);
    ASSERT_TRUE(d.Empty());
}

TEST(DequeTest, MixedPushesAndPops)
{
    Deque<int> d;
    d.Push_Back(10);
    d.Push_Front(20);
    d.Push_Back(30);
    d.Push_Front(40);

    ASSERT_EQ(d.Size(), 4);
    ASSERT_EQ(d.Front(), 40);
    ASSERT_EQ(d.Back(), 30);

    ASSERT_EQ(d.Pop_Front(), 40);
    ASSERT_EQ(d.Pop_Back(), 30);
    ASSERT_EQ(d.Pop_Front(), 20);
    ASSERT_EQ(d.Pop_Back(), 10);
    ASSERT_TRUE(d.Empty());
}

TEST(DequeTest, ThrowsWhenEmptyPopFront)
{
    Deque<int> d;
    ASSERT_THROW(d.Pop_Front(), std::out_of_range);
}

TEST(DequeTest, ThrowsWhenEmptyPopBack)
{
    Deque<int> d;
    ASSERT_THROW(d.Pop_Back(), std::out_of_range);
}

TEST(DequeTest, ThrowsWhenAccessFrontEmpty)
{
    Deque<int> d;
    ASSERT_THROW(d.Front(), std::out_of_range);
}

TEST(DequeTest, ThrowsWhenAccessBackEmpty)
{
    Deque<int> d;
    ASSERT_THROW(d.Back(), std::out_of_range);
}

TEST(DequeTest, PushMoreThanInitialCapacity)
{
    Deque<int> d;
    for (int i = 0; i < 10; ++i)
    {
        d.Push_Back(i);
    }

    ASSERT_EQ(d.Size(), 10);
    for (int i = 0; i < 10; ++i)
    {
        ASSERT_EQ(d[i], i);
    }
}

TEST(DequeTest, OperatorIndexing)
{
    Deque<int> d;
    d.Push_Back(100);
    d.Push_Back(200);
    d.Push_Back(300);

    ASSERT_EQ(d[0], 100);
    ASSERT_EQ(d[1], 200);
    ASSERT_EQ(d[2], 300);

    d.Pop_Front();
    ASSERT_EQ(d[0], 200);
    ASSERT_EQ(d[1], 300);
}

TEST(DequeTest, IndexOutOfRangeThrows)
{
    Deque<int> d;
    d.Push_Back(1);
    d.Push_Back(2);

    ASSERT_THROW(d[2], std::out_of_range);
    ASSERT_THROW(d[5], std::out_of_range);
}

TEST(DequeTest, StressTestLargeNumberOfElements)
{
    Deque<int> d;
    const int N = 1000;

    for (int i = 0; i < N; ++i)
    {
        d.Push_Back(i);
    }
    ASSERT_EQ(d.Size(), N);

    for (int i = 0; i < N; ++i)
    {
        ASSERT_EQ(d[i], i);
    }

    for (int i = 0; i < N; ++i)
    {
        ASSERT_EQ(d.Pop_Front(), i);
    }
    ASSERT_TRUE(d.Empty());
}
