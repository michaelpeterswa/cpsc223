/*
Michael Peters and Nathan Flack
mpeters4
7 October 2018
Description: This is a client program that tests the member functions of abstract
data type Binary Tree. It creates a full tree of height 3 and a degenerate tree of height 4. It also
runs the ordering functions for each tree.

clang++ -std=c++11 client.cpp binarytree.cpp exception.cpp treenode.cpp item.cpp key.cpp -o gotree
*/


#include "binarytree.h"
#include "exception.h"
#include <string>
#include <fstream>
using namespace std;

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except);

//runs necessary functions for complete tree height 4
//pre: infile exists and aTree exists;
//post: runs make, print, and runOrders
//usage: runCompleteTreeHeight4(infile, aTree);
void runCompleteTreeHeight4(ifstream& infile, BinaryTree& aTree);

//runs necessary functions for full tree height 3
//pre: infile exists and aTree exists;
//post: runs make, print, and runOrders
//usage: runFullTreeHeight3(infile, aTree);
void runFullTreeHeight3(ifstream& infile, BinaryTree& aTree);

//runs order traversals
//pre: a tree exists
//post: order traversals are printed for aTree
//usage: runOrders(mytree);
void runOrders(BinaryTree& aTree);

int main()
{
   BinaryTree completeTree, fullTree;
   ifstream infile;

   openInputFile(infile, "in.dat");

   runFullTreeHeight3(infile, fullTree);
   runCompleteTreeHeight4(infile, completeTree);

   return 0;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile, string filename)
{
   inputFile.open(filename);
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except)
{
   cout << endl << endl;
   cout << except.what();
   cout << endl << endl;
}

//runs necessary functions for complete tree height 4
//pre: infile exists and aTree exists;
//post: runs make, print, and runOrders
//usage: runCompleteTreeHeight4(infile, aTree);
void runCompleteTreeHeight4(ifstream& infile, BinaryTree& aTree){

    try{
        aTree.makeCompleteTreeHeight4(infile);
    }
    catch (Exception except)
    {
       printExceptionMessage(except);
    }

    cout << endl;
    cout << "Complete Tree Height 4:" << endl;
    cout << endl;
    aTree.prettyDisplay();
    runOrders(aTree);
    cout << "------------------------------" << endl;
}

//runs necessary functions for full tree height 3
//pre: infile exists and aTree exists;
//post: runs make, print, and runOrders
//usage: runFullTreeHeight3(infile, aTree);
void runFullTreeHeight3(ifstream& infile, BinaryTree& aTree){

    try{
        aTree.makeFullTreeHeight3(infile);
    }
    catch (Exception except)
    {
       printExceptionMessage(except);
    }

    cout << endl;
    cout << "Full Tree Height 3:" << endl;
    cout << endl;
    aTree.prettyDisplay();
    runOrders(aTree);
    cout << "------------------------------" << endl;
}

//runs order traversals
//pre: a tree exists
//post: order traversals are printed for aTree
//usage: runOrders(mytree);
void runOrders(BinaryTree& aTree){
    cout << endl << endl;
    cout << "Preorder:" << endl;
    cout << endl;
    aTree.preorderTraverse();
    cout << endl;
    cout << "Inorder:" << endl;
    cout << endl;
    aTree.inorderTraverse();
    cout << endl;
    cout << "Postorder:" << endl;
    cout << endl;
    aTree.postorderTraverse();
    cout << endl;
}
