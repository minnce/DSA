#include <Data_Structures/Ringbuffer.hpp>
#include <gtest/gtest.h>
#include <optional>

using namespace dataStructures;

TEST(RingbufferTest, NoItemTest)
{
    auto ring = Ringbuffer(5);
    ASSERT_EQ(std::nullopt, ring.get_item());
};