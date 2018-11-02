//file treenode.h
//author Dr. Y
//date October 8, 2018

//ADT TreeNode for a binary tree: data object a node with 
//                            an item and a pointer to left and right children
// operations: constructors
// Especially designed for the BinaryTree class

#ifndef TREENODE_H
#define TREENODE_H

#include <cstdlib>
#include "item.h"
using namespace std;

class TreeNode
{
public:
 
//YOU DO     
TreeNode();

//YOU DO
TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight);
   
Item item;
TreeNode* leftChild;
TreeNode* rightChild;

};
#endif


