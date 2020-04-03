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
#include <array>

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

TEST(BSTTest, Inorder) {
  BinarySearchTree<int> bst;
  bst.insert(8);
  bst.insert(4);
  bst.insert(10);
  std::array<int, 3> exp_order = {4, 8, 10};
  std::array<int, 3> out;
  bst.inOrderWalk(bst.getRoot(), [&out](int val) {
    static int i = 0;
    out[i++] = val;
  });

  // make sure all values are same
  for (int i = 0; i < exp_order.size(); i++) {
    EXPECT_EQ(out[i], exp_order[i]);
  }
}

TEST(BSTTest, InorderIter) {
  BinarySearchTree<int> bst;
  bst.insert(8);
  bst.insert(4);
  bst.insert(10);
  std::array<int, 3> exp_order = {4, 8, 10};
  std::array<int, 3> out;
  bst.inOrderWalk([&out](int val) {
    static int i = 0;
    out[i++] = val;
  });

  // make sure all values are same
  for (int i = 0; i < exp_order.size(); i++) {
    EXPECT_EQ(out[i], exp_order[i]);
  }
}


TEST(BSTTest, Preorder) {
  BinarySearchTree<int> bst;
  bst.insert(8);
  bst.insert(4);
  bst.insert(10);
  std::array<int, 3> exp_order = {8, 4, 10};
  std::array<int, 3> out;
  bst.preOrderWalk(bst.getRoot(), [&out](int val) {
    static int i = 0;
    out[i++] = val;
  });

  // make sure all values are same
  for (int i = 0; i < exp_order.size(); i++) {
    EXPECT_EQ(out[i], exp_order[i]);
  }
}

TEST(BSTTest, Postorder) {
  BinarySearchTree<int> bst;
  bst.insert(8);
  bst.insert(4);
  bst.insert(10);
  std::array<int, 3> exp_order = {4, 10, 8};
  std::array<int, 3> out;
  bst.postOrderWalk(bst.getRoot(), [&out](int val) {
    static int i = 0;
    out[i++] = val;
  });

  // make sure all values are same
  for (int i = 0; i < exp_order.size(); i++) {
    EXPECT_EQ(out[i], exp_order[i]);
  }
}