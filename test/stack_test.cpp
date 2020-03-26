#include "../stack.h"
#include <gtest/gtest.h>

TEST(StackTest, Constructor) {
  Stack<int> stack;

  EXPECT_EQ(stack.Size(), 0);
}

TEST(StackTest, Push) {
  Stack<int> stack;
  const unsigned num_items=10;
  for(auto i=1;i<=num_items;i++)
  {
    stack.Push(i);
  }
  EXPECT_EQ(stack.Size(), num_items);
  EXPECT_EQ(stack.Peek(), num_items); 
}

