#ifndef SINGLY_LIST
#define SINGLY_LIST

#include "linkedlist.h"

template <class T>
class SinglyNode {
 public:
  SinglyNode() : next(nullptr) {}
  SinglyNode(T item) : data(item), next(nullptr) {}
  SinglyNode(const SinglyNode<T> &copy) {
    data = copy.data;
    next = copy.next;
  }

  T data;
  SinglyNode<T> *next;
  // friend class SinglyList;
};

template <class T>
class SinglyList : public LinkedList<T> {
 public:
  SinglyList() : head(nullptr), tail(nullptr), len(0) {}
  ~SinglyList() {
    DestroyList();
    head = tail = nullptr;
  }

  size_t Size() const override { return len; }
  void InsertAtFront(T item) override;
  void InsertAtBack(T item) override;
  void DeleteAtFront() override;
  void DeleteAtBack() override;
  bool Search(T item) const override;
  SinglyNode<T> *Search(T item);

  SinglyNode<T> *GetHead() const { return head; }
  SinglyNode<T> *GetTail() const { return tail; }

 private:
  // helper methods go here
  void DestroyList();

  SinglyNode<T> *head;
  SinglyNode<T> *tail;
  size_t len;
};

template <class T>
void SinglyList<T>::DestroyList() {
  while (head != nullptr) {
    SinglyNode<T> *cur = head;
    head = head->next;
    delete cur;
    cur = nullptr;
  }
}

template <class T>
void SinglyList<T>::InsertAtFront(T item) {
  if (head == nullptr) {
    head = new SinglyNode<T>(item);
    tail = head;
    len++;
    return;
  } else {
    SinglyNode<T> *newNode = new SinglyNode<T>(item);
    newNode->next = head;
    head = newNode;
    len++;
  }
}

template <class T>
void SinglyList<T>::InsertAtBack(T item) {
  // both head & tails point to the null
  if (head == nullptr && tail == nullptr) {
    head = new SinglyNode<T>(item);
    tail = head;
    len++;
    return;
  }

  SinglyNode<T> *newNode = new SinglyNode<T>(item);
  tail->next = newNode;
  tail = newNode;
  len++;
}

template <class T>
void SinglyList<T>::DeleteAtFront() {
  if (head == nullptr) {
    return;
  }

  SinglyNode<T> *temp = head->next;
  delete head;
  head = temp;
  len--;
}

template <class T>
void SinglyList<T>::DeleteAtBack() {
  if (tail == nullptr) return;

  // find the predecessor of tail
  SinglyNode<T> *cur = head;
  while (cur && cur->next != tail) {
    cur = cur->next;
  }

  delete tail;
  cur->next = nullptr;
  tail = cur;
  len--;
}

template <class T>
SinglyNode<T> *SinglyList<T>::Search(T item) {
  SinglyNode<T> *cur = head;
  while (cur) {
    if (cur->data == item) {
      break;
    }
    cur = cur->next;
  }

  return cur;
}

template <class T>
bool SinglyList<T>::Search(T item) const {
  bool found = false;
  SinglyNode<T> *cur = head;
  while (cur) {
    if (cur->data == item) {
      found = true;
      break;
    }
    cur = cur->next;
  }

  return found;
}

#endif