//filename item.cpp
//author  Harley Davis and Vincent Rettke
//date September 16, 2018
//Dropped off by: vrettke

// Implementation of ADT Item wherex
//     an Item is-a Key  (technical computer science)
//     class Item is a derived or child class of class Key

//     data object: a meaning of a texting abbreviation
//     operations: create, destroy, copy create, copy
//                 input, output

#include "item.h" 
using namespace std;

 
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
istream& operator>> (istream& input, Item& rightHandSideItem)
{
	char newline;
	input >> rightHandSideItem.textingAbbreviation;
	input.get(newline);
	getline(input, rightHandSideItem.textingMeaning);
}
 
//allows for the output of an item to the standard output device or a file
//pre rightHandSideItem has been filled with a texting abbreviation and
//    its associated meaning 
//    output has been opened
//post rightHandSideItem has been written to the output device
//     lol:  laugh out loud
// 
//usage  outfile << myItem;
ostream& operator<< (ostream& output, const Item& rightHandSideItem)
{
	output << rightHandSideItem.textingAbbreviation << ": " << rightHandSideItem.textingMeaning;
}


//creates an empty item (texting abbreviation and its associated meaning)
//post an empty item is created in memory
//usage Item aitem;
Item::Item()
{
	
}

//releases memory for a texting abbreviation and its associated meaning
//pre Item object exists
//post Item object no longer exists, memory has been freed
//usage automatically done at the end of scope
Item::~Item()
{
	
}

//creates a new item and copies the right hand side item into item
//pre rightHandSideItem has been filled with a texting abbreviation and
//    its associated meaning 
//post Item object has a copy of rightHandSideItem
//usage  Item myItem(yourItem);
Item::Item(const Item& rightHandSideItem)
{
	textingMeaning = rightHandSideItem.textingMeaning;
	textingAbbreviation = rightHandSideItem.textingAbbreviation;
}

//
//pre both Item exists and rightHandSideItem exists and
// 		fill with texting abbreviation and it's assoc meaning
//post info from rightHandSideItem is copied to item.
//usage myItem = yourItem;
Item& Item::operator=(const Item& rightHandSideItem)
{
	if ( this != &rightHandSideItem )
	{		
		textingMeaning = rightHandSideItem.textingMeaning;
		textingAbbreviation = rightHandSideItem.textingAbbreviation;
	}
}

bool Item::isEmpty()
{
	return textingAbbreviation == "";
}

void Item::markIt()
{
	textingAbbreviation = "marked";
	textingMeaning = "";
}
