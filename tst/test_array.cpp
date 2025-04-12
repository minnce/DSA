#include <Data_Structures/Array.hpp>
#include <gtest/gtest.h>

using namespace mystd;

TEST(ArrayTest, BasicArray)
{
    array arr = array<int>(5);
    arr[1] = 2;
    ASSERT_EQ(arr[1], 2);
}