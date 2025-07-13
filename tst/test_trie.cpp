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

TEST(TrieTest, OverlappingPrefixes)
{
    Trie t;
    t.add_item("apple");
    t.add_item("app");
    t.add_item("apricot");

    ASSERT_TRUE(t.find("apple"));
    ASSERT_TRUE(t.find("app"));
    ASSERT_TRUE(t.find("apricot"));
    ASSERT_FALSE(t.find("appl"));
}

TEST(TrieTest, DeletionEdgeCases)
{
    Trie t;
    t.add_item("a");
    t.add_item("ab");
    t.add_item("abc");

    t.delete_item("ab");
    ASSERT_TRUE(t.find("a"));
    ASSERT_FALSE(t.find("ab"));
    ASSERT_TRUE(t.find("abc"));

    t.delete_item("abc");
    ASSERT_TRUE(t.find("a"));
    ASSERT_FALSE(t.find("abc"));

    t.delete_item("a");
    ASSERT_FALSE(t.find("a"));
}

TEST(TrieTest, CaseSensitivity)
{
    Trie t;
    t.add_item("Test");
    t.add_item("test");

    ASSERT_TRUE(t.find("Test"));
    ASSERT_TRUE(t.find("test"));
    ASSERT_FALSE(t.find("Tes"));
    ASSERT_FALSE(t.find("TEST"));

    t.delete_item("test");
    ASSERT_FALSE(t.find("test"));
    ASSERT_TRUE(t.find("Test"));
}

TEST(TrieTest, LongWordStressTest)
{
    Trie t;
    std::string long_word(10000, 'a');
    t.add_item(long_word);
    ASSERT_TRUE(t.find(long_word));

    long_word[9999] = 'b';
    ASSERT_FALSE(t.find(long_word));
}
