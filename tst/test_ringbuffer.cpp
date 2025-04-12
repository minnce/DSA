#include <Data_Structures/Ringbuffer.hpp>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

using namespace mystd;

TEST(RingbufferTest, EmptyGetReturnsNullopt)
{
    auto ring = ringbuffer<int>(4);
    EXPECT_THROW(ring.get_item(), std::out_of_range);
}

TEST(RingbufferTest, BasicPushPop)
{
    ringbuffer<int> ring(3);
    ring.add_item(10);
    ring.add_item(20);

    EXPECT_EQ(ring.get_item(), 10);
    EXPECT_EQ(ring.get_item(), 20);
    EXPECT_THROW(ring.get_item(), std::out_of_range);
}

TEST(RingbufferTest, Wraparound)
{
    ringbuffer<int> ring(3);
    ring.add_item(1);
    ring.add_item(2);
    ring.add_item(3);

    EXPECT_EQ(ring.get_item(), 1);
    ring.add_item(4);

    EXPECT_EQ(ring.get_item(), 2);
    EXPECT_EQ(ring.get_item(), 3);
    EXPECT_EQ(ring.get_item(), 4);
    EXPECT_THROW(ring.get_item(), std::out_of_range);
}

TEST(RingbufferTest, ResizePreservesOrder)
{
    ringbuffer<int> ring(2);
    ring.add_item(100);
    ring.add_item(200);
    ring.add_item(300);

    EXPECT_EQ(ring.get_item(), 100);
    EXPECT_EQ(ring.get_item(), 200);
    EXPECT_EQ(ring.get_item(), 300);
    EXPECT_THROW(ring.get_item(), std::out_of_range);
}

TEST(RingbufferTest, AddAfterReads)
{
    ringbuffer<int> ring(3);
    ring.add_item(5);
    ring.add_item(6);
    EXPECT_EQ(ring.get_item(), 5);
    EXPECT_EQ(ring.get_item(), 6);

    ring.add_item(7);
    ring.add_item(8);
    ring.add_item(9);

    EXPECT_EQ(ring.get_item(), 7);
    EXPECT_EQ(ring.get_item(), 8);
    EXPECT_EQ(ring.get_item(), 9);
}

TEST(RingbufferTest, StringSupport)
{
    ringbuffer<std::string> ring(2);
    ring.add_item("foo");
    ring.add_item("bar");

    EXPECT_EQ(ring.get_item(), "foo");
    ring.add_item("baz");

    EXPECT_EQ(ring.get_item(), "bar");
    EXPECT_EQ(ring.get_item(), "baz");
    EXPECT_THROW(ring.get_item(), std::out_of_range);
}

TEST(RingbufferTest, StressTest)
{
    const int N = 10000;
    ringbuffer<int> ring(4);
    for (int i = 0; i < N; ++i)
        ring.add_item(i);

    for (int i = 0; i < N; ++i)
        ASSERT_EQ(ring.get_item(), i);

    EXPECT_THROW(ring.get_item(), std::out_of_range);
}
