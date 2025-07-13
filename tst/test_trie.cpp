#include <Data_Structures/Trie.hpp>
#include <gtest/gtest.h>

using namespace mystd;

TEST(TrieTest, BasicTrie)
{
    auto t = Trie();
    t.add_item("hello");
    ASSERT_EQ(true, t.find("hello"));
    ASSERT_EQ(false, t.find("hell"));
    t.add_item("cat");
    t.add_item("cate");
    ASSERT_EQ(false, t.find("ca"));
    ASSERT_EQ(true, t.find("cat"));
    ASSERT_EQ(true, t.find("cate"));
    t.delete_item("cat");
    ASSERT_EQ(false, t.find("cat"));
    ASSERT_EQ(true, t.find("cate"));
    t.delete_item("cate");
    ASSERT_EQ(false, t.find("cat"));
    ASSERT_EQ(false, t.find("cate"));
}
