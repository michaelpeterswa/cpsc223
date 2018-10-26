// file binarytree.cpp
// Nathan Flack and Michael Peters
//----------
// mpeters4
//----------
// October 14, 2018

// Specification of ADT Binary Tree
//    Data object: A binary tree T that is either empty or in the form
//                 Full or Complete
//data structure: a linked binary tree
//
//operations:
// copyTree()
// destroyTree()
// writePretty()
// makeFullTreeHeight3()
// makeCompleteTreeHeight4()
// prettyDisplay()
// overridden operator=
// copy constructor
// order sorting
// order sorting traversal helpers

#include "binarytree.h"
#include <iostream>
using namespace std;

// ***************** recursive helpers *****************

//Copies one binary tree to another
//pre oldtreep points to the root of a binary tree
//post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
//usage: copyTree (newptr, oldptr);
void copyTree (TreeNode*& newtreep, TreeNode* oldtreep) throw (Exception)
{
	if (oldtreep != nullptr)
	{
		newtreep = new (nothrow) TreeNode(oldtreep->item, nullptr, nullptr);
		if (newtreep == nullptr)
		{
			throw Exception("in BinaryTree: in copyTree: no memory in heap for newtreep");
		}
		copyTree(newtreep->leftChild, oldtreep->leftChild);
		copyTree(newtreep->rightChild, oldtreep->rightChild);
	}
}

//Releases memory for a binary tree
//pre: treep points to the root of a binary tree
//post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
//usage: destroyTree (mroot);
void destroyTree(TreeNode*& treep)
{
	if(treep != nullptr)
	{
		destroyTree(treep->leftChild);
		destroyTree(treep->rightChild);
		delete treep;
		treep = nullptr;
	}
}

// recursive helper for prettyDisplay
// helps to print the tree to look like a computer science tree
// post: recursively sorts the tree using a method other than preorder, postorder, and inorder
// usage: writePretty(treep, root);
void writePretty (TreeNode* treep, int level)
{
	Key copyKey;
	if (treep != nullptr)
	{
		writePretty(treep -> rightChild, level + 1);

		for(int i = 0; i < level; i++)
		{
			if(level == 1){
				cout << "root -> ";
			}
			else
				cout << "\t";
		}
		copyKey = treep -> item;
		cout << copyKey << " <"<< endl;
		writePretty(treep -> leftChild, level + 1);
	}// not preorder, not inorder, not postorder
}

// ********** recursive helpers for the traversals ****************
//pre: treep points to the root of a binary tree to be traversed
//post: prints the item objects in the nodes on the screen in the
//     specified order. the items are separated by commas
//usage: preorder (mroot);
//       similarly for the others
void preorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		cout << treep -> item << "," << endl;
		preorder(treep -> leftChild);
		preorder(treep -> rightChild);
	}
}

void inorder (TreeNode* treep, ostream& output)
{
	if (treep != nullptr)
	{
		inorder(treep -> leftChild);
		output << treep -> item << "," << endl;
		inorder(treep -> rightChild);
	}
}


void postorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		postorder(treep -> leftChild);
		postorder(treep -> rightChild);
		cout << treep -> item << "," << endl;
	}
}

// **************************public methods************************

//creates an empty binary tree
//post: object is an empty binary tree
//usage: BinaryTree zags;
BinaryTree::BinaryTree()
{
   root = nullptr;
}

//creates a new binary tree that is a copy of an existing tree
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: BinaryTree zags (bulldog);
BinaryTree::BinaryTree(const BinaryTree& rightHandSideTree) throw (Exception)
{
   root = nullptr;
   copyTree(root, rightHandSideTree.root);
}

//releases the memory of a binary tree
//pre: object exists
//post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
BinaryTree::~BinaryTree()
{
   destroyTree(root);
}

// ******************** member functions ********************************************
//@pre: binary tree object exists
// **********************************************************************************

//checks for an empty tree
//post: returns true if the object is empty; else returns false
//usage: if (tree.isEmpty())
bool BinaryTree::isEmpty() const
{
   return (root == nullptr);
}

//copies one tree to another
//pre: rightHandSideTree is an assigned tree.
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: atree = btree = ctree;
BinaryTree& BinaryTree::operator=(const BinaryTree& rightHandSideTree) throw (Exception)
{
	if (this != &rightHandSideTree)
   {
	   	destroyTree(root);
		copyTree(root, rightHandSideTree.root);
   }
   return *this;
}

//prints the tree to look like a computer science tree
//post: outputs the tree as in the example below
//
//                       / bar
//                 / foo
//                       \ geeU
//  root ->  queue
//                       / stack
//                 \ list
//                       \ array
//nodes at the same level are indented the same.
//Viewer must rotate head 90 degrees in order to look like a cs tree
//usage: tree.prettyDisplay();
void BinaryTree::prettyDisplay()
{
	writePretty(root, 1);
}

// *************** on the following traversals

//post: prints the objects in the tree in order specified
//usage: tree.preorderTraverse();
//similarly for the other traversals
// *****************************************************

//preorder traversal
//post: prints the objects in the preorder
//usage: tree.preorderTraverse();
void BinaryTree::preorderTraverse ()
{
   preorder(root);
}

//inorder traversal
//post: prints the objects in the inorder
//usage: tree.inorderTraverse();
void BinaryTree::inorderTraverse(ostream& output)
{
	inorder(root, output); //change headers
}

//postorder traversal
//post: prints the objects in the postorder
//usage: tree.postorderTraverse();
void BinaryTree::postorderTraverse()
{
	postorder(root);
}

//makes a full binary tree of height 3
//pre input is either cin or an open file
//    input's pointer is before the first item
//post: object is a full binary tree of height 3
//throws an exception if there is not enough room in the
//       heap to make the tree
//usage: makeFullTreeHeight3(infile);
void BinaryTree::makeFullTreeHeight3(istream& input) throw (Exception)
{
	Item newguy;

	input >> newguy;
	root = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root == nullptr)
		throw Exception("in BinaryTree: no memory available in heap for root item");

	input >> newguy;
	root -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->leftChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for leftChild");

	input >> newguy;
	root -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->rightChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for rightChild");

	input >> newguy;
	root -> leftChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->leftChild->leftChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for left leftChild");

	input >> newguy;
	root -> leftChild-> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->leftChild-> rightChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for left right Child");

	input >> newguy;
	root -> rightChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->rightChild->leftChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for right left Child");

	input >> newguy;
	root-> rightChild-> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root-> rightChild-> rightChild == nullptr)
		throw Exception("in BinaryTree: no memory available in heap for right right item");

}

//makes a complete but not full binary tree of height 4
//Only inputs 9 items, static function
//throws an exception if there is not enough room in the
//       heap to make the tree
//also throws specific exception due to project reqs
//	will throw when there is room left in heap
//usage: makeCompleteTreeHeight4(infile);
void BinaryTree::makeCompleteTreeHeight4(istream& input) throw (Exception)
{
	Item newguy;

	input >> newguy;
	root = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root == nullptr)
		throw Exception("in BinaryTree: no memory available in heap for root item");

	input >> newguy;
	root -> leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->leftChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for leftChild");

	input >> newguy;
   	root -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
   	if(root->rightChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for rightChild");

	input >> newguy;
	root -> leftChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->leftChild->leftChild == nullptr)
    	throw Exception("in BinaryTree: no memory from heap available for left leftChild");

	input >> newguy;
	root -> leftChild-> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->leftChild-> rightChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for left right Child");

	input >> newguy;
	root -> rightChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->rightChild->leftChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for right left Child");

    input >> newguy;
    root-> rightChild-> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if(root-> rightChild-> rightChild == nullptr)
   		throw Exception("in BinaryTree: no memory available in heap for right right item");

	input >> newguy;
	root -> leftChild->leftChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->leftChild->leftChild->leftChild == nullptr)
	    throw Exception("in BinaryTree: no memory from heap available for left left leftChild");

	input >> newguy;
	root -> leftChild->leftChild->rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root->leftChild->leftChild->rightChild == nullptr)
		throw Exception("in BinaryTree: no memory from heap available for left left rightChild");

	if(root->leftChild->leftChild->rightChild != nullptr)
		throw Exception("I am throwing an exception at you, Dr. Y. Do you have your catcher’s mitt ready?");
}
