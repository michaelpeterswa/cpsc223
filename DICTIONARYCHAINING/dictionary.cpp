/*
Michael Peters and Nathan Flack
mpeters4
1 October 2018
Description: This is the implementation file for abstract data type Dictionary. This file
contains function headers and bodies for the class Dictionary's methods as well as documentation
for each function. This data object is a Dictionary which stores Stacks of Items in a hash table. The class
has methods that create, destroy, search for a meaning, insert a new item, remove item, input,
output, check if dictionary is empty or full, and return number of entries.
*/

#include "dictionary.h"
#include "stack.h"
#include <iomanip>
using namespace std;

const int TABLESIZE = 11;

struct DictionaryRecord
{
   Stack* hashTablePtr;
   int numberStored;
};

int hashFunction(const Key& theText)
{
   return theText.convertToInteger() % TABLESIZE;
}

void printStack(Stack copyStack)
{
	Item topItem;
    while(!copyStack.isEmpty())
    {
    copyStack.getTop(topItem);
    cout << "\t->\t" << topItem << endl;
    copyStack.pop();
    }
}

// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example (caveat: these texts may hash to a different address)
//       address       text  meaning
//           0:
//                ->   lol   laugh out loud
//                ->   ttyl  talk to you later
//           1:
//                ->   smh   shake my head
// usage: outfile << myDictionary;
ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{
    output << "address\t\ttext\tmeaning" << endl;
    for (int i = 0; i < TABLESIZE; i++)
    {
		if(!rightHandSideDictionary.dictionaryPtr->hashTablePtr[i].isEmpty())// if the stack isnt empty
		{
        output << i << ":" << endl;
        printStack(rightHandSideDictionary.dictionaryPtr->hashTablePtr[i]);
		}
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
    Item itemInsert;
    int numberToInsert;
    bool isAlreadyThere;

    input >> numberToInsert;
    input.ignore();

    for (int i = 0; i < numberToInsert; i++)
    {
        input >> itemInsert;
        rightHandSideDictionary.addNewEntry(itemInsert, isAlreadyThere);
    }
    return input;
}

// creates a new dictionary
// post: Dictionary object exists but is empty
// usage: Dictionary myDictionary;
Dictionary::Dictionary()
{
   dictionaryPtr = new DictionaryRecord;
   dictionaryPtr -> numberStored = 0;
   dictionaryPtr -> hashTablePtr = new Stack [TABLESIZE];
}

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
Dictionary::~Dictionary()
{
   	delete [] dictionaryPtr -> hashTablePtr;
   	dictionaryPtr -> hashTablePtr = NULL;
   	delete dictionaryPtr;
	dictionaryPtr = NULL;
}

//
//
//
//
//
void searchTheStack(Stack copyStack, bool& isFound, const Key& targetText, Item& foundItem)  //might need to be in dictionary
{
	Item foundKey;
	isFound = false;
	while(!copyStack.isEmpty() && !isFound)
	{
		copyStack.getTop(foundItem);
		if (foundItem == targetText)
		{
			isFound = true;
		}
		else
		{
			copyStack.pop();
		}
	}
	return;
}

// searchs for a meaning with a given text
// pre targetText has been assigned
// post if an item with texting abbreviationthe same as targetText is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  myDictionary.searchForMeaning(targetText, anItem, isFound);
void Dictionary::searchForMeaning(const Key& targetText, Item& anItem, bool& isFound)
{
    int address = hashFunction(targetText);
	searchTheStack(dictionaryPtr->hashTablePtr[address], isFound, targetText, anItem);
}

// inserts a new text' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object and newItem's text
//            is not already there  isFull is false and isAlreadyThere is false
//            and newItem is appropriately added
//       else either isFull is true or isAlreadyThere is true, depending
// usage: myDictionary.addNewEntry(myItem, isAlreadyThere);
void Dictionary::addNewEntry(const Item& newItem, bool& isAlreadyThere)
{
	isAlreadyThere = false;
    int address = hashFunction(newItem);
	bool isAdded, isFound;
	Item foundItem;
	searchForMeaning(newItem, foundItem, isFound);
	if (isFound && (foundItem == newItem))
	{
		isAlreadyThere = true;
	}
	else
	{
		dictionaryPtr->numberStored += 1;
		dictionaryPtr->hashTablePtr[address].push(newItem, isAdded);
	}
	//cout << endl << dictionaryPtr->numberStored << endl; //unnecesary
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
	isFound = false;
	isEmpty = false;
    bool isAdded = false;
    int address = hashFunction(targetText);
	Item foundItem, compareItem;
    Stack copyStack;


	searchForMeaning(targetText, foundItem, isFound);
    while (not dictionaryPtr->hashTablePtr[address].isEmpty()) {
        if (isFound and (foundItem == targetText))
    	{
            dictionaryPtr->hashTablePtr[address].getTop(compareItem);
    		if(not (compareItem == targetText)){
                copyStack.push(compareItem, isAdded);
                dictionaryPtr->hashTablePtr[address].pop();
            }
            else{
                dictionaryPtr->hashTablePtr[address].pop();
            }
    	}
    }
    while (not copyStack.isEmpty()) {
        copyStack.getTop(compareItem);
        dictionaryPtr->hashTablePtr[address].push(compareItem, isAdded);
        copyStack.pop();
    }
}

// checks if the dictionary is empty
// pre: none
// post: if Dictionary object is empty function returns true
//       else function will return false
// usage: myDictionary.isEmpty();
// bool Dictionary::isEmpty()
// {
//     return (dictionaryPtr->numberStored == 0);
// }

// checks if the dictionary is full
// pre: none
// post: if Dictionary object is full function returns true
//       else function will return false
// usage: myDictionary.isFull();
// bool Dictionary::isFull()
// {
//     return (dictionaryPtr->numberStored == TABLESIZE);
// }

// tells user how many items are in dictionary object
// pre: none
// post: returns the number of entries in the dictionary as an integer
// usage: myDictionary.getNumberOfEntries();
// int Dictionary::getNumberOfEntries()
// {
//     return dictionaryPtr->numberStored;
// }
