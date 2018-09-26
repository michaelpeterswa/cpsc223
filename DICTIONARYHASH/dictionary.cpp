//Michael Peters and Vincent Rettke
//CPSC223 01
//Programming Assignment 3
//September 24, 2018
//dictionary.cpp
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

ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{
	output << "address" << "\t" << "text" << "\t" << "meaning" << endl;

	for (int i = 0; i < TABLESIZE; i++){
	 output << i << "\t" <<rightHandSideDictionary.dictionaryPtr-> hashTablePtr[i] << endl;
 }
 return output;

}

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

Dictionary::Dictionary()
{
	dictionaryPtr = new DictionaryRecord;
	dictionaryPtr-> numberStored = 0;
	dictionaryPtr-> hashTablePtr = new Item[TABLESIZE];

}

Dictionary::~Dictionary()
{

}

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

void Dictionary::addNewEntry(const Item& newItem, bool& isFull, bool& isAlreadyThere)
{
	int address = hashFunction(newItem);
  isFull = false;
  isAlreadyThere = false;
  bool wasEntered = false;

  if(dictionaryPtr->numberStored == TABLESIZE)
    isFull = true;

	while ((not isFull) and (not wasEntered) and (not isAlreadyThere))
	{
    if(dictionaryPtr->hashTablePtr[address].isEmpty()){
      dictionaryPtr->hashTablePtr[address] = newItem;
      dictionaryPtr->numberStored++;
      wasEntered = true;
    }
    else if(dictionaryPtr->hashTablePtr[address] == newItem){
      isAlreadyThere = true;
    }
    else{
      address = (address + 1) % TABLESIZE;
    }
	}
}

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

bool Dictionary::isEmpty()
{
	if (dictionaryPtr-> numberStored == 0)
		return true;

	return false;

}

int Dictionary::getNumberOfEntries()
{
	return dictionaryPtr-> numberStored;

}

int Dictionary::hashFunction(const Key& theKey)
{
	return (theKey.convertToInteger() % TABLESIZE);
}
