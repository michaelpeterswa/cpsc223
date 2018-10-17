//clientguy
// clang++ -std=c++11 client.cpp binarytree.cpp exception.cpp treenode.cpp item.cpp key.cpp -o gotree

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

void runCompleteTreeHeight3(ifstream& infile, BinaryTree aTree);

void runFullTreeHeight3(ifstream& infile, BinaryTree aTree);

void runOrders(BinaryTree aTree);

int main()
{
   BinaryTree completeTree, fullTree;
   ifstream infile;

   openInputFile(infile, "in.dat");
   runFullTreeHeight3(infile, fullTree);
   runCompleteTreeHeight3(infile, completeTree);

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

void runCompleteTreeHeight3(ifstream& infile, BinaryTree aTree){

    try{
        aTree.makeCompleteTreeHeight3(infile);
    }
    catch (Exception except)
    {
       printExceptionMessage(except);
    }

    cout << endl;
    cout << "Complete Tree Height 3:" << endl;
    cout << endl;
    aTree.prettyDisplay();
    runOrders(aTree);
    cout << "------------------------------" << endl;
}

void runFullTreeHeight3(ifstream& infile, BinaryTree aTree){

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

void runOrders(BinaryTree aTree){
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
