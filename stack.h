#ifndef STACK
#define STACK

#include "singlylist.h"

/**
 * @brief Template Stack Container
 * 
 * @tparam T Type parameter
 */
template <class T>
class Stack {
 public:
  Stack() : container(new SinglyList<T>()) {}
  Stack(const Stack& copy) { container = copy.container; }

  ~Stack() { delete container; }
  /**
   * @brief Add item to the stack
   * 
   * @param item item to add
   */
  void Push(T item) { container->InsertAtBack(item); }

  /**
   * @brief Remove an item from the stack
   * 
   */
  void Pop() { container->DeleteAtBack(); }

  /**
   * @brief Get the item at the top of the stack
   * 
   * @return T type of the item
   */
  T Peek() { return container->GetTail()->data; }

  /**
   * @brief Get the Size object
   * 
   * @return size_t number of items in the stack
   */
  size_t Size() const { return container->Size(); }

 private:
  // using linked list implementation for the underlying container
  SinglyList<T>* container;
};

#endif
