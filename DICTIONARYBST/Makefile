compiler= clang++
flag= -std=c++11 -o
clientexec= dodictionary
testexec= searchtreetester

all:
	$(compiler) $(flag) $(clientexec) clientprogram.cpp binarysearchtree.cpp binarytree.cpp treenode.cpp item.cpp key.cpp exception.cpp
	$(compiler) $(flag) $(testexec) searchtreetester.cpp binarysearchtree.cpp binarytree.cpp treenode.cpp item.cpp key.cpp exception.cpp 

test:
	$(compiler) $(flag) searchtreetester searchtreetester.cpp binarysearchtree.cpp binarytree.cpp treenode.cpp item.cpp key.cpp exception.cpp

client:
	$(compiler) $(flag) dodictionary clientprogram.cpp binarysearchtree.cpp binarytree.cpp treenode.cpp item.cpp key.cpp exception.cpp

clean:
	rm dodictionary
	rm searchtreetester
