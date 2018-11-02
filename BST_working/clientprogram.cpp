//Michael Peters and Nathan Flack
//
#include <iostream>
#include <fstream>
#include "binarysearchtree.h"
#include "exception.h"

using namespace std;

void printMenu();
void welcome();
char getInput();
char menuPrompt();
void doMenu(istream&, ostream&, BinarySearchTree&);

void runSearch(BinarySearchTree&);
void runInsert(BinarySearchTree&);
void runList(BinarySearchTree&);
void runPrint(BinarySearchTree&);
void runRebalance(istream&, ostream&, BinarySearchTree&);
void runSave(ostream&, BinarySearchTree&);

int main(){

    BinarySearchTree masterDirectory;

    ifstream infile("dictionary.dat"); //file input used for testing reading from file
    ofstream outfile("dictionary.dat"); //file output used for testing writing to a file

    welcome();
    doMenu(infile, outfile, masterDirectory);

    return 0;
}

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

void welcome(){
    cout << "Welcome to the Electronic Directory" << endl;
    cout << "\tdesigned by Michael Peters and Nathan Flack" << endl;
    cout << endl;
}

char getInput(){
    char input, newline;
    cin.get(input);
    cin.get(newline);

    return input;
}

char menuPrompt(){
    char input;

    cout << "Please enter the option of your choosing (single lowercase option letter): ";
    input = getInput();
    cout << "---------------------------------------------------------" << endl;
    cout << endl;

    return input;
}

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

void runSearch(BinarySearchTree& masterTree){
    Item foundItem;
    Key newKey;

    cout << "Please enter the number to be searched: ";
    cin >> newKey;
    cout << endl;

    if(masterTree.searchForMeaning(newKey, foundItem)){
        cout << foundItem << endl;
    }
    else{
        cout << "That number was not located in the Directory" << endl;
    }
}

void runInsert(BinarySearchTree& masterTree){
    Item newItem;

    cout << endl;
    cout << "Please enter contact information (number followed by name): ";
    cin >> newItem;
    masterTree.addNewEntry(newItem);
    cout << endl;

}

void runList(BinarySearchTree& masterTree){
    cout << endl;
    cout << "Listing the contacts..." << endl;
    cout << endl;
    masterTree.inorderTraverse(cout);
}

void runPrint(BinarySearchTree& masterTree){
    cout << endl;
    cout << "Printing the tree..." << endl;
    cout << endl;
    masterTree.prettyDisplay();
}

void runRebalance(istream& infile, ostream& outfile, BinarySearchTree& masterTree){
    cout << endl;
    cout << "Rebalancing the tree..." << endl;
    cout << endl;

    masterTree.reBalance(infile, outfile);

    cout << "Rebalance was successful." << endl;
    cout << endl;
}

void runSave(ostream& outfile, BinarySearchTree& masterTree){
    masterTree.inorderTraverse(outfile);
    cout << "Saving to file." << endl;
}
