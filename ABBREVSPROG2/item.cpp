
// Michael Peters
// Nathan Flack
// CPSC223 01
// Homework Assignment 2
// September 14, 2018

//    *****************
//    dropoff: mpeters4
//    *****************

// Specification of ADT Item where
//     an Item is-a Key  (technical computer science)
//     class Item is a derived or child class of class Key

//     data object: a meaning of a texting abbreviation
//     operations: create, destroy, copy create, copy
//                 input, output


#include "item.h"

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

istream& operator>> (istream& input, Item& rightHandSideItem){
  char newline;

  input >> rightHandSideItem.textingAbbreviation;
  input.get(newline);
  getline(input,rightHandSideItem.textingMeaning);

  return input;
}

//allows for the output of an item to the standard output device or a file
//pre rightHandSideItem has been filled with a texting abbreviation and
//    its associated meaning
//    output has been opened
//post rightHandSideItem has been written to the output device
//     lol:  laugh out loud
//
//usage  outfile << myItem;
ostream& operator<< (ostream& output, const Item& rightHandSideItem){
  output << rightHandSideItem.textingAbbreviation << ": " << rightHandSideItem.textingMeaning << endl;

  return output;
}

//creates an empty item (texting abbreviation and its associated meaning)
//post
//usage Item aitem;
Item::Item(){

}

//releases memory for a texting abbreviation and its associated meaning
//pre Item object exists
//post Item object no longer exists, memory has been freed
//usage automatically done at the end of scope
Item::~Item(){

}

//creates a new item and copies the right hand side item into item
//pre Item object exists
//post rightHandSideItem is copied into new item
//usage  Item myItem(yourItem);
Item::Item(const Item& rightHandSideItem){
  textingMeaning = rightHandSideItem.textingMeaning;
  textingAbbreviation = rightHandSideItem.textingAbbreviation;
}

//copies rightHandSideItem's member variables into an existing item
//pre Item object exists
//post Item object contains the member variables from rightHandSideItem
//usage exampleItem = secondItem;
Item& Item::operator=(const Item& rightHandSideItem){
  if(this != &rightHandSideItem)
    textingAbbreviation = rightHandSideItem.textingAbbreviation;
    textingMeaning = rightHandSideItem.textingMeaning;
  return *this;
}
