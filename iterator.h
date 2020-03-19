#ifndef ITERATOR
#define ITERATOR

/**
 * @brief
 * Abstract Base class for iterators
 *
 * @tparam T Type of the iterator
 */
template <class T>
class Iterator {
 public:
  
  /**
   * @brief Iterator dtor
   *
   */
  virtual ~Iterator() { }
  
  /**
   * @brief overloaded increment operator
   *
   * @return Iterator<T>&
   */
  virtual Iterator<T>& operator++() = 0;

  /**
   * @brief overloaded increment operator
   *
   * @return Iterator<T>&
   */
  virtual Iterator<T>& operator++(int) = 0;
  
  /**
   * @brief overloaded equality operator
   * 
   * @param other istance of the other iterator
   * @return true if both iterators are same
   * @return false otherwise
   */
  virtual bool operator==(Iterator<T>& other) const = 0;
  
  /**
   * @brief overloaded not equality operator
   * 
   * @param other instance of the other iterator
   * @return true if both instances are same
   * @return false otherwise
   */
  virtual bool operator!=(Iterator<T>& other) const = 0;
  
  /**
   * @brief overloaded Dereference(*) operator
   * 
   * @return T& type of the iterator
   */
  virtual T& operator*() const = 0;
};

#endif