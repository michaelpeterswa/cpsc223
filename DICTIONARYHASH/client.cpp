//Michael Peters and Vincent Rettke
//CPSC223 01
//Programming Assignment 3
//September 24, 2018
//client.cpp

#include <iostream>
#include <fstream>
#include "key.h"
#include "item.h"
#include "dictionary.h"
using namespace std;

int main (){

    ifstream infile("in.dat"); //file input used for testing reading from file

    Dictionary master;
    Item anItem;
    Key search;

    bool isFound, isEmpty;

    cout << endl;
    cout << endl;
    cout << "     created Dictionary object 'master' " << endl;
    cout << "        created Item object 'anItem' " << endl;
    cout << "        created Key object 'search' " << endl;
    cout << "     ----------------------------------" << endl;
    cout << endl;
    cout << "    first read from in.dat of four abbreviations" << endl;
    infile >> master;
    cout << "    printing current dictionary (2a)" << endl;
    cout << endl;
    cout << master;
    cout << "     ----------------------------------" << endl;
    cout << endl;
    cout << "     second read from in.dat of three abbreviations" << endl;
    infile >> master;
    cout << "     printing current dictionary (2b)" << endl;
    cout << endl;
    cout << master;
    cout << "     ----------------------------------" << endl;

    cout << endl;
    cout << "searching for l8r (2c short)" << endl;
    cout << "if found, l8r will be printed, along with it's meaning" << endl;
    cout << endl;
    infile >> search;
    master.searchForMeaning(search, anItem, isFound);
    if(isFound)
      cout << anItem << endl;
    else
      cout << "l8r not found in dictionary" << endl;

    cout << endl;
    cout << "searching for lorf (2c long)" << endl;
    cout << "if found, lorf will be printed, along with it's meaning" << endl;
    cout << endl;
    infile >> search;
    master.searchForMeaning(search, anItem, isFound);
    if(isFound)
      cout << anItem << endl;
    else
      cout << "lorf not found in dictionary" << endl;

    cout << "     ----------------------------------" << endl;
    cout << endl;

    infile >> search;
    cout << "removing orlf from dictionary (2d)" << endl;
    cout << "notice that address 0 is 'marked'" << endl;
    master.deleteEntry(search, isEmpty, isFound);
    cout << endl;
    cout << master;
    cout << "     ----------------------------------" << endl;
    cout << endl;

    cout << "searching for lorf (2e)" << endl;
    cout << "if found, lorf will be printed, along with it's meaning" << endl;
    cout << endl;
    infile >> search;
    master.searchForMeaning(search, anItem, isFound);
    if(isFound)
      cout << anItem << endl;
    else
      cout << "lorf not found in dictionary" << endl;


infile.close();
return 0;
}
