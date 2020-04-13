#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <functional>
#include <iostream>

#include "stack.h"

// Simple BST with recursively implemented basic operations
template <typename T>
class BinarySearchTree {
  // Tree Node Template Class
  template <typename X>
  class BinarySearchTreeNode {
   public:
    BinarySearchTreeNode() : left(nullptr), right(nullptr) {}
    BinarySearchTreeNode(T val) : left(nullptr), right(nullptr), data(val) {}
    BinarySearchTreeNode(const BinarySearchTreeNode<T>& node) {
      data = node.data;
      left = node.left;
      right = node.right;
    }

    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
    X data;
  };

  // root node of the tree
  BinarySearchTreeNode<T>* root;
  // number of nodes found in the tree
  unsigned int n;

  void insertItem(BinarySearchTreeNode<T>*& node, T value);
  // iterative insert func.
  void insertItem(T value);

  BinarySearchTreeNode<T>* searchItem(BinarySearchTreeNode<T>* node, T value);

  void deleteTree(BinarySearchTreeNode<T>* node) {
    if (node) {
      // delete children first then the node itself
      deleteTree(node->left);
      deleteTree(node->right);
      delete node;
    }
    root = nullptr;
  }

  void deleteNode(BinarySearchTreeNode<T>*& node, T val);

 public:
  BinarySearchTree() : root(nullptr), n(0) {}
  ~BinarySearchTree() {
    deleteTree(root);
    n = 0;
  }

  void insert(T value) { insertItem(value); /*insertItem(root, value);*/ }
  void deleteItem(T value) { deleteNode(root, value); }
  BinarySearchTreeNode<T>* search(T value) { return searchItem(root, value); }
  BinarySearchTreeNode<T>* findMin();
  BinarySearchTreeNode<T>* findMax();

  bool isEmpty() const { return size() == 0; }

  BinarySearchTreeNode<T>* getRoot() const { return root; }

  const unsigned int size() const { return n; }

  // Traversals
  void inOrderWalk(BinarySearchTreeNode<T>* node,
                   std::function<void(T val)> nodefunc);

  // iterative inorderwalk
  void inOrderWalk(std::function<void(T val)> nodefunc);

  void preOrderWalk(BinarySearchTreeNode<T>* node,
                    std::function<void(T val)> nodefunc);
  void postOrderWalk(BinarySearchTreeNode<T>* node,
                     std::function<void(T val)> nodefunc);
};

/**
 * @brief      Function to delete a node by searching for its key.
 *              3 possible options to check
 *              a) if the node is a leaf node, then simply delete it
 *              b) if the node has a left/right child, replace its key with the
 * child's c) if the node has both left and right child, replace its key with
 * its successor.
 * @param      node  The node
 * @param[in]  val   The key of the node to be deleted
 */
template <typename T>
void BinarySearchTree<T>::deleteNode(BinarySearchTreeNode<T>*& node, T val) {
  // if there is no node nothing to delete
  if (node == nullptr) {
    return;
  }

  if (val < node->data) {
    deleteNode(node->left, val);
  } else if (val > node->data) {
    deleteNode(node->right, val);
  } else if (node->left != nullptr && node->right != nullptr) {
    // find the successor of the right tree
    BinarySearchTreeNode<T>* cur = node->right;
    while (cur && cur->left != nullptr) {
      cur = cur->left;
    }
    // update node key with its successor
    node->data = cur->data;
    deleteNode(node->right, cur->data);
  } else {
    BinarySearchTreeNode<T>* temp = node;
    node = (node->left != nullptr) ? node->left : node->right;
    delete temp;
    n--;
  }
}

template <typename T>
void BinarySearchTree<T>::insertItem(BinarySearchTreeNode<T>*& node, T value) {
  // base case
  if (node == nullptr) {
    node = new BinarySearchTreeNode<T>(value);
    n++;
  }

  // recursive case
  if (value < node->data)
    insertItem(node->left, value);
  else if (value > node->data)
    insertItem(node->right, value);
}

template <typename T>
BinarySearchTree<T>::BinarySearchTreeNode<T>* BinarySearchTree<T>::searchItem(
    BinarySearchTreeNode<T>* node, T value) {
  // base case either hit to null link or found
  if (node == nullptr)
    return nullptr;
  else if (value == node->data)
    return node;

  if (value < node->data)
    return searchItem(node->left, value);
  else if (value > node->data)
    return searchItem(node->right, value);
}

template <typename T>
void BinarySearchTree<T>::inOrderWalk(BinarySearchTreeNode<T>* node,
                                      std::function<void(T val)> nodefunc) {
  if (node) {
    inOrderWalk(node->left, nodefunc);
    nodefunc(node->data);
    inOrderWalk(node->right, nodefunc);
  }
}

template <typename T>
void BinarySearchTree<T>::inOrderWalk(std::function<void(T val)> nodefunc) {
  Stack<BinarySearchTreeNode<T>*> stack;
  BinarySearchTreeNode<T>* cur = this->root;
  bool done = false;

  while (!done) {
    if (cur != nullptr) {
      stack.Push(cur);
      cur = cur->left;
    } else {
      if (!stack.IsEmpty()) {
        cur = stack.Peek();
        stack.Pop();
        nodefunc(cur->data);
        cur = cur->right;
      } else {
        done = true;
      }
    }
  }
}

template <typename T>
void BinarySearchTree<T>::preOrderWalk(BinarySearchTreeNode<T>* node,
                                       std::function<void(T val)> nodefunc) {
  if (node) {
    nodefunc(node->data);
    preOrderWalk(node->left, nodefunc);
    preOrderWalk(node->right, nodefunc);
  }
}

template <typename T>
void BinarySearchTree<T>::postOrderWalk(BinarySearchTreeNode<T>* node,
                                        std::function<void(T val)> nodefunc) {
  if (node) {
    postOrderWalk(node->left, nodefunc);
    postOrderWalk(node->right, nodefunc);
    nodefunc(node->data);
  }
}

template <typename T>
BinarySearchTree<T>::BinarySearchTreeNode<T>* BinarySearchTree<T>::findMin() {
  BinarySearchTreeNode<T>* cur = getRoot();

  // check for the null case first
  if (cur) {
    // then traverse to the left
    while (cur->left != nullptr) {
      cur = cur->left;
    }
  }
  return cur;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTreeNode<T>* BinarySearchTree<T>::findMax() {
  BinarySearchTreeNode<T>* cur = getRoot();

  // check for the null case first
  if (cur) {
    // then traverse to the right
    while (cur->right != nullptr) {
      cur = cur->right;
    }
  }
  return cur;
}

template <typename T>
void BinarySearchTree<T>::insertItem(T value) {
  BinarySearchTreeNode<T>*cur = getRoot(), *parent = nullptr;

  // find a proper leaf node to insert the new node
  while (cur) {
    parent = cur;
    if (value >= cur->data) {
      cur = cur->right;
    } else {
      cur = cur->left;
    }
  }

  // empty tree case
  if (parent == nullptr) {
    root = new BinarySearchTreeNode<T>(value);
  } else if (value < parent->data) {
    // attach to the left child of parent
    parent->left = new BinarySearchTreeNode<T>(value);
  } else {
    // attach to the right child of parent
    parent->right = new BinarySearchTreeNode<T>(value);
  }

  // increment element count
  n++;
}

#endif
