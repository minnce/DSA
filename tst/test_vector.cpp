#include <Data_Structures/Vector.hpp>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

using namespace dataStructures;

struct Person
{
    std::string name;
    int age;

    bool operator==(const Person &other) const { return name == other.name && age == other.age; }
};

TEST(VectorTest, InitializeTest)
{
    auto v = Vector<int>();
    ASSERT_EQ(v.Size(), 0);
    ASSERT_EQ(v.getCapacity(), 2);
    ASSERT_THROW(v[0], std::out_of_range);
    v.Push_Back(1);
    ASSERT_EQ(v[0], 1);
    ASSERT_THROW(v[1], std::out_of_range);
    ASSERT_THROW(v[2], std::out_of_range);
    v[0] = 10;
    ASSERT_EQ(v[0], 10);
}

TEST(VectorTest, PopTest)
{
    auto v = Vector<int>();
    ASSERT_THROW(v.Pop_Back(), std::out_of_range);
    v.Push_Back(1);
    ASSERT_EQ(1, v.Pop_Back());
    ASSERT_EQ(v.Size(), 0);
    ASSERT_EQ(v.getCapacity(), 2);
}

TEST(VectorTest, CharTest)
{
    auto v = Vector<char>();
    v.Push_Back('a');
    ASSERT_EQ('a', v.Pop_Back());
    ASSERT_EQ(v.Size(), 0);
    ASSERT_EQ(v.getCapacity(), 2);
}

TEST(VectorTest, StringTest)
{
    auto v = Vector<std::string>();
    v.Push_Back("Test");
    ASSERT_EQ("Test", v.Pop_Back());
    ASSERT_EQ(v.Size(), 0);
    ASSERT_EQ(v.getCapacity(), 2);
}

TEST(VectorTest, ResizeAndAccessBeyondInitialCapacity)
{
    Vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.Push_Back(i);
    }
    ASSERT_EQ(v.Size(), 10);
    ASSERT_GE(v.getCapacity(), 10);

    for (int i = 0; i < 10; ++i)
    {
        ASSERT_EQ(v[i], i);
    }

    ASSERT_THROW(v[10], std::out_of_range);
}

TEST(VectorTest, MultiplePops)
{
    Vector<int> v;
    v.Push_Back(5);
    v.Push_Back(10);
    v.Push_Back(15);

    ASSERT_EQ(v.Pop_Back(), 15);
    ASSERT_EQ(v.Pop_Back(), 10);
    ASSERT_EQ(v.Pop_Back(), 5);
    ASSERT_THROW(v.Pop_Back(), std::out_of_range);
}

TEST(VectorTest, CustomStructTest)
{
    Vector<Person> people;
    people.Push_Back({"Alice", 30});
    people.Push_Back({"Bob", 25});

    auto p1 = people.Pop_Back();
    ASSERT_EQ(p1, Person("Bob", 25));

    auto p2 = people.Pop_Back();
    ASSERT_EQ(p2, Person("Alice", 30));

    ASSERT_EQ(people.Size(), 0);
}

TEST(VectorTest, PushAndAccessAfterReallocation)
{
    Vector<std::string> v;
    for (int i = 0; i < 100; ++i)
    {
        v.Push_Back("Item " + std::to_string(i));
    }

    ASSERT_EQ(v.Size(), 100);
    for (int i = 0; i < 100; ++i)
    {
        ASSERT_EQ(v[i], "Item " + std::to_string(i));
    }
}

TEST(VectorTest, AlternatingPushPop)
{
    Vector<std::string> v;

    v.Push_Back("A");
    ASSERT_EQ(v.Pop_Back(), "A");

    v.Push_Back("B");
    v.Push_Back("C");
    ASSERT_EQ(v.Pop_Back(), "C");

    v.Push_Back("D");
    ASSERT_EQ(v.Size(), 2);
    ASSERT_EQ(v[0], "B");
    ASSERT_EQ(v[1], "D");
}
