#include <Data_Structures/LinkedList.hpp>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace dataStructures;

TEST(LinkedListTest, EmptyList)
{
    LinkedList<int> list;
    auto vec = list.convert_to_vector();
    EXPECT_TRUE(vec.empty());
}

TEST(LinkedListTest, SingleItem)
{
    LinkedList<int> list;
    list.add_item(42);
    auto vec = list.convert_to_vector();
    ASSERT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 42);
}

TEST(LinkedListTest, MultipleItems)
{
    LinkedList<int> list;
    list.add_item(1);
    list.add_item(2);
    list.add_item(3);

    auto vec = list.convert_to_vector();
    ASSERT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(LinkedListTest, PrintEmpty)
{
    LinkedList<int> list;
    EXPECT_NO_THROW(list.print_list());
}

TEST(LinkedListTest, PrintNonEmpty)
{
    LinkedList<int> list;
    list.add_item(100);
    list.add_item(200);
    testing::internal::CaptureStdout();
    list.print_list();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("100") != std::string::npos);
    EXPECT_TRUE(output.find("200") != std::string::npos);
    EXPECT_TRUE(output.find("print done!") != std::string::npos);
}

TEST(LinkedListTest, StringItems)
{
    LinkedList<std::string> list;
    list.add_item("hello");
    list.add_item("world");

    auto vec = list.convert_to_vector();
    ASSERT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], "hello");
    EXPECT_EQ(vec[1], "world");
}

TEST(LinkedListTest, Duplicates)
{
    LinkedList<int> list;
    list.add_item(7);
    list.add_item(7);
    list.add_item(7);

    auto vec = list.convert_to_vector();
    ASSERT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 7);
    EXPECT_EQ(vec[1], 7);
    EXPECT_EQ(vec[2], 7);
}

TEST(LinkedListTest, StressTest)
{
    LinkedList<int> list;
    const int N = 1000;
    for (int i = 0; i < N; ++i)
        list.add_item(i);

    auto vec = list.convert_to_vector();
    ASSERT_EQ(vec.size(), N);
    for (int i = 0; i < N; ++i)
        EXPECT_EQ(vec[i], i);
}
