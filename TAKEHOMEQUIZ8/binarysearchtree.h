// Specification of ADT BinarySearchTree
//     data object: a bunch of texting abbreviations and their meanings
//     operations: create, destroy
//                 search the dictionary for an item given its text
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its text
//   associated operations: input and output
// filename binarysearchtree.h
// date October 25, 2018

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarytree.h"

struct SearchTree;

class BinarySearchTree : public BinaryTree
{

public:

// creates a new BinarySearchTree
// post: BinarySearchTree object exists but is empty
// usage: BinarySearchTree mySearchTree;
BinarySearchTree();

// destroys a BinarySearchTree
// pre: BinarySearchTree object exists
// post: all memory for BinarySearchTree object has been freed
// usage: automatically done at the end of scope
~BinarySearchTree();

// searchs for a meaning with a given text
// pre targetText has been assigned a value not already in the hash table
// post if an item with texting abbreviationthe same as targetText is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  myTree.searchForMeaning(root, targetText, anItem, isFound){;
void searchForMeaning(TreeNode* root, const Key& targetText, Item& anItem, bool& isFound);

// inserts a new text' item into the BinarySearchTree
// pre: newItem has been assigned and is not already in the BinarySearchTree
// post: if there is room in the BinarySearchTree object and newItem's text
//            is not already there and isAlreadyThere is false
//            and anItem is appropriately added
//       else either isFull is true or isAlreadyThere is true, depending
// usage: myTree.addNewEntry(myItem, isAlreadyThere);
void addNewEntry(const Item& newItem, bool& isAlreadyThere);

// removes the item associated with a given text from the dictionary
// pre: targetText is assigned
// post: if BinarySearchTree object is not empty and
//           targetText is found in BinarySearchTree object, isFound is true
//           and the associated Item object (text and meaning) has been
//           removed from the BinarySearchTree object
//       else isFound is false or isEmpty is true depending
// usage: myTree.deleteEntry(myText, isEmpty, isFound);
void deleteEntry(const Key& targetText, bool& isEmpty, bool& isFound);

int returnEntries();

private:
    int numberOfEntries;
};


#endif
