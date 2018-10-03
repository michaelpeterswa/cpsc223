/*
Michael and Nathan Flack
mpeters4
25 September 2018
Description: This is the header file for abstract data type Item. This file contains function prototypes
and documentation for the methods of class Item. Item is a a derived class of class Key, so it can access
protected data members of class Key and inherits some functions. Abstract data type Item is the meaning of
a texting abbreviation stored in parent Key. This file contains protypes for member functions and friends
that handle the following operations: create, destroy, copy create, copy, input, and output.
*/

#ifndef ITEM_H
#define ITEM_H

#include "key.h"
using namespace std;

class Item: public Key
{

//allows for input of an item from either the standard input device or a file
//pre input has been opened and readied for the input of
//    a texting abbreviation followed by newline and associated meaning with
//    spaces between words ending with a newline. For example:
//    lol
//    laugh out loud
//
//post rightHandSideItem has been filled with a texting abbreviation and its
//     associated meaning
//usage cin >> myItem;
friend istream& operator>> (istream& input, Item& rightHandSideItem);

//allows for the output of an item to the standard output device or a file
//pre rightHandSideItem has been filled with a texting abbreviation and
//    its associated meaning
//    output has been opened
//post rightHandSideItem has been written to the output device
//     lol:  laugh out loud
//
//usage  outfile << myItem;
friend ostream& operator<< (ostream& output, const Item& rightHandSideItem);

public:

//creates an empty item (texting abbreviation and its associated meaning)
//post Item object is an empty texting meaning
//usage Item aitem;
Item();

//releases memory for a texting abbreviation and its associated meaning
//pre Item object exists
//post Item object no longer exists, memory has been freed
//usage automatically done at the end of scope
~Item();

//creates a new item and copies the right hand side item into item
//pre rightHandSideItem is an Item assigned a string that represents a texting meaning
//post Item object has a copy of the texting meaning in rightHandSideItem
//usage  Item myItem(yourItem);
Item(const Item& rightHandSideItem);

//copies a texting meaning
//pre rightHandSideItem has been assigned a texting meaning
//post Item object has a copy of rightHandSideItem
//usage aItem = bItem;
Item& operator=(const Item& rightHandSideItem);

//tells user if item is empty
//pre none
//post returns true if item contains no text
//     else returns false
//usage if(myItem.isEmpty())
bool isEmpty();

//marks item as deleted for use in dictionary hash table
//pre item exists
//post  item's texting abbreviation is marked --- and meaning
//      shows item has been deleted
//usage myItem.mark();
void mark();

//tells user if an item is marked as deleted
//pre none
//post  returns true if item's texting abbreviation is ---
//      else returns false
//usage bool myBool = myItem.isMarked();
bool isMarked();

private:
   string textingMeaning;
};
#endif
