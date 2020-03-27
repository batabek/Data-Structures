/**
 * @file binarysearchtree_test.cpp
 * @author Berk Atabek (atabek.berk@gmail.com)
 * @brief Unit Tests for BinarySearchTree Class
 * @version 1.0
 * @date 27-03-2020
 *
 * @copyright Copyright (c) 2020
 *
 */
#include "../binarysearchtree.h"
#include <gtest/gtest.h>

TEST(BSTTest, Constructor) {
  BinarySearchTree<int> bst;

  EXPECT_EQ(bst.size(), 0);
}

TEST(BSTTest, Insert) {
  BinarySearchTree<int> bst;
  const unsigned num_items = 10;
  for (auto i = 1; i <= num_items; i++) {
    bst.insert(i);
    EXPECT_EQ(bst.search(i)->data, i);
  }

  EXPECT_EQ(bst.size(), num_items);
}

TEST(BSTTest, Remove) {
  BinarySearchTree<int> bst;
  const unsigned num_items = 10;
  for (auto i = 1; i <= num_items; i++) {
    bst.insert(i);
  }

  for (auto i = num_items; i >= 1; i--) {
    bst.deleteItem(i);
    EXPECT_EQ(bst.search(i), nullptr);
  }
}