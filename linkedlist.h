#ifndef LINKED_LIST
#define LINKED_LIST

#include <cstddef>

template <class T>
class LinkedList {
 public:
  virtual ~LinkedList() {}

  virtual size_t Size() const = 0;
  virtual void InsertAtFront(T item) = 0;
  virtual void InsertAtBack(T item) = 0;
  virtual void DeleteAtFront() = 0;
  virtual void DeleteAtBack() = 0;
  virtual bool Search(T item) const = 0;
};

#endif