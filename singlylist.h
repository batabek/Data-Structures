#ifndef SINGLY_LIST
#define SINGLY_LIST

#include "iterator.h"
#include "linkedlist.h"

/**
 * @brief Template List Node class
 *
 * @tparam T type of the list node
 */
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

/**
 * @brief Singly List iterator
 *
 * @tparam Y type parameter
 */
template <class T>
class SinglyListIterator : public Iterator<T> {
 public:
  SinglyListIterator(SinglyNode<T> *node) : node_cur_(node) {}
  SinglyListIterator(const SinglyListIterator<T> &copy) {
    this->node_cur_ = copy.node_cur_;
  }

  ~SinglyListIterator() {}

  /**
   * @brief overloaded increment operator
   *        points to the next element in the list  
   * @return SinglyListIterator<T>& 
   */
  SinglyListIterator<T> &operator++() override {
    node_cur_ = node_cur_->next;
    return *this;
  }

  /**
   * @brief overloaded increment operator
   * 
   * @return SinglyListIterator<T>& 
   */
  SinglyListIterator<T>& operator++(int) override {
    node_cur_ = node_cur_->next;
    return *this;
  }

  bool operator==(Iterator<T> &other) const override {
    return node_cur_ == dynamic_cast<SinglyListIterator&>(other).node_cur_;
  }

  bool operator!=(Iterator<T> &other) const override {
    return node_cur_ != dynamic_cast<SinglyListIterator&>(other).node_cur_;
  }

  T &operator*() const override { return node_cur_->data; }

 private:
  SinglyNode<T> *node_cur_;
};



/**
 * @brief Template Linked List Class
 *
 * @tparam T type of the linked list
 */
template <class T>
class SinglyList : public LinkedList<T> {
 public:
  SinglyList() : head(nullptr), tail(nullptr), len(0) {}
  ~SinglyList() {
    DestroyList();
    head = tail = nullptr;
  }

  /**
   * @brief Return the size of the list
   * 
   * @return size_t number of elements in the list
   */
  size_t Size() const override { return len; }

  /**
   * @brief Checks for the empty
   * 
   * @return true if the size greater than 0
   * @return false otherwise
   */
  bool IsEmpty() { return Size() == 0 ? true : false; }

  /**
   * @brief Insert the item at the front(head) of the list
   * 
   * @param item item to insert at front 
   */
  void InsertAtFront(T item) override;

  /**
   * @brief Insert the item at the back(tail) of the list
   * 
   * @param item item to insert at the front
   */
  void InsertAtBack(T item) override;

  /**
   * @brief Delete an item from the fron of the list
   * 
   */
  void DeleteAtFront() override;

  /**
   * @brief Delete an item from the back of the list
   * 
   */
  void DeleteAtBack() override;

  /**
   * @brief Searches the item in the list
   * 
   * @param item item to search for in the list
   * @return true if the item is found
   * @return false if the item is not found
   */
  bool Search(T item) const override;
  
  /**
   * @brief Searches the item in the list
   * 
   * @param item item to search for in the list
   * @return SinglyNode<T>* returns the found item if found, nullptr otherwise
   */
  SinglyNode<T> *Search(T item);

  /**
   * @brief Get the Head pointer of the list
   * 
   * @return SinglyNode<T>* returns a node pointer to head
   */
  SinglyNode<T> *GetHead() const { return head; }

  /**
   * @brief Get the Tail pointer of the list
   * 
   * @return SinglyNode<T>* returns a node pointer to the tail 
   */
  SinglyNode<T> *GetTail() const { return tail; }

  /**
   * @brief Get a list iterator to the beginning of the list
   * 
   * @return SinglyListIterator<T> 
   */
  SinglyListIterator<T> Begin() { return SinglyListIterator<T>(GetHead()); }
  
  /**
   * @brief Get a list iterator to the end of the list
   * 
   * @return SinglyListIterator<T> 
   */
  SinglyListIterator<T> End() { return SinglyListIterator<T>(GetTail()->next); }

 private:
  /**
   * @brief Helper method to release allocated nodes of the list
   * 
   */
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
    head->next = nullptr;
    tail = head;
    len++;
    return;
  }

  SinglyNode<T> *newNode = new SinglyNode<T>(item);
  newNode->next = nullptr;
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

  if (head != tail) {
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
  else {
    delete tail;
    head = tail = nullptr;
    len--;
  }
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