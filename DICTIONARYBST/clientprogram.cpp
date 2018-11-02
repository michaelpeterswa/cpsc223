//Michael Peters and Nathan Flack
//clientprogram.cpp
//November 2, 2018
//dropoff: mpeters4

#include <iostream>
#include <fstream>
#include "binarysearchtree.h"
#include "exception.h"

using namespace std;

//menu functions
void printMenu();
void welcome();
char getInput();
char menuPrompt();
void doMenu(istream&, ostream&, BinarySearchTree&);

//option functions
void runSearch(BinarySearchTree&);
void runInsert(BinarySearchTree&);
void runList(BinarySearchTree&);
void runPrint(BinarySearchTree&);
void runRebalance(istream&, ostream&, BinarySearchTree&);
void runSave(ostream&, BinarySearchTree&);
void readFromFile(istream&, BinarySearchTree&);

//main
int main(){

    BinarySearchTree masterDirectory;

    ifstream infile("dictionary.dat"); //file input used for testing reading from file

    welcome();
    readFromFile(infile, masterDirectory);

    ofstream outfile("dictionary.dat"); //file output used for testing writing to a file
    doMenu(infile, outfile, masterDirectory);

    return 0;
}

//prints the menu, in doMenu
void printMenu(){
    cout << "----------------------------------------------------" << endl;
    cout << "Option:\t Command" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "f:\t Find a contact from phone number" << endl;
    cout << "i:\t Insert a new contact into the directory" << endl;
    cout << "l:\t List the entire directory" << endl;
    cout << "p:\t Print the directory tree" << endl;
    cout << "r:\t Rebalance the directory tree" << endl;
    cout << "s:\t Save the directory" << endl;
    cout << "e:\t Exit the directory with Save" << endl;
    cout << endl;

}

//welcome function that runs once at start
void welcome(){
    cout << "Welcome to the Electronic Directory" << endl;
    cout << "\tdesigned by Michael Peters and Nathan Flack" << endl;
    cout << endl;
}

//recieve input from the line
char getInput(){
    char input, newline;
    cin.get(input);
    cin.get(newline);

    return input;
}

//prompt for the menu
char menuPrompt(){
    char input;

    cout << "Please enter the option of your choosing (single lowercase option letter only): ";
    input = getInput();
    cout << "---------------------------------------------------------" << endl;
    cout << endl;

    return input;
}

//central menu function
void doMenu(istream& infile, ostream& outfile, BinarySearchTree& masterTree){
    char inp;

    printMenu();
    inp = menuPrompt();

     if(inp != 'e') {

        if(inp == 'f'){
            //search for contact from number
            runSearch(masterTree);
            doMenu(infile, outfile, masterTree);
        }

        else if(inp == 'i'){
            //insert new contact
            runInsert(masterTree);
            doMenu(infile, outfile, masterTree);
        }

        else if(inp == 'l'){
            //list the contacts
            runList(masterTree);
            doMenu(infile, outfile, masterTree);
        }

        else if(inp == 'p'){
            //pretty print the tree
            runPrint(masterTree);
            doMenu(infile, outfile, masterTree);
        }

        else if(inp == 'r'){
            //rebalance
            runRebalance(infile, outfile, masterTree);
            doMenu(infile, outfile, masterTree);
        }

        else if(inp == 's'){
            //save
            runSave(outfile, masterTree);
            doMenu(infile, outfile, masterTree);
        }

        else{
            cout << "---------------------" << endl;
            cout << "invalid option letter" << endl;
            cout << "---------------------" << endl;
            cout << endl;
            doMenu(infile, outfile, masterTree);
        }
    }
    if(inp == 'e'){
        //save
        runSave(outfile, masterTree);
        cout << "The directory is now saving..." << endl;
        cout << "The directory program is now closing. Goodbye!" << endl;
    }
}

//run search
void runSearch(BinarySearchTree& masterTree){
    Item foundItem;
    Key newKey;

    cout << "Please enter the number to be searched: ";
    cin >> newKey;
    cout << endl;

    if(masterTree.searchForMeaning(newKey, foundItem)){
        cout << "Found! Here is the contact: ";
        cout << foundItem << endl;
    }
    else{
        cout << "That number was not located in the Directory" << endl;
    }
}

//run insert of a name and number
void runInsert(BinarySearchTree& masterTree){
    Item newItem;

    cout << endl;
    cout << "Please enter contact information (number followed by name): ";
    cin >> newItem;

    try{
        masterTree.addNewEntry(newItem);
    }
    catch (Exception except){
        cout << except.what() << endl;
    }

    cout << endl;

}

//runs list
void runList(BinarySearchTree& masterTree){
    cout << endl;
    cout << "Listing the contacts..." << endl;
    cout << endl;
    masterTree.BinaryTree::inorderTraverse();
    cout << endl;
}

//runs print
void runPrint(BinarySearchTree& masterTree){
    cout << endl;
    cout << "Printing the tree..." << endl;
    cout << endl;
    masterTree.prettyDisplay();
}

//runs rebalance
void runRebalance(istream& infile, ostream& outfile, BinarySearchTree& masterTree){
    cout << endl;
    cout << "Rebalancing the tree..." << endl;
    cout << endl;

    masterTree.reBalance(infile, outfile);

    cout << "Rebalance was successful." << endl;
    cout << endl;
}

//run save
void runSave(ostream& outfile, BinarySearchTree& masterTree){
    masterTree.inorderTraverse(outfile);
    cout << "Saving to file." << endl;
}

//run read at start
void readFromFile(istream& infile, BinarySearchTree& masterTree){
    int numberOfItems;
    infile >> numberOfItems;
    cout << numberOfItems << " items read from file"<<endl;
    for (int i = 0; i < numberOfItems; i++)
    {
        Item newItem;
        infile >> newItem;
        masterTree.addNewEntry(newItem);
    }
}
