//clientguy

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

int main()
{
   BinaryTree mytree, otherTree;
   ifstream infile;

   openInputFile(infile, "in.dat");

   try {
     mytree.makeCompleteTreeHeight3(infile);
     mytree.preorderTraverse();
	 cout << endl << endl;
	 mytree.prettyDisplay();
	 cout << endl << endl;
	 otherTree = mytree;
	 otherTree.prettyDisplay();
    }
   catch (Exception except)
   {
      printExceptionMessage(except);
   }
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

void testCopyTree()
{


}
