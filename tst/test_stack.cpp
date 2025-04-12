#include <Data_Structures/Stack.hpp>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

using namespace mystd;

struct Dummy
{
    int x;

    Dummy() : x(0) {}

    Dummy(int val) : x(val) {}
};

TEST(StackTest, BasicInitializeTest)
{
    auto s = stack<int>();
    ASSERT_EQ(s.size(), 0);
    ASSERT_TRUE(s.empty());
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    ASSERT_FALSE(s.empty());
    ASSERT_EQ(s.size(), 4);
    ASSERT_EQ(s.pop(), 4);
    ASSERT_EQ(s.pop(), 3);
    ASSERT_EQ(s.pop(), 2);
    ASSERT_EQ(s.size(), 1);
    ASSERT_EQ(s.pop(), 1);
    ASSERT_EQ(s.size(), 0);
    ASSERT_TRUE(s.empty());
}

TEST(StackTest, StressTest)
{
    stack<int> s;
    for (int i = 0; i < 10000; ++i)
    {
        s.push(i);
    }
    ASSERT_EQ(s.size(), 10000);

    for (int i = 9999; i >= 0; --i)
    {
        ASSERT_EQ(s.pop(), i);
    }
    ASSERT_TRUE(s.empty());
}

TEST(StackTest, PopFromEmptyStack)
{
    stack<int> s;
    ASSERT_TRUE(s.empty());
    EXPECT_THROW(s.pop(), std::out_of_range);
}

TEST(StackTest, SingleElementTest)
{
    stack<std::string> s;
    s.push("hello");
    ASSERT_FALSE(s.empty());
    ASSERT_EQ(s.size(), 1);
    ASSERT_EQ(s.pop(), "hello");
    ASSERT_TRUE(s.empty());
    ASSERT_EQ(s.size(), 0);
}

TEST(StackTest, InterleavedPushPopTest)
{
    stack<int> s;
    s.push(1);
    s.push(2);
    ASSERT_EQ(s.pop(), 2);
    s.push(3);
    ASSERT_EQ(s.pop(), 3);
    ASSERT_EQ(s.pop(), 1);
    ASSERT_TRUE(s.empty());
}

TEST(StackTest, ComplexObjectTest)
{
    stack<Dummy> s;
    s.push(Dummy(10));
    s.push(Dummy(20));
    ASSERT_EQ(s.pop().x, 20);
    ASSERT_EQ(s.pop().x, 10);
    ASSERT_TRUE(s.empty());
}
