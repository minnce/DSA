#include <Data_Structures/Vector.hpp>
#include <gtest/gtest.h>
#include <optional>

using namespace dataStructures;

TEST(VectorTest, InitializeTest)
{
    auto v = Vector<int>();
    ASSERT_EQ(v.Size(), 0);
    ASSERT_EQ(v.getCapacity(), 2);
    ASSERT_EQ(v[0], std::nullopt);
    v.Push_Back(1);
    ASSERT_EQ(v[0], 1);
}