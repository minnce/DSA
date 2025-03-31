#include <Data_Structures/Ringbuffer.hpp>
#include <gtest/gtest.h>
#include <optional>

using namespace dataStructures;

TEST(RingbufferTest, NoItemTest)
{
    auto ring = Ringbuffer(5);
    ASSERT_EQ(std::nullopt, ring.get_item());
};

TEST(RingbufferTest, GetTset)
{
    auto ring = Ringbuffer(100);
    ring.add_item(1);
    ASSERT_EQ(1, ring.get_item());
}

TEST(RingbufferTest, ResizeTest)
{
    auto ring = Ringbuffer(2);
    ring.add_item(1);
    ring.add_item(2);
    ring.add_item(3);
    ASSERT_EQ(ring.get_item(), 1);
    ASSERT_EQ(ring.get_item(), 2);
    ASSERT_EQ(ring.get_item(), 3);
    ASSERT_EQ(std::nullopt, ring.get_item());
}