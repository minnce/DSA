#include <Data_Structures/Stack.hpp>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

using namespace dataStructures;

struct Dummy
{
    int x;

    Dummy() : x(0) {}

    Dummy(int val) : x(val) {}
};

TEST(StackTest, BasicInitializeTest)
{
    auto s = Stack<int>();
    ASSERT_EQ(s.Size(), 0);
    ASSERT_TRUE(s.Empty());
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    ASSERT_FALSE(s.Empty());
    ASSERT_EQ(s.Size(), 4);
    ASSERT_EQ(s.Pop(), 4);
    ASSERT_EQ(s.Pop(), 3);
    ASSERT_EQ(s.Pop(), 2);
    ASSERT_EQ(s.Size(), 1);
    ASSERT_EQ(s.Pop(), 1);
    ASSERT_EQ(s.Size(), 0);
    ASSERT_TRUE(s.Empty());
}

TEST(StackTest, StressTest)
{
    Stack<int> s;
    for (int i = 0; i < 10000; ++i)
    {
        s.Push(i);
    }
    ASSERT_EQ(s.Size(), 10000);

    for (int i = 9999; i >= 0; --i)
    {
        ASSERT_EQ(s.Pop(), i);
    }
    ASSERT_TRUE(s.Empty());
}

TEST(StackTest, PopFromEmptyStack)
{
    Stack<int> s;
    ASSERT_TRUE(s.Empty());
    EXPECT_THROW(s.Pop(), std::out_of_range);
}

TEST(StackTest, SingleElementTest)
{
    Stack<std::string> s;
    s.Push("hello");
    ASSERT_FALSE(s.Empty());
    ASSERT_EQ(s.Size(), 1);
    ASSERT_EQ(s.Pop(), "hello");
    ASSERT_TRUE(s.Empty());
    ASSERT_EQ(s.Size(), 0);
}

TEST(StackTest, InterleavedPushPopTest)
{
    Stack<int> s;
    s.Push(1);
    s.Push(2);
    ASSERT_EQ(s.Pop(), 2);
    s.Push(3);
    ASSERT_EQ(s.Pop(), 3);
    ASSERT_EQ(s.Pop(), 1);
    ASSERT_TRUE(s.Empty());
}

TEST(StackTest, ComplexObjectTest)
{
    Stack<Dummy> s;
    s.Push(Dummy(10));
    s.Push(Dummy(20));
    ASSERT_EQ(s.Pop().x, 20);
    ASSERT_EQ(s.Pop().x, 10);
    ASSERT_TRUE(s.Empty());
}
