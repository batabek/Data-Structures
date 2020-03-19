#ifndef LINKED_LIST
#define LINKED_LIST

#include <cstddef>

/**
 * @brief Abstract Base Class for List Containers
 * 
 * @tparam T Type parameter
 */
template <class T>
class LinkedList {
 public:
  virtual ~LinkedList() { }
  /**
   * @brief returns the size of the list container
   * 
   * @return size_t size of the container
   */
  virtual size_t Size() const = 0;

  /**
   * @brief Inserts the item at the front
   * 
   * @param item item to insert 
   */
  virtual void InsertAtFront(T item) = 0;
  
  /**
   * @brief Inserts the item at the back
   * 
   * @param item item to insert
   */
  virtual void InsertAtBack(T item) = 0;
  
  /**
   * @brief Deletes one item from the front
   * 
   */
  virtual void DeleteAtFront() = 0;
  
  /**
   * @brief Deletes one item from the back
   * 
   */
  virtual void DeleteAtBack() = 0;

  /**
   * @brief Searches for an item 
   * 
   * @param item item to search for
   * @return true if the item is found
   * @return false othwerwise
   */
  virtual bool Search(T item) const = 0;
};

#endif