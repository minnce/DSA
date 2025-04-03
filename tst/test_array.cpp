#include <Data_Structures/Array.hpp>
#include <gtest/gtest.h>

using namespace dataStructures;

TEST(ArrayTest, BasicArray)
{
    auto arr = Array<int>(5);
    arr[1] = 2;
    ASSERT_EQ(arr[1], 2);
}