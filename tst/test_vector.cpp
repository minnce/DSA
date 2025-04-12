#include <Data_Structures/Vector.hpp>
#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

using namespace mystd;

struct Person
{
    std::string name;
    int age;

    bool operator==(const Person &other) const { return name == other.name && age == other.age; }
};

TEST(VectorTest, InitializeTest)
{
    auto v = vector<int>();
    ASSERT_EQ(v.size(), 0);
    ASSERT_THROW(v[0], std::out_of_range);
    v.push_back(1);
    ASSERT_EQ(v[0], 1);
    ASSERT_THROW(v[1], std::out_of_range);
    ASSERT_THROW(v[2], std::out_of_range);
    v[0] = 10;
    ASSERT_EQ(v[0], 10);
}

TEST(VectorTest, PopTest)
{
    auto v = vector<int>();
    ASSERT_THROW(v.pop_back(), std::out_of_range);
    v.push_back(1);
    ASSERT_EQ(1, v.pop_back());
    ASSERT_EQ(v.size(), 0);
}

TEST(VectorTest, CharTest)
{
    auto v = vector<char>();
    v.push_back('a');
    ASSERT_EQ('a', v.pop_back());
    ASSERT_EQ(v.size(), 0);
}

TEST(VectorTest, StringTest)
{
    auto v = vector<std::string>();
    v.push_back("Test");
    ASSERT_EQ("Test", v.pop_back());
    ASSERT_EQ(v.size(), 0);
}

TEST(VectorTest, ResizeAndAccessBeyondInitialCapacity)
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    ASSERT_EQ(v.size(), 10);

    for (int i = 0; i < 10; ++i)
    {
        ASSERT_EQ(v[i], i);
    }

    ASSERT_THROW(v[10], std::out_of_range);
}

TEST(VectorTest, MultiplePops)
{
    vector<int> v;
    v.push_back(5);
    v.push_back(10);
    v.push_back(15);

    ASSERT_EQ(v.pop_back(), 15);
    ASSERT_EQ(v.pop_back(), 10);
    ASSERT_EQ(v.pop_back(), 5);
    ASSERT_THROW(v.pop_back(), std::out_of_range);
}

TEST(VectorTest, CustomStructTest)
{
    vector<Person> people;
    people.push_back({"Alice", 30});
    people.push_back({"Bob", 25});

    auto p1 = people.pop_back();
    ASSERT_EQ(p1, Person("Bob", 25));

    auto p2 = people.pop_back();
    ASSERT_EQ(p2, Person("Alice", 30));

    ASSERT_EQ(people.size(), 0);
}

TEST(VectorTest, PushAndAccessAfterReallocation)
{
    vector<std::string> v;
    for (int i = 0; i < 100; ++i)
    {
        v.push_back("Item " + std::to_string(i));
    }

    ASSERT_EQ(v.size(), 100);
    for (int i = 0; i < 100; ++i)
    {
        ASSERT_EQ(v[i], "Item " + std::to_string(i));
    }
}

TEST(VectorTest, AlternatingPushPop)
{
    vector<std::string> v;

    v.push_back("A");
    ASSERT_EQ(v.pop_back(), "A");

    v.push_back("B");
    v.push_back("C");
    ASSERT_EQ(v.pop_back(), "C");

    v.push_back("D");
    ASSERT_EQ(v.size(), 2);
    ASSERT_EQ(v[0], "B");
    ASSERT_EQ(v[1], "D");
}
