#include "../queue.h"
#include <gtest/gtest.h>

TEST(QueueTest, Constructor) {
  Queue<int> queue;

  EXPECT_EQ(queue.Size(), 0);
}

TEST(QueueTest, Enqueue) {
  Queue<int> queue;
  const unsigned num_items = 10;
  for (auto i = 1; i <= num_items; i++) {
    queue.Enqueue(i);
    EXPECT_EQ(queue.Size(), i);
  }
}

TEST(QueueTest, Dequeue) {
  Queue<int> queue;
  const unsigned num_items = 5;
  for (auto i = 1; i <= num_items; i++) {
    queue.Enqueue(i);
  }

  queue.Dequeue();
  EXPECT_EQ(queue.Size(), num_items - 1);
  queue.Dequeue();
  EXPECT_EQ(queue.Size(), num_items - 2);
}

TEST(QueueTest, Peek) {
  Queue<int> queue;
  const unsigned num_items = 5;
  for (auto i = 1; i <= num_items; i++) {
    queue.Enqueue(i);
    EXPECT_EQ(queue.Peek(), 1);
  }

  queue.Dequeue();
  EXPECT_EQ(queue.Size(), num_items - 1);
  EXPECT_EQ(queue.Peek(), 2);
}
