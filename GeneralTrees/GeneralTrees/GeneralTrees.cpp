
#include <iostream>
#include "TreeNode.h"
#include <vector>


using namespace std;
int main()
{
   
	srand(static_cast<unsigned>(time(nullptr))); 

	TreeNode<int> root(std::rand() % 100 + 1); //root node with a random value between 1 and 100.


	//child nodes with random values between 1 and 100.
	TreeNode<int> node2(std::rand() % 100 + 1);
	TreeNode<int> node3(std::rand() % 100 + 1);

	//inserting child nodes into root node.
	root.insertChild(&node2);
	root.insertChild(&node3);

	TreeNode<int> node4(std::rand() % 100 + 1);
	TreeNode<int> node5(std::rand() % 100 + 1);

	node2.insertChild(&node4);
	node2.insertChild(&node5);

	TreeNode<int> node6(std::rand() % 100 + 1);

	node3.insertChild(&node6);

	cout << "Depth-First Preorder Traversal: ";
	root.depthFirstPreorder();
	cout << endl;

	//printing the depth and size of the tree.
	cout << "Depth: " << root.depth() << endl;
	cout << "Size: " << root.size() << endl;

	return 0;
}

