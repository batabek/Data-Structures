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

  void Enqueue(T item) { container->InsertAtBack(item); }

  void Dequeue() { container->DeleteAtFront()(); }

  T Peek() { return container->GetTail()->data; }

  size_t GetSize() const { return container->GetSize(); }

 private:
  // using linked list implementation for the underlying container
  SinglyList<T>* container;
};

#endif