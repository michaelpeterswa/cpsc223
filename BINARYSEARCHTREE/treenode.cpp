// Michael Peters and Nathan Flack
// Implementation of ADT TreeNode
// date October 14, 2018

//ADT TreeNode for a binary tree: data object a node with
//                            an item and a pointer to left and right children
// operations: constructors
// Especially designed for the BinaryTree class

#include "treenode.h"

//constructor for TreeNode object
//post: TreeNode exists
TreeNode::TreeNode()
{
   leftChild = nullptr;
   rightChild = nullptr;
}

//constructor with Data
//post: filled TreeNode exists
TreeNode::TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight)
{
   item = newItem;
   leftChild = theLeft;
   rightChild = theRight;
}
