#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template<class T>
class BinarySearchTree
{
	public: 
		BinarySearchTree();
	private:
		class BinarySearchTreeNode {
			public:
				BinarySearchTreeNode();
			private:
				BinarySearchTreeNode* left;
				BinarySearchTreeNode* right;
				T data;
			
		};

};

#endif	
