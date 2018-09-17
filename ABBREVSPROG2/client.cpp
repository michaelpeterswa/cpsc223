/*
Michael Peters and Nathan Flack
CPSC223 01
Homework Assignment 2
Thursday, September 14, 2018

ADT Item (Texting Abbreviation and Meaning)
Specification file for ADT Item (Testing Abbreviation and Meaning)
   data object: a key or texting abbreviation and meaning (unique)
   operations: create an empty Item, destroy an Item
               read an Item from a file, write an Item to a file
               read an Item from the user, write an Item to the screen,
               convert an Item to a number (for what's coming in Dictionary)

filename: client.cpp

This program, client.cpp is designed to display the functions of the Item Class.

*/

#include "item.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {

  ifstream infile("in.dat"); //file input used for testing reading from file
  ofstream outfile("out.dat"); //file output used for testing writing to a file
  Item firstOne, thirdOne, fromFile;
  Key firstKey, fromFileKey;

  cout << "-----------------------" << endl;
  cout << "  INITIALIZE OBJECTS" << endl;
  cout << endl;
  cout << "created four Item objects (firstOne, thirdOne, fromFile)" << endl;
  cout << "created two Key objects (firstKey, fromFileKey)" << endl;
  cout << endl;

  cout << "-----------------------" << endl;
  cout << "  CLASS KEY TESTING" << endl;
  cout << endl;

  cout << "Enter a texting abbreviation for firstKey -> ";
  cin >> firstKey;
  cout << endl;
  cout << "reading from in.dat..." << endl;
  infile >> fromFileKey;
  cout << endl;
  cout << "fromFileKey -- " << fromFileKey << endl;
  cout << endl;

  cout << "writing firstKey to out.dat..." << endl;
  cout << endl;
  outfile << "firstKey -> " << firstKey << endl;


  cout << "testing class Key copy constructor..." << endl;
  cout << "copying firstKey to secondKey..." << endl;
  Key secondKey(firstKey);
  cout << endl;

  cout << "firstKey -- " << firstKey << endl;
  cout << "secondKey -- " << secondKey << endl;
  cout << endl;

  cout << "testing convertToInteger on Key firstKey..." << endl;
  cout << "result: " << firstKey.convertToInteger() << endl;
  cout << endl;

  cout << "testing == operator on firstKey and fromFileKey..." << endl;
    if(firstKey == fromFileKey){
      cout << "firstKey and fromFileKey match" << endl;
    }
    else
      cout << "firstKey and fromFileKey do not match" << endl;
      cout << endl;

  cout << "testing == operator on firstKey and secondKey..." << endl;
    if(firstKey == secondKey){
      cout << "firstKey and secondKey match" << endl;
    }
    else
      cout << "firstKey and secondKey do not match" << endl;
      cout << endl;

  cout << "testing < operator on firstKey and fromFileKey..." << endl;
    if(firstKey < fromFileKey){
      cout << "firstKey is less than fromFileKey" << endl;
    }
    else
      cout << "firstKey is not less than fromFileKey" << endl;
      cout << endl;

  cout << "testing < operator on firstKey and secondKey..." << endl;
    if(firstKey < secondKey){
      cout << "firstKey is less than secondKey" << endl;
    }
    else
      cout << "firstKey is not less than secondKey" << endl;
      cout << endl;

  cout << "-----------------------" << endl;
  cout << "  CLASS ITEM TESTING" << endl;
  cout << endl;

  cout << "Enter a texting abbreviation, and it's associated meaning -> ";
  cin >> firstOne;
  cout << endl;
  cout << "reading from in.dat..." << endl;
  infile >> fromFile;
  cout << endl;

  cout << "firstOne -- " << firstOne;
  cout << "fromFile -- " << fromFile;
  cout << endl;

  cout << "writing firstOne to out.dat..." << endl;
  cout << endl;
  outfile << "firstOne -> " << firstOne << endl;

  cout << "testing class Item copy constructor..." << endl;
  cout << "copying firstKey to secondKey..." << endl;
  Item secondOne(firstOne);
  cout << endl;
  cout << "firstOne -- " << firstOne;
  cout << "secondOne -- " << secondOne;
  cout << endl;

  cout << "testing cascading equals operator..." << endl;
  cout << "copying firstOne to secondOne and thirdOne..." << endl;
  cout << endl;

  thirdOne = secondOne = firstOne;

  cout << "firstOne -- " << firstOne;
  cout << "secondOne -- " << secondOne;
  cout << "thirdOne -- " << thirdOne;
  cout << endl;

  cout << "testing convertToInteger on Item firstOne..." << endl;
  cout << "result: " << firstOne.convertToInteger() << endl;
  cout << endl;

  cout << "testing == operator on firstOne and fromFile..." << endl;
    if(firstOne == fromFile){
      cout << "firstKey and fromFileKey match" << endl;
    }
    else
      cout << "firstKey and fromFileKey do not match" << endl;
      cout << endl;

  cout << "testing == operator on firstOne and secondOne..." << endl;
    if(firstOne == secondOne){
      cout << "firstOne and secondOne match" << endl;
    }
    else
      cout << "firstOne and secondOne do not match" << endl;
      cout << endl;

  cout << "testing < operator on firstOne and fromFile..." << endl;
    if(firstOne < fromFile){
      cout << "firstOne is less than fromFile" << endl;
    }
    else
      cout << "firstOne is not less than fromFile" << endl;
      cout << endl;

  cout << "testing < operator on firstOne and secondOne..." << endl;
    if(firstOne < secondOne){
      cout << "firstOne is less than secondOne" << endl;
    }
    else
      cout << "firstOne is not less than secondOne" << endl;
      cout << endl;
      cout << endl;

  return 0;
}
