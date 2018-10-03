/*
Alex Giacobbi and Nathan Flack
agiacobbi
17 September 2018
Description: This is the implementation file for abstract data type Item. This file contains function headers and
bodies for the class Item's methods as well as documentation for each function. This data object is an Item which 
stores a texting abbreviation (inherited from Key) and an associated texting meaning. The class inherits functions 
and data members from class Key and has its own methods and friends that create, destroy, copy, assign, input, and 
output.
*/

#include "key.h"
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
istream& operator>> (istream& input, Item& rightHandSideItem)
{
    char newLine;

    input >> rightHandSideItem.textingAbbreviation;
    input.get(newLine);
    getline(input, rightHandSideItem.textingMeaning);

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
ostream& operator<< (ostream& output, const Item& rightHandSideItem)
{
    output << rightHandSideItem.textingAbbreviation << "\t" << rightHandSideItem.textingMeaning;
    return output;
}

//creates an empty item
//post Item object is an empty texting meaning
//usage Item itemA();
Item::Item()
{
   
}

//creates a specific texting meaning
//pre rightHandSideItem is an Item assigned a string that represents a texting meaning
//post Item object has a copy of the texting meaning in rightHandSideItem
//usage Item myItem(yourItem); 
Item::Item(const Item& rightHandSideItem)
{
    textingAbbreviation = rightHandSideItem.textingAbbreviation;
    textingMeaning = rightHandSideItem.textingMeaning;
}

//releases memory for a texting abbreviation
//pre Key object exists
//post Key object no longer exists, memory has been freed
//usage automatically done at the end of scope
Item::~Item()
{
   
}

//copies a texting meaning
//pre rightHandSideItem has been assigned a texting meaning
//post Item object has a copy of rightHandSideItem
//usage aItem = bItem;
Item& Item::operator=(const Item& rightHandSideItem)
{
    if (this != &rightHandSideItem) {
        textingAbbreviation = rightHandSideItem.textingAbbreviation;
        textingMeaning = rightHandSideItem.textingMeaning;
    }
    return *this;
}

//tells user if an item is empty
//pre none
//post  returns true if item abbreviation contains no text
//      else returns false
// usage: bool myBool = myItem.isEmpty();
bool Item::isEmpty()
{
    return (textingAbbreviation.empty());
}

//marks an item for deletion proccess in dictionary hash table
//pre item exists
//post item's texting abbreviation has been set to --- and meaning displays Item has been deleted
//usage myItem.mark();
void Item::mark()
{
    textingAbbreviation = "---";
    textingMeaning = "Item has been deleted";
}

//tells user if an item is marked
//pre none
//post returns true if item's texting abbreviation is ---
//     else returns false
//usage: bool myBool = myItem.isMarked();
bool Item::isMarked()
{
    return (textingAbbreviation == "---");
}
