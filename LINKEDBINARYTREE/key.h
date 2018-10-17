//filename key.h
//author  Dr. Y
//date September 7, 2018
//Specification of Abstract Data Type Key
//
//   data object: a key which is a texting abbreviation
//   operations: create, destroy, copy,
//               input, output, assign
//               check if same, check if less than,
//               convert to an integer

#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>
using namespace std;

class Key
{
//allows for input of a key object from either the standard input device or a file
//pre input has been opened or a prompt has been given
//post rightHandSideKey has been filled with a texting abbreviation
//usage cin >> mykey;
friend istream& operator>> (istream& input, Key& rightHandSideKey);

//allows for the output of a key to the standard output device or a file
//pre rightHandSideKey has been filled with a texting abbreviation; output has been opened
//post rightHandSideKey has been written to the output device with no spaces before or after
//usage  outfile << mykey;
friend ostream& operator<< (ostream& output, const Key& rightHandSideKey);

public:

//creates an empty texting abbreviation
//post Key object is an empty texting abbreviation
//usage Key akey;
Key();

//creates a specific texting abbreviation
//pre keyText is assigned a string that represents a texting abbreviation
//post Key object has a copy of the texting abbreviation in keyText
//usage Key akey("lol");
Key(string keyText);

//releases memory for a texting abbreviation
//pre Key object exists
//post Key object no longer exists, memory has been freed
//usage automatically done at the end of scope
~Key();

//copies a texting abbreviation
//pre rightHandSideKey has been assigned a texting abbreviation
//post Key object has a copy of rightHandSideKey
//usage bkey = akey;
Key& operator=(const Key& rightHandSideKey);

//converts a texting abbreviation to an integer
//pre Key object exists
//post returns the sum of the ASCII values of letters in the texting abbreviation
//usage cout << akey.convertToInteger();
int convertToInteger() const;

//checks if two texting abbreviations are the same
//pre rightHandSideKey has been assigned
//post returns true if Key object is the same exact texting abbreviation as that in rightHandSideKey
//usage if (akey == bkey) { cout << "the texting abbreviations are the same" << endl;
bool operator==(const Key& rightHandSideKey) const;

//checks if one texting abbreviation is less than another
//pre rightHandSideKey has been assigned a texting abbreviation
//post returns true if Key object's texting abbreviation is less than (alphabetically) the one in rightHandSideKey
//usage if (akey < bkey) { cout << "left text is less than right text" << endl;
bool operator<(const Key& rightHandSideKey) const;

protected:
   string textingAbbreviation;
};
#endif
