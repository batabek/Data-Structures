#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <functional>
#include <iostream>

// Simple BST with recursively implemented basic operations
template <typename T>
class BinarySearchTree {
  template <typename X>
  struct BinarySearchTreeNode {
   public:
    BinarySearchTreeNode() : left(nullptr), right(nullptr) {}
    BinarySearchTreeNode(T val) : left(nullptr), right(nullptr), data(val) {}

    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
    X data;
  };

  // pointer to the root node of the BST
  BinarySearchTreeNode<T>* root;
  // #ofnodes found in the tree
  unsigned int n;

  void deleteTree(BinarySearchTreeNode<T>* node) {
    if (node) {
      // delete children first then the node itself
      deleteTree(node->left);
      deleteTree(node->right);
      delete node;
    }
    root = nullptr;
  }

 public:
  BinarySearchTree() : root(nullptr), n(0) {}

  ~BinarySearchTree() {
    deleteTree(root);
    n = 0;
  }

  void insert(T value) { insertItem(root, value); }

  void insertItem(BinarySearchTreeNode<T>*& node, T value);
  BinarySearchTreeNode<T>* searchItem(T value);
  void deleteItem(T value);
  BinarySearchTreeNode<T>* min();
  BinarySearchTreeNode<T>* max();

  const unsigned int size() const { return n; }

  void inOrderWalk(BinarySearchTreeNode<T>* node,
                   std::function<void(T val)> nodefunc);
  void preOrderWalk(BinarySearchTreeNode<T>* node,
                    std::function<void(T val)> nodefunc);
  void postOrderWalk(BinarySearchTreeNode<T>* node,
                     std::function<void(T val)> nodefunc);

  BinarySearchTreeNode<T>* getRoot() const { return root; }
};

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
    T value) {
  return nullptr;
}

template <typename T>
void BinarySearchTree<T>::deleteItem(T value) {}

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
BinarySearchTree<T>::BinarySearchTreeNode<T>* BinarySearchTree<T>::min() {}

template <typename T>
BinarySearchTree<T>::BinarySearchTreeNode<T>* BinarySearchTree<T>::max() {}

#endif
