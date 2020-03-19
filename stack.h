#ifndef STACK
#define STACK

#include "singlylist.h"

/**
 * @brief Template Stack Data Structure 
 * 
 * @tparam T Type parameter
 */
template <class T>
class Stack {
 public:
  Stack() : container(new SinglyList<T>()) {}
  Stack(const Stack& copy) { container = copy.container; }

  ~Stack() { delete container; }

  void Push(T item) { container->InsertAtBack(item); }

  void Pop() { container->DeleteAtBack(); }

  T Peek() { return container->GetTail()->data; }

  size_t GetSize() const { return container->GetSize(); }

 private:
  // using linked list implementation for the underlying container
  SinglyList<T>* container;
};

#endif
