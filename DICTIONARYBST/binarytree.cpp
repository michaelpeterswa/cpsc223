//file binarytree.cpp
// Nathan Flack and Michael Peters
// October 14, 2018

//data object: a binary tree of linked treenodes that hold items
//data structure: a linked binary tree
//operations: constructor, destructor, isEmpty, operator=, prettyDisplay, preorderTraverse, postorderTraverse
// 			  inorderTraverse, makeCompleteTreeHeight4, makeFullTreeHeight3

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

//prints the tree to look like a computer science tree
//pre: treep points to the root of a tree. level >= 0
//post: outputs the tree as in the example below
//
//  					  bar
//                  foo
//                        geeU
//  root ->  queue
//                        stack
//                  list
//                        array
//nodes at the same level are indented the same.
//Viewer must rotate head 90 degrees in order to look like a cs tree
//usage: writePretty(root,0,cout);
void writePretty (TreeNode* treep, int level, ostream& output)
{
	if (treep != nullptr)
	{
		writePretty(treep -> rightChild, level += 1, output);
		if (treep -> rightChild != nullptr)
		{
			for (int j = 0;j <= level;j++)
				output << '\t';
			output << "/" << endl;
		}
		if (level == 1)
			output << "root ->" ;
		else
		{
			for (int i = 0; i < level; i++)
				output << '\t' ;
		}
		Key text = treep -> item;
		output << "  " << text << endl;
		 if (treep -> leftChild != nullptr)
        {
            for (int i = 0; i <= level; i++)
                output << '\t';
            output << "\\" << endl;
			writePretty(treep -> leftChild, level, output);
		}
	}
}

// ********** recursive helpers for the traversals ****************
//pre: treep points to the root of a binary tree to be traversed
//post: prints the item objects in the nodes on the screen in the
//     specified order. the items are separated by commas

// afk,
// btw,
// imo,
// bff,
// idc,
// noyb,
// diy,
// tyt,
// asap,

//usage: preorder (mroot);
//       similarly for the others
void preorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		Key treepKey = treep->item;
		cout << treepKey << "," << endl;
		preorder(treep -> leftChild);
		preorder(treep -> rightChild);
	}
}

void inorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		inorder(treep -> leftChild);
		Item treepItem = treep->item;
		cout << treepItem.getText() <<  endl;
		inorder(treep -> rightChild);
	}
}

void postorder (TreeNode* treep)
{
	if (treep != nullptr)
	{
		postorder(treep -> leftChild);
		postorder(treep -> rightChild);
		Key treepKey = treep->item;
		cout << treepKey << "," << endl;
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
//                        bar<
//                  foo<
//                        geeU<
//  root -> queue<
//                        stack<
//                  list<
//                        array<
//nodes at the same level are indented the same.
//Viewer must rotate head 90 degrees in order to look like a cs tree
//usage: tree.prettyDisplay();
void BinaryTree::prettyDisplay()
{
	writePretty(root, 1, cout);
}

// *************** on the following traversals

//post: prints the objects in the tree in order specified
//usage: tree.preorderTraverse();
//similarly for the other traversals
// *****************************************************
void BinaryTree::preorderTraverse ()
{
   preorder(root);
}

void BinaryTree::inorderTraverse()
{
	inorder(root);
}


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
//usage: myTree.makeFullTreeHeight3(infile);
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
	root-> rightChild -> rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
	if(root-> rightChild -> rightChild == nullptr)
		throw Exception("in BinaryTree: no memory available in heap for right right item");

}

//makes a complete binary tree of height 4
//pre input is either cin or an open file
//    input's pointer is before the first item
//post: object is a complete binary tree of height 4
//throws an exception if there is not enough room in the
//       heap to make the tree
//usage: myTree.makeCompleteTreeHeight4(infile);
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

	throw Exception("I am throwing an exception at you, Dr. Y. Do you have your catcher’s mitt ready?");
}
