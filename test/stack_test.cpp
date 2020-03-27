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

TEST(StackTest, Pop)
{
  Stack<int> stack;
  const unsigned num_items=5;
  for(auto i=1;i<=num_items;i++)
  {
    stack.Push(i);
  }
  
  stack.Pop();
  EXPECT_EQ(stack.Size(),num_items-1);
  stack.Pop();
  EXPECT_EQ(stack.Size(),num_items-2);
  
}

TEST(StackTest, Peek)
{
  Stack<int> stack;
  const unsigned num_items=5;
  for(auto i=1;i<=num_items;i++)
  {
    stack.Push(i);
  }
  
  EXPECT_EQ(stack.Peek(),num_items);
  stack.Pop();
  EXPECT_EQ(stack.Peek(),num_items-1);
  
}


