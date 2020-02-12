#ifndef SINGLY_LIST
#define SINGLY_LIST

#include "linkedlist.h"

template <class T>
class SinglyNode {
 public:
  SinglyNode() : next(nullptr) {}
  SinglyNode(T item) : data(item), next(nullptr) {}

  // private:
  T data;
  SinglyNode<T>* next;

  // friend class SinglyList;
};

template <class T>
class SinglyList : public LinkedList<T> {
 public:
  SinglyList() : head(nullptr), tail(nullptr), len(0) {}
  ~SinglyList() {
    destroyList();
    head = tail = nullptr;
  }

  size_t Size() const override { return len; }
  void InsertAtFront(T item) override;
  void InsertAtBack(T item) override;
  void DeleteAtFront() override;
  void DeleteAtBack() override;
  bool Search(T item) const override;

  SinglyNode<T>* GetHead() const { return head; }
  SinglyNode<T>* GetTail() const { return tail; }

 private:
  // helper methods go here
  void destroyList();

  SinglyNode<T>* head;
  SinglyNode<T>* tail;
  size_t len;
};

template <class T>
void SinglyList<T>::destroyList() {}

template <class T>
void SinglyList<T>::InsertAtFront(T item) {
  if (head == nullptr) {
    head = new SinglyNode<T>(item);
    tail = head;
    return;
  } else {
    SinglyNode<T>* newNode = new SinglyNode<T>(item);
    newNode->next = head;
    head = newNode;
  }
}

template <class T>
void SinglyList<T>::InsertAtBack(T item) {}

template <class T>
void SinglyList<T>::DeleteAtFront() {}

template <class T>
void SinglyList<T>::DeleteAtBack() {}

template <class T>
bool SinglyList<T>::Search(T item) const {
  return true;
}

#endif