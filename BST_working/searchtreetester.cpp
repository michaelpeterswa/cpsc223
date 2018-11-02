#include <iostream>
#include <fstream>
#include <cstdlib>
#include "binarysearchtree.h"
#include "item.h"

using namespace std;

void printMenu();
void openMenu(BinarySearchTree&, istream&, ostream&);

void find(BinarySearchTree&);
void insert(BinarySearchTree&);
void list(BinarySearchTree&);
void print(BinarySearchTree&);
void rebalance(BinarySearchTree&, istream&, ostream&);
void save(BinarySearchTree&);

int main()
{
	BinarySearchTree myTree1;
	ifstream inFile("dictionary.dat");
	ofstream oFile("dictionary.dat");
	openMenu(myTree1, inFile, oFile);
	return 0;
}



void openMenu(BinarySearchTree& myTree, istream& inFile, ostream& oFile)
{
	char character;
	bool exit = false;
	while(not exit)
	{
		cout << endl;
		printMenu();
		cin.get(character);
		cout << endl;
		if (character == 'f')
		{
			find(myTree);
		}
		else if (character == 'i')
		{
			insert(myTree);
		}
		else if (character == 'l')
		{
			list(myTree);
		}
		else if (character == 'p')
		{
			print(myTree);
		}
		else if (character == 'r')
		{
			rebalance(myTree, inFile, oFile);
		}
		else if (character == 's')
		{
			save(myTree);
		}
		else if (character == 'e')
		{
			exit = true;
		}
	}
}

void printMenu()
{
	cout << "f : find" << endl;
	cout << "i : insert" << endl;
	cout << "l : list " << endl;
	cout << "p : print " << endl;
	cout << "r : rebalance " << endl;
	cout << "s : save " << endl;
	cout << "e : exit " << endl;
	cout << "Enter your option >_";
}

void find(BinarySearchTree& myTree)
{
	Key targetText;
	Item foundItem;
	cout << "Enter abbreviation you want to find" << endl;
	cin >> targetText;
	if(myTree.searchForMeaning(targetText, foundItem))
	{
		cout << "item found" << endl;
	}
	else
	{
		cout << "item not found" << endl;
	}

}

void insert(BinarySearchTree& myTree)
{
	Item newItem;
	cout << "enter a texting abbreviation and meaning to add" << endl;
	cin >> newItem;
	myTree.addNewEntry(newItem);
}

void list(BinarySearchTree& myTree)
{
	myTree.inorderTraverse(cout);
}
void print(BinarySearchTree& myTree)
{
	myTree.prettyDisplay();
}
void rebalance(BinarySearchTree& myTree, istream& inFile, ostream& oFile)
{
	 myTree.reBalance(inFile, oFile);
}
void save(BinarySearchTree& myTree){}
