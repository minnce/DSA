#include <Data_Structures/Ringbuffer.hpp>
#include <gtest/gtest.h>
#include <optional>
#include <string>

using namespace dataStructures;

TEST(RingbufferTest, EmptyGetReturnsNullopt)
{
    Ringbuffer<int> ring(4);
    ASSERT_EQ(ring.get_item(), std::nullopt);
}

TEST(RingbufferTest, BasicPushPop)
{
    Ringbuffer<int> ring(3);
    ring.add_item(10);
    ring.add_item(20);

    EXPECT_EQ(ring.get_item(), 10);
    EXPECT_EQ(ring.get_item(), 20);
    EXPECT_EQ(ring.get_item(), std::nullopt);
}

TEST(RingbufferTest, Wraparound)
{
    Ringbuffer<int> ring(3);
    ring.add_item(1);
    ring.add_item(2);
    ring.add_item(3);

    EXPECT_EQ(ring.get_item(), 1);
    ring.add_item(4);

    EXPECT_EQ(ring.get_item(), 2);
    EXPECT_EQ(ring.get_item(), 3);
    EXPECT_EQ(ring.get_item(), 4);
    EXPECT_EQ(ring.get_item(), std::nullopt);
}

TEST(RingbufferTest, ResizePreservesOrder)
{
    Ringbuffer<int> ring(2);
    ring.add_item(100);
    ring.add_item(200);
    ring.add_item(300);

    EXPECT_EQ(ring.get_item(), 100);
    EXPECT_EQ(ring.get_item(), 200);
    EXPECT_EQ(ring.get_item(), 300);
    EXPECT_EQ(ring.get_item(), std::nullopt);
}

TEST(RingbufferTest, AddAfterReads)
{
    Ringbuffer<int> ring(3);
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
    Ringbuffer<std::string> ring(2);
    ring.add_item("foo");
    ring.add_item("bar");

    EXPECT_EQ(ring.get_item(), "foo");
    ring.add_item("baz");

    EXPECT_EQ(ring.get_item(), "bar");
    EXPECT_EQ(ring.get_item(), "baz");
    EXPECT_EQ(ring.get_item(), std::nullopt);
}

TEST(RingbufferTest, StressTest)
{
    const int N = 10000;
    Ringbuffer<int> ring(4);
    for (int i = 0; i < N; ++i)
        ring.add_item(i);

    for (int i = 0; i < N; ++i)
        ASSERT_EQ(ring.get_item(), i);

    ASSERT_EQ(ring.get_item(), std::nullopt);
}
