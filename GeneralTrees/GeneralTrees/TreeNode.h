
#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

template <class T>
class TreeNode
{
public:
    T data;
    TreeNode* parent;
    std::vector<TreeNode*> children;

    TreeNode(T val) : data(val), parent(nullptr) //this is the constructor for the TreeNode class and no parent.
    {
    }

    void insertChild(TreeNode* child) //this function inserts a child to the node.
    {
        child->parent = this;
        children.push_back(child);
    }

    void deleteChild(TreeNode* child) //this function deletes a child from the node.
    {
        children.erase( std::remove(children.begin(), children.end(), child), children.end());
        delete child;
    }

    int size() //this calculates the size of the subtree rooted at this node.
    {
        int count = 1;
        for (TreeNode* child : children) 
        {
            count += child->size();
        }
        return count;
    }

    int depth() //this calculates the depth of the node in the tree.
    {
        int i = 0;
        TreeNode* current = parent;
        while (current != nullptr) 
        {
            i++;
            current = current->parent;
        }
        return i;
    }

    bool Leaf() //this checks if the node is a leaf, and has no children.
    {
        return children.empty();
    }

  
    void depthFirstPreorder() //this prints the nodes in the tree in depth-first preorder.
    {
        std::cout << data << " ";  
        for (TreeNode* child : children) 
        {
            child->depthFirstPreorder();  
        }
    }

};

