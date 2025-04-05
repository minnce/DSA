#include <Data_Structures/Ringbuffer.hpp>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

using namespace dataStructures;

TEST(RingbufferTest, EmptyGetReturnsNullopt)
{
    auto ring = Ringbuffer<int>(4);
    EXPECT_THROW(ring.Get_Item(), std::out_of_range);
}

TEST(RingbufferTest, BasicPushPop)
{
    Ringbuffer<int> ring(3);
    ring.Add_Item(10);
    ring.Add_Item(20);

    EXPECT_EQ(ring.Get_Item(), 10);
    EXPECT_EQ(ring.Get_Item(), 20);
    EXPECT_THROW(ring.Get_Item(), std::out_of_range);
}

TEST(RingbufferTest, Wraparound)
{
    Ringbuffer<int> ring(3);
    ring.Add_Item(1);
    ring.Add_Item(2);
    ring.Add_Item(3);

    EXPECT_EQ(ring.Get_Item(), 1);
    ring.Add_Item(4);

    EXPECT_EQ(ring.Get_Item(), 2);
    EXPECT_EQ(ring.Get_Item(), 3);
    EXPECT_EQ(ring.Get_Item(), 4);
    EXPECT_THROW(ring.Get_Item(), std::out_of_range);
}

TEST(RingbufferTest, ResizePreservesOrder)
{
    Ringbuffer<int> ring(2);
    ring.Add_Item(100);
    ring.Add_Item(200);
    ring.Add_Item(300);

    EXPECT_EQ(ring.Get_Item(), 100);
    EXPECT_EQ(ring.Get_Item(), 200);
    EXPECT_EQ(ring.Get_Item(), 300);
    EXPECT_THROW(ring.Get_Item(), std::out_of_range);
}

TEST(RingbufferTest, AddAfterReads)
{
    Ringbuffer<int> ring(3);
    ring.Add_Item(5);
    ring.Add_Item(6);
    EXPECT_EQ(ring.Get_Item(), 5);
    EXPECT_EQ(ring.Get_Item(), 6);

    ring.Add_Item(7);
    ring.Add_Item(8);
    ring.Add_Item(9);

    EXPECT_EQ(ring.Get_Item(), 7);
    EXPECT_EQ(ring.Get_Item(), 8);
    EXPECT_EQ(ring.Get_Item(), 9);
}

TEST(RingbufferTest, StringSupport)
{
    Ringbuffer<std::string> ring(2);
    ring.Add_Item("foo");
    ring.Add_Item("bar");

    EXPECT_EQ(ring.Get_Item(), "foo");
    ring.Add_Item("baz");

    EXPECT_EQ(ring.Get_Item(), "bar");
    EXPECT_EQ(ring.Get_Item(), "baz");
    EXPECT_THROW(ring.Get_Item(), std::out_of_range);
}

TEST(RingbufferTest, StressTest)
{
    const int N = 10000;
    Ringbuffer<int> ring(4);
    for (int i = 0; i < N; ++i)
        ring.Add_Item(i);

    for (int i = 0; i < N; ++i)
        ASSERT_EQ(ring.Get_Item(), i);

    EXPECT_THROW(ring.Get_Item(), std::out_of_range);
}
