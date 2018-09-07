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

filename: testingclient.cpp

This program, testingclient.cpp is designed to display the functions of the Key Class.

*/
#include "key.h"
#include <iostream>
#include <fstream>
using namespace std;



int main()
{
   ifstream infile("in.dat"); //file input used for testing reading from file
   ofstream outfile("out.dat"); //file output used for testing writing to a file
   Key firstOne; //primary Key object
   Key rightHandSideKey; //secondary Key object
   char inputChoice; //


   cout << endl << endl;    // to move first output away from command prompt

   cout << "          Testing the constructor" << endl;
   cout << "string is empty and show nothing between # signs" << endl;
   cout << "#";
   firstOne.write(cout);
   cout << "#" << endl;
   cout << endl;
   cout << "Would you like to input from a file? (y/n) ";
   cin >> inputChoice;

   //here is the switch-case that deals with wether the user
   //would like to use a file or type in their textingAbbreviation

   switch (inputChoice) {
     case 'y':
       firstOne.read(infile);
       break;
     case 'n':
       cout << "Enter a texting abbreviation -> "; // note the arrow to show the user where to type and left on same line
       firstOne.read(cin);
       break;
     default:
       cout << "that is not a valid answer, please try again. Goodbye" << endl;
       return 0;
   }

   cout << endl;
   cout << "shows result between # signs" << endl;
   cout << "#";
   firstOne.write(cout);
   cout << "#" << endl;
   firstOne.write(outfile);
   cout << endl;
   cout << "        Writing textingAbbreviation to out.dat" << endl;
   cout << endl;

   cout << "       Testing the convertToInteger, OUTPUT IS: " << firstOne.convertToInteger() << endl;
   cout << endl;

   cout << "       Testing assign function" << endl;
   cout << "please input textingAbbreviation for rightHandSideKey -> ";
   rightHandSideKey.read(cin);
   cout << endl;
   firstOne.assign(rightHandSideKey);
   cout << endl;
   cout << "the value of rightHandSideKey is: " << endl;
   cout << "#";
   rightHandSideKey.write(cout);
   cout << "#" << endl;
   cout << "the new value of firstOne is: " << endl;
   cout << "#";
   firstOne.write(cout);
   cout << "#" << endl;
   return 0;
}
