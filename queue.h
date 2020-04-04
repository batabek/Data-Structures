#ifndef QUEUE
#define QUEUE

#include "singlylist.h"

/**
 * @brief Template Queue Container
 *
 * @tparam T Type parameter
 */
template <class T>
class Queue {
 public:
  Queue() : container(new SinglyList<T>()) {}
  Queue(const Queue& copy) { container = copy.container; }

  ~Queue() { delete container; }

  /**
   * @brief add item to the queue
   *
   * @param item item to add
   */
  void Enqueue(T item) { container->InsertAtBack(item); }

  /**
   * @brief remove an item from the queue (i.e. front)
   *
   */
  void Dequeue() { container->DeleteAtFront(); }

  /**
   * @brief Get the item from the head of the queue
   *
   * @return T
   */
  T Peek() { return container->GetHead()->data; }

  /**
   * @brief Returns the Size of the queue
   *
   * @return size_t number of items in the queue
   */
  size_t Size() const { return container->Size(); }

  /**
   * @brief Checks for the empty
   *
   * @return true if the size greater than 0
   * @return false otherwise
   */
  bool IsEmpty() { return Size() == 0 ? true : false; }

 private:
  // using linked list implementation for the underlying container
  SinglyList<T>* container;
};

#endif