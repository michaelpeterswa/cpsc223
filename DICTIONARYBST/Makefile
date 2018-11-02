compiler= clang++
flag= -std=c++11

all:
	$(compiler) $(flag) clientprogram.cpp binarysearchtree.cpp binarytree.cpp treenode.cpp item.cpp key.cpp exception.cpp -o dodictionary
	$(compiler) $(flag) searchtreetester.cpp binarysearchtree.cpp binarytree.cpp treenode.cpp item.cpp key.cpp exception.cpp -o searchtreetester

test:
	$(compiler) $(flag) searchtreetester.cpp binarysearchtree.cpp binarytree.cpp treenode.cpp item.cpp key.cpp exception.cpp -o searchtreetester

client:
	$(compiler) $(flag) clientprogram.cpp binarysearchtree.cpp binarytree.cpp treenode.cpp item.cpp key.cpp exception.cpp -o dodictionary

clean:
	rm dodictionary
	rm searchtreetester
