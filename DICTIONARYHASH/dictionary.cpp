//Michael Peters and Vincent Rettke
//CPSC223 01
//Programming Assignment 3
//September 24, 2018
//dictionary.cpp
// Specification of ADT Dictionary
//     data object: a bunch of texting abbreviations and their meanings
//     operations: create, destroy
//                 search the dictionary for an item given its text
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its text
//   associated operations: input and output

//*****************
//dropoff: mpeters4
//*****************

#include "dictionary.h"
#include <string>
#include <iostream>
using namespace std;

const int TABLESIZE = 11;

struct DictionaryRecord
{
	Item* hashTablePtr;
	int numberStored;
};

// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example
//       address    text       meaning
//          0        lol       laugh out loud
//          1        ttyl      talk to you later
// usage: outfile << myDictionary;
ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{
	output << "address" << "\t" << "text" << "\t" << "meaning" << endl;

	for (int i = 0; i < TABLESIZE; i++){
	 	output << i << "\t" <<rightHandSideDictionary.dictionaryPtr-> hashTablePtr[i] << endl;
 	}
 return output;
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
istream& operator>> (istream& input, Dictionary& rightHandSideDictionary)
{
  int numberOfEntries = 0;
  bool isAlreadyThere, isFull;

  input >> numberOfEntries;

  Item newItem;
  for(int i = 0; i < numberOfEntries; i++){
	  input >> newItem;
	  rightHandSideDictionary.addNewEntry(newItem, isFull, isAlreadyThere);
  }
  return input;
}

//constructor
//establishes dictionaryPtr for hash table
Dictionary::Dictionary()
{
	dictionaryPtr = new DictionaryRecord;
	dictionaryPtr-> numberStored = 0;
	dictionaryPtr-> hashTablePtr = new Item[TABLESIZE];

}

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
Dictionary::~Dictionary()
{
delete dictionaryPtr;
}

// searchs for a meaning with a given text
// pre targetText has been assigned
// post if an item with texting abbreviationthe same as targetText is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  myDictionary.searchForMeaning(targetText, anItem, isFound);
void Dictionary::searchForMeaning(const Key& targetText, Item& anItem, bool& isFound)
{
  isFound = false;
  int address = hashFunction(targetText);

	while ((not dictionaryPtr-> hashTablePtr[address].isEmpty()) and (not isFound))
	{
		if (targetText == dictionaryPtr-> hashTablePtr[address])
		{
			isFound = true;
			anItem = dictionaryPtr-> hashTablePtr[address];
			return;
		}
		address = (address + 1) % TABLESIZE;
	}
	isFound = false;
}

// inserts a new text' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object and newItem's text
//            is not already there  isFull is false and isAlreadyThere is false
//            and newItem is appropriately added
//       else either isFull is true or isAlreadyThere is true, depending
// usage: myDictionary.addNewEntry(myItem, isFull, isAlreadyThere);
void Dictionary::addNewEntry(const Item& newItem, bool& isFull, bool& isAlreadyThere)
{
	int address = hashFunction(newItem);
 	isFull = false;
 	isAlreadyThere = false;

	if(dictionaryPtr->numberStored == TABLESIZE)
    	isFull = true;

	while ((not isFull) and (not isAlreadyThere))
	{
    	if(dictionaryPtr->hashTablePtr[address].isEmpty()){
      		dictionaryPtr->hashTablePtr[address] = newItem;
      		dictionaryPtr->numberStored++;
    	}
    	else if(dictionaryPtr->hashTablePtr[address] == newItem){
    		isAlreadyThere = true;
    	}
    	else{
    		address = (address + 1) % TABLESIZE;
    	}
	}
}

// removes the item associated with a given text from the dictionary
// pre: targetText is assigned
// post: if Dictionary object is not empty and
//           targetText is found in Dictionary object, isFound is true
//           and the associated Item object (text and meaning) has been
//           removed from the Dictionary object
//       else isFound is false or isEmpty is true depending
// usage: myDictionary.deleteEntry(myText, isEmpty, isFound);
void Dictionary::deleteEntry(const Key& targetText, bool& isEmpty, bool& isFound)
{
	int address = hashFunction(targetText);

	if (dictionaryPtr-> hashTablePtr[address].isEmpty())
	{
		isFound = false;
		isEmpty = true;
		return;
	}

	while (!dictionaryPtr-> hashTablePtr[address].isEmpty())
	{
		if (targetText == dictionaryPtr-> hashTablePtr[address])
		{
			dictionaryPtr-> hashTablePtr[address].markIt();
			isFound = true;
			isEmpty = false;
			return;
		}
		address = (address + 1) % TABLESIZE;
	}
}

//checks to see if dictionary is empty
//pre: dictionary object exists
//post: returns either true or false
//usage: myDictionary.isEmpty()
bool Dictionary::isEmpty()
{
	if (dictionaryPtr-> numberStored == 0)
		return true;

	return false;

}

//returns number of entries in dictionary
//pre: dictionary object exists
//post: returns number of entries in dictionary
//usage: myDictionary.getNumberOfEntries()
int Dictionary::getNumberOfEntries()
{
	return dictionaryPtr-> numberStored;

}

//returns number of entries in dictionary
//pre: key object exists
//post: returns hashed value
//usage: hashFunction(key)
int Dictionary::hashFunction(const Key& theKey)
{
	return (theKey.convertToInteger() % TABLESIZE);
}
