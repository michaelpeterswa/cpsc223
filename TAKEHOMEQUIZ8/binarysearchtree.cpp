/*
Michael Peters
mpeters4
1 October 2018
Description: This is the implementation file for abstract data type BinarySearchTree. This file
contains function headers and bodies for the class Dictionary's methods as well as documentation
for each function. This data object is a Dictionary which stores Stacks of Items in a hash table. The class
has methods that create, destroy, search for a meaning, insert a new item, remove item, input,
output, and return number of entries.

******************
dropoff: mpeters4
******************

pseudocode of readTree algorithm that rebalances a binary search tree
you decide how to pass parameter treep
pre: infile has items with keys in sorted order
void readTree(ifstream& infile, TreeNode* or TreeNode*& treep, int numberOfEntries)
{
   if (numberOfEntries > 0)
   {
      treep = pointer to a new TreeNode with an empty item and nullptr children;
      readTree(infile, treep -> leftChild, numberOfEntries / 2);
      read from infile into treep's item;
      readTree(infile, treep -> rightChild, (numberOfEntries - 1) / 2;
   }
}


*/

#include "binarysearchtree.h"
#include "exception.h"
#include <iomanip>
using namespace std;

bool searchHelper(TreeNode* treep, const Key& targetText, Item& anItem) throw (Exception){
    if (treep != nullptr){
        if(targetText == treep -> item){
            anItem = treep -> item;
            return true;
        }else if (targetText < treep -> item){
            return searchHelper(treep -> leftChild, targetText, anItem);
        }else
            return searchHelper(treep -> rightChild, targetText, anItem);
    }

void addNewHelper(TreeNode* treep, const Item& anItem) throw (Exception){
    if (treep != nullptr){
        if(targetText == treep -> item){
            anItem = treep -> item;
        }else if (targetText < treep -> item){
            addNewHelper(treep -> leftChild, anItem);
        }else
            addNewHelper(treep -> rightChild, anItem);
    }
treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
} //figure out where to throw if already there and if full

// searchs for a meaning with a given text
// pre targetText has been assigned a value not already in the hash table
// post if an item with texting abbreviationthe same as targetText is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  myTree.searchForMeaning(root, targetText, anItem, isFound){;
void BinarySearchTree::searchForMeaning(TreeNode* treeRoot, const Key& targetText, Item& anItem) throw (Exception){
    searchHelper(treeRoot, targetText, anItem);
}

// inserts a new text' item into the BinarySearchTree
// pre: newItem has been assigned and is not already in the BinarySearchTree
// post: if there is room in the BinarySearchTree object and newItem's text
//            is not already there and isAlreadyThere is false
//            and anItem is appropriately added
//       else either isFull is true or isAlreadyThere is true, depending
// usage: myTree.addNewEntry(myItem, isAlreadyThere);
void BinarySearchTree::addNewEntry(const Item& newItem, bool& isAlreadyThere) throw (Exception){
    addNewHelper(root, newItem);
}

// removes the item associated with a given text from the dictionary
// pre: targetText is assigned
// post: if BinarySearchTree object is not empty and
//           targetText is found in BinarySearchTree object, isFound is true
//           and the associated Item object (text and meaning) has been
//           removed from the BinarySearchTree object
//       else isFound is false or isEmpty is true depending
// usage: myTree.deleteEntry(myText, isEmpty, isFound);
void BinarySearchTree::deleteEntry(const Key& targetText, bool& isEmpty, bool& isFound){
}

//returns number of entries in the tree
int BinarySearchTree::returnEntries(){
    return numberOfEntries;
}
