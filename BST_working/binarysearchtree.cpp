// Specification of ADT Dictionary as ADT Binary Search Tree
//     data object: a bunch of texting abbreviations and their meanings
//     operations: create, destroy
//                 search the dictionary for an item given its text
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its text
//   associated operations: input and output
// filename binarysearchtree.cpp
// date October 24, 2018


#include "binarysearchtree.h"
#include <iostream>
using namespace std;

// recursive helper functions

//Releases memory for a binary tree
//pre: treep points to the root of a binary tree
//post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
//usage: destroyTree (mroot);
void destroySearchTree (TreeNode*& treep)
{
   if (treep != nullptr)
   {
	   destroySearchTree(treep -> leftChild);
	   destroySearchTree(treep -> rightChild);
	   delete treep;
	   treep = nullptr;
   }
}

void readTree(istream& infile, TreeNode* treep, int numberOfEntries)
{
	if (numberOfEntries > 0)
	{
		Item newguy;
		treep = new (nothrow) TreeNode(newguy, nullptr, nullptr);					//pointer to a new TreeNode with an empty item and nullptr children;
		readTree(infile, treep -> leftChild, numberOfEntries / 2);
		infile >> treep -> item;							//read from infile into treep's item;
		readTree(infile, treep -> rightChild, (numberOfEntries - 1) / 2);
	}
}


void inorderSearchTree (TreeNode* treep, ostream& output)
{
	if (treep != nullptr)
	{
		inorderSearchTree(treep -> leftChild, output);
		output << treep -> item << endl;
		inorderSearchTree(treep -> rightChild, output);
	}
}



// searches a binary search tree for a certain text
// pre: treep is assigned a pointer to a root node of a binary search tree
//      targetText is assigned
// post: if targetText is found in the tree whose root node is treep
//          then the item in the root node is copied into anItem and
//          returns true; otherwise, returns false
// usage: isFound = searchHelper(root, targetText, anItem);
bool searchHelper(TreeNode* treep, const Key& targetText, Item& anItem)
{
   if (treep != nullptr)
   {
      if (targetText == treep -> item)
      {
         anItem = treep -> item;
         return true;
      } else if (targetText < treep -> item) {
         return searchHelper(treep -> leftChild, targetText, anItem);
      } else {
         return searchHelper(treep -> rightChild, targetText, anItem);
      }
   } else {
      return false;
   }
}

void addHelper(TreeNode*& treep, const Item& newItem) throw(Exception)
{
   if (treep != nullptr)
   {
      if (newItem == treep -> item)
      {
         //throw Exception("already there");
	  } else if (newItem < treep -> item) {
         addHelper(treep -> leftChild, newItem);
      } else {
         addHelper(treep -> rightChild, newItem);
      }
   } else {
	   treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
	   if (treep == nullptr)
	   {
		   throw Exception("Binary search tree ");
	   }
   }
}

bool deleteHelper(TreeNode*& treep, const Key& targetText)
{
	if (treep != nullptr)
	{
		if (targetText == treep -> item)
		{
			if (treep->leftChild == nullptr and treep->rightChild == nullptr)
			{
				delete treep;
				treep = nullptr;
				return true;
			}
			else if(treep->leftChild != nullptr and treep->rightChild == nullptr)
			{
				TreeNode* delptr = treep;
				treep = delptr->leftChild;
				delptr->leftChild = nullptr;
				delete delptr;
				return true;
			}
			else if(treep->rightChild != nullptr and treep->leftChild == nullptr)
			{
				TreeNode* delptr = treep;
				treep = delptr->rightChild;
				delptr->rightChild = nullptr;
				delete delptr;
				return true;
			}
			else if(treep->rightChild != nullptr and treep->leftChild != nullptr)
			{
				TreeNode* delptr = treep;
				treep = delptr->rightChild;
				delptr->rightChild = nullptr;
				delete delptr;					//this needs to be fixed
				return true;
			}
			else
			{
				return true;
			}
		}
		else if (targetText < treep -> item)
		{
			return deleteHelper(treep -> leftChild, targetText);
		}
		else
		{
			return deleteHelper(treep -> rightChild, targetText);
		}
	}
	else
	{
		return false;
	}
}

// inputs items into a dictionary
// pre: input has been opened if it is a file
//      items are arranged in the following format
//      2
//      lol
//      laugh out loud
//      ttyl
//      talk to you later
// post: if there is room,
//       all items in the input have been stored in rightHandSideDictionary
// usage: infile >> myDictionary;
istream& operator>> (istream& input, BinarySearchTree& rightHandSideDictionary)
{
	Item newItem;
	input >> newItem;
	addHelper(rightHandSideDictionary.root, newItem);
	return input;
}

// creates a new dictionary
// post: BinarySearchTree object exists but is empty
// usage: BinarySearchTree myDictionary;
BinarySearchTree::BinarySearchTree()
{
 	root = nullptr;
	numberOfItems = 0;
}

// destroys a dictionary
// pre: BinarySearchTree object exists
// post: all memory for BinarySearchTree object has been freed
// usage: automatically done at the end of scope
BinarySearchTree::~BinarySearchTree()
{
	destroySearchTree(root);
}

// searchs for a meaning with a given text
// pre targetText has been assigned a value not already in the hash table
// post if an item with texting abbreviationthe same as targetText is found then
//          it returns true and theItem is that item
//       else it returns false
// usage  myDictionary.searchForMeaning(targetText, anItem);
bool BinarySearchTree::searchForMeaning(const Key& targetText, Item& anItem)
{
	return searchHelper(root, targetText, anItem);
}

// inserts a new text' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the BinarySearchTree object and newItem's text
//            is not already there then newItem is appropriately added
//       else it throws an exception for either a full dictionary or
//            a message that it is already there
// usage: myDictionary.addNewEntry(myItem);
void BinarySearchTree::addNewEntry(const Item& newItem) throw (Exception)
{
	addHelper(root, newItem);
	numberOfItems++;
}

// removes the item associated with a given text from the dictionary
// pre: targetText is assigned
// post: if BinarySearchTree object is not empty and
//           targetText is found in Dictionary object, isFound is true
//           and the associated Item object (text and meaning) has been
//           removed from the Dictionary object
//       else isFound is false or isEmpty is true depending
// usage: myDictionary.deleteEntry(myText);
void BinarySearchTree::deleteEntry(const Key& targetText) throw(Exception)
{
	deleteHelper(root, targetText);
}

//
//
//
//
//
//
//
void BinarySearchTree::inorderTraverse(ostream& output)
{
	output << "Number of Items: " << numberOfItems << endl;
	inorderSearchTree(root, output);
}


//
//
//
//
//
//
//
void BinarySearchTree::reBalance(istream& inFile, ostream& oFile)
{
	inorderSearchTree(root, oFile);
	readTree(inFile, root, numberOfItems);
}
