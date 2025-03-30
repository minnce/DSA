#include <Data_Structures/LinkedList.hpp>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace dataStructures;

TEST(LinkedListTest, Sanity)
{
    LinkedList<std::string> testList;
    std::vector<std::string> res = testList.convert_to_vector();
    EXPECT_EQ(res.size(), 0);
}

TEST(LinkedListTest, ListAddPrint)
{
    LinkedList<int> testList;
    testList.add_item(10);
    testList.add_item(20);
    std::vector<int> res = testList.convert_to_vector();
    EXPECT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], 10);
    EXPECT_EQ(res[1], 20);
}
