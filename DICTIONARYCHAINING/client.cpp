/*
Michael Peters and Nathan Flack
mpeters4
3 October 2018
Description: This is a client program that tests the member functions of abstract
data type Dictionary. This program is broken into functions that each test a different
member function. The program takes input from file in.dat to walk the user through each
function and show that each function works as documented.
*/

#include <iostream>
#include <fstream>
#include "item.h"
#include "dictionary.h"
using namespace std;

void testInputOperator(Dictionary& testDictionary, istream& inputFile);
void testAddNewEntry(Dictionary& testDictionary, istream& inputFile);
void testSearchForMeaning(Dictionary& testDictionary, istream& inputFile);
void testDeleteEntry(Dictionary& testDictionary, istream& inputFile);
void printDictionary(Dictionary& testDictionary);


int main()
{
    Dictionary testDictionary;
    fstream inputFile;

    inputFile.open("in.dat");

    // Reading in the first four items and inserting into the dictionary
    testInputOperator(testDictionary, inputFile);
    printDictionary(testDictionary);

    // Adding new entries using stack push
    testAddNewEntry(testDictionary, inputFile);
    testAddNewEntry(testDictionary, inputFile);
    testAddNewEntry(testDictionary, inputFile);
    printDictionary(testDictionary);

    testSearchForMeaning(testDictionary, inputFile);     // finds item on first look
    testSearchForMeaning(testDictionary, inputFile);     // finds item after passing through a copy stack

    // Deleting an entry
    testDeleteEntry(testDictionary, inputFile);
    printDictionary(testDictionary);

    testSearchForMeaning(testDictionary, inputFile);     //finds item after an item has been deleted

    inputFile.close();
    return 0;
}

void testInputOperator(Dictionary& testDictionary, istream& inputFile)
{
    cout << "--- Testing the input operator>> to read in entries from a file ---" << endl;
    inputFile >> testDictionary;
}

void testAddNewEntry(Dictionary& testDictionary, istream& inputFile)
{
    Item itemOne;
    bool isAlreadyThere;

    cout << "--- Testing addNewEntry function to add a new item using stack push ---" << endl;
    inputFile >> itemOne;

    testDictionary.addNewEntry(itemOne, isAlreadyThere);
}

void testSearchForMeaning(Dictionary& testDictionary, istream& inputFile)
{
    Key keyOne;
    Item itemOne;
    bool isFound;

    cout << "--- Testing searchForMeaning function to find the associated item ---" << endl;
    inputFile >> keyOne;

    cout << "Searching for key: " << keyOne << endl;
    testDictionary.searchForMeaning(keyOne, itemOne, isFound);

    if(isFound)
        cout << "Found: " << itemOne << endl << endl;
    else
        cout << "Not Found" << endl << endl;
}

void testDeleteEntry(Dictionary& testDictionary, istream& inputFile)
{
    Key keyOne;
    Item itemOne;
    bool isEmpty, isFound;

    cout << "--- Testing deleteEntry function to delete an item ---" << endl;
    inputFile >> keyOne;
	cout << "--- Deleting the " << keyOne << " item ---" << endl;
    testDictionary.deleteEntry(keyOne, isEmpty, isFound);
}

void printDictionary(Dictionary& testDictionary)
{
    cout << endl <<  "Printing the dictionary to the screen" << endl;
    cout << testDictionary << endl << endl;
}
