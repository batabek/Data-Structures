#include "../singlylist.h"
#include <gtest/gtest.h>

TEST(SinglyListTest, Constructor) {
  SinglyList<int> list;

  EXPECT_EQ(list.GetHead(), nullptr);
  EXPECT_EQ(list.GetTail(), nullptr);
  EXPECT_EQ(list.Size(), 0);
}

TEST(SinglyListTest, EmptyList) {
  SinglyList<int> list;
  EXPECT_EQ(list.Size(), 0);
}

TEST(SinglyListTest, Size) {
  SinglyList<int> list;
  list.InsertAtBack(1);
  list.InsertAtBack(2);
  list.InsertAtBack(3);
  EXPECT_EQ(list.Size(), 3);
}

TEST(SinglyListTest, InsertAtFront) {
  SinglyList<int> list;

  list.InsertAtFront(1);
  EXPECT_EQ(list.GetHead()->data, 1);
  list.InsertAtFront(2);
  EXPECT_EQ(list.GetHead()->data, 2);
}

TEST(SinglyListTest, InsertAtBack) {
  SinglyList<int> list;

  list.InsertAtBack(1);
  EXPECT_EQ(list.GetTail()->data, 1);
  list.InsertAtBack(2);
  EXPECT_EQ(list.GetTail()->data, 2);
}

TEST(SinglyListTest, DeleteAtFront) {
  SinglyList<int> list;

  list.InsertAtFront(1);
  list.InsertAtFront(2);
  list.DeleteAtFront();
  EXPECT_EQ(list.GetHead()->data, 1);
}

TEST(SinglyListTest, DeleteAtBack) {
  SinglyList<int> list;

  list.InsertAtBack(1);
  list.InsertAtBack(2);
  list.InsertAtBack(3);
  list.DeleteAtBack();
  EXPECT_EQ(list.GetTail()->data, 2);
}

TEST(SinglyListTest, Search) {
  SinglyList<int> list;

  list.InsertAtBack(1);
  list.InsertAtBack(2);
  list.InsertAtBack(3);
  EXPECT_TRUE(list.Search(1));
  EXPECT_TRUE(list.Search(2));
  list.DeleteAtBack();
  EXPECT_FALSE(list.Search(3));
  list.DeleteAtBack();
  EXPECT_FALSE(list.Search(2));
}
