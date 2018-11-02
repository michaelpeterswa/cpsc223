#include <iostream>
#include <fstream>
#include <cstdlib>
#include "binarysearchtree.h"
#include "item.h"
#include "exception.h"

using namespace std;

void runSearch(BinarySearchTree&);
void runInsert(BinarySearchTree&);
void runList(BinarySearchTree&);
void runPrint(BinarySearchTree&);
void separate();

int main()
{
	BinarySearchTree masterDirectory;

	runInsert(masterDirectory);
	separate();
	runSearch(masterDirectory);
	separate();
	runList(masterDirectory);
	separate();
	runPrint(masterDirectory);
	separate();
	return 0;
}

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

void runSearch(BinarySearchTree& masterTree){
    Item foundItem;
    Key newKey;

    cout << "Please enter the number to be searched (number previously entered): ";
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

void runList(BinarySearchTree& masterTree){
    cout << endl;
    cout << "Listing the contacts in the directory..." << endl;
    cout << endl;
    masterTree.BinaryTree::inorderTraverse();
    cout << endl;
}

void runPrint(BinarySearchTree& masterTree){
    cout << endl;
    cout << "Printing the tree..." << endl;
    cout << endl;
    masterTree.prettyDisplay();
}

void separate(){
	cout << "-------------------------------" << endl;
}
