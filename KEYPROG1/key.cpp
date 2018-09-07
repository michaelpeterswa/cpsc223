/*
Michael Peters and Nathan Flack
CPSC223 01
Homework Assignment 1
Thursday, September 6, 2018

ADT Key (Texting Abbreviation)
Specification file for ADT Key (Testing Abbreviation)
   data object: a key or texting abbreviation (unique)
   operations: create an empty key, destroy a key
               read a key from a file, write a key to a file
               read a key from the user, write a key to the screen,
               convert a key to a number (for what's coming in Dictionary)

filename: key.cpp

This program, key.cpp is designed to interface between key.h and testingclient.cpp.
This file contains the functions from class Key that are defined within.

*/

#include "key.h"
#include <string>
#include <iostream>
using namespace std;

//creates string by calling string constructor
Key::Key(){

  cout << "Key object initialized" << endl;
}

//destroys textingAbbreviation by clearing the string
Key::~Key(){

  textingAbbreviation.erase();
}

//this function reads from an input stream passed in, into textingAbbreviation
void Key::read(istream& inputstream){

  inputstream >> textingAbbreviation;
}

//this function writes to an output stream passed in, from textingAbbreviation
void Key::write(ostream& outputstream){

  outputstream << textingAbbreviation;
}

//this function adds all of the ascii values of each letter in the textingAbbreviation string
int Key::convertToInteger(){

  int runningTab = 0;

  for (int count = 0; count < textingAbbreviation.length(); count++) {

    runningTab += int(textingAbbreviation.at(count));

  }
  return runningTab;
}

//this function assigns textingAbbreviation a new string specified by the key object passed into it
void Key::assign(const Key& rightHandSideKey){
    textingAbbreviation = rightHandSideKey.textingAbbreviation;
}
