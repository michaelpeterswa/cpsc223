// Implementation of ADT TreeNode

#include "treenode.h"


TreeNode::TreeNode()
{
   leftChild = nullptr;
   rightChild = nullptr;
}

TreeNode::TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight)
{
   item = newItem;
   leftChild = theLeft;
   rightChild = theRight;
}
