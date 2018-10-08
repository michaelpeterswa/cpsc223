/*
Michael Peters
mpeters4
7 October 2018
Description: This is a client program that tests the member functions of abstract
data type Binary Tree. It creates a full tree of height 3 and a degenerate tree of height 4. It also runs the ordering functions for each tree.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "binarytree.h"
using namespace std;

// opens a file for reading
// post: infile has been opened with file pointer at beginning of file
// usage: openFile(infile);
void openFile(ifstream& infile);

// makes a full binary tree of height 3
// pre: fullTree exists. infile has been opened with file pointer at beginning
//      items are arranged so that text is on one line and meaning is on next line
// post: fullTree is now a full binary tree of height 3
// usage: makeFullTreeHeight3(infile, fullTree);
void makeFullTreeHeight3(ifstream& infile, BinaryTree& fullTree);

// makes a degenerate tree of height 4
// pre: fullTree exists. infile has been opened with file pointer at beginning
//      items are arranged so that text is on one line and meaning is on next line
// post: fullTree is now a degenerate tree of height 4
// usage: makeFullTreeHeight2(infile, fullTree);
void makeDegenerateTreeHeight4(ifstream& infile, BinaryTree& degenerateTree);

// prints the full tree in reader-friendly fashion with branches
// post: the picture of the tree has been displayed on the screen
// usage: printFullTreeHeight3();
void printFullTreeHeight3();

// prints the degenerate tree in reader-friendly fashion with branches
// post: the picture of the tree has been displayed on the screen
// usage: printDegenerateTreeHeight4();
void printDegenerateTreeHeight4();

// prints a number of newlines on the screen
// pre: numberOfLines is assigned a positive value_comp
// post: numberOfLines newlines has been printed on the screen
// usage: makeNewLines(3);
void printNewLines(int numberOfLines);

// runs print, make, and order functions for rfth3
// pre: infile and fullTree exist
// post: functions are run
// usage: runFullTreeHeight3(infile, fullTree);
void runFullTreeHeight3(ifstream& infile, BinaryTree& fullTree);

// runs print, make, and order functions for rdth4
// pre: infile and degenerateTree exist
// post: functions are run
// usage: runDegenerateTreeHeight4(infile, degenerateTree);
void runDegenerateTreeHeight4(ifstream& infile, BinaryTree& degenerateTree);

int main()
{
	BinaryTree fullTree;
	BinaryTree degenerateTree;
	ifstream infile;

	openFile(infile);
	runFullTreeHeight3(infile, fullTree);
	runDegenerateTreeHeight4(infile, degenerateTree);

	return 0;
}

// runs print, make, and order functions for rfth3
// pre: infile and fullTree exist
// post: functions are run
// usage: runFullTreeHeight3(infile, fullTree);ww
void runFullTreeHeight3(ifstream& infile, BinaryTree& fullTree){

	printNewLines(2);
	cout << "A Full Tree of Height 3" << endl;
	printNewLines(1);
	printFullTreeHeight3();
	makeFullTreeHeight3(infile, fullTree);

    printNewLines(1);
	cout << "Preorder Traversal:" << endl;
	printNewLines(1);
	fullTree.preorder();

	cout << "Inorder Traversal:" << endl;
	printNewLines(1);
	fullTree.inorder();

	cout << "Postorder Traversal:" << endl;
	printNewLines(1);
	fullTree.postorder();
}

// runs print, make, and order functions for rdth4
// pre: infile and degenerateTree exist
// post: functions are run
// usage: runDegenerateTreeHeight4(infile, degenerateTree);
void runDegenerateTreeHeight4(ifstream& infile, BinaryTree& degenerateTree){

	printNewLines(2);
	cout << "A Degenerate Tree of Height 4" << endl;
	printNewLines(1);
	printDegenerateTreeHeight4();
	makeDegenerateTreeHeight4(infile, degenerateTree);

	printNewLines(1);
	cout << "Preorder Traversal:" << endl;
	printNewLines(1);
	degenerateTree.preorder();

	cout << "Inorder Traversal:" << endl;
	printNewLines(1);
	degenerateTree.inorder();

	cout << "Postorder Traversal:" << endl;
	printNewLines(1);
	degenerateTree.postorder();

}

// opens a file for reading
// post: infile has been opened with file pointer at beginning of file
// usage: openFile(infile);
void openFile(ifstream& infile)
{
	infile.open("in.dat");
	if (infile.fail())
	{
		cout << "ERROR: cannot open in.dat. BOLTING" << endl;
		exit(1);   // the only place we bolt
	}
}

// makes a full binary tree of height 2
// pre: fullTree exists. infile has been opened with file pointer at beginning
//      items are arranged so that text is on one line and meaning is on next line
// post: fullTree is now a full binary tree of height 2
// usage: makeFullTreeHeight2(infile, fullTree);
void makeFullTreeHeight3(ifstream& infile, BinaryTree& fullTree)
{
	Item nextItem;

	infile >> nextItem;
	fullTree.insert(nextItem, 1, 2);

	infile >> nextItem;
	fullTree.insert(nextItem, 3, 4);

	infile >> nextItem;
	fullTree.insert(nextItem, 5, 6);

	infile >> nextItem;
	fullTree.insert(nextItem, -1, -1);

	infile >> nextItem;
	fullTree.insert(nextItem, -1, -1);

	infile >> nextItem;
	fullTree.insert(nextItem, -1, -1);

	infile >> nextItem;
	fullTree.insert(nextItem, -1, -1);
}

void makeDegenerateTreeHeight4(ifstream& infile, BinaryTree& degenerateTree){

	Item nextItem;

	infile >> nextItem;
	degenerateTree.insert(nextItem, -1, 1);

	infile >> nextItem;
	degenerateTree.insert(nextItem, -1, 2);

	infile >> nextItem;
	degenerateTree.insert(nextItem, -1, 3);

	infile >> nextItem;
	degenerateTree.insert(nextItem, -1, -1);

}

// prints the full tree in reader-friendly fashion with branches
// post: the picture of the tree has been displayed on the screen
// usage: printFullTreeHeight2();
void printFullTreeHeight3()
{
	cout << "                         " << "          lol: laugh out loud" << endl;
	cout << "            /     " << "                 " << "                                        \\" << endl;
	cout << "      smh: shake my head" << "                                     " << "            l8r: later" << endl;
	cout << "     /                  \\  " << "                                         / " << "                 \\" << endl;
	cout << "ttyl: talk to you later  rofl: rolling on the floor laughing" << "    cya: see you later  " << "gtg: got to go" << endl;
}

void printDegenerateTreeHeight4()
{
	cout << "   lol" << endl;
	cout << "    \\" << endl;
	cout << "    smh" << endl;
	cout << "      \\" << endl;
	cout << "      l8r" << endl;
	cout << "        \\" << endl;
	cout << "        ttyl" << endl;
}

// prints a number of newlines on the screen
// pre: numberOfLines is assigned a positive value_comp
// post: numberOfLines newlines has been printed on the screen
// usage: makeNewLines(3);
void printNewLines(int numberOfLines)
{
	for (int k = 0; k < numberOfLines; k++)
		cout << endl;
}
