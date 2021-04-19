#include <iostream>
#include <string>
#include "BST.h"
#include "AVL.h"

using namespace std;

void main()
{
	AVL avl1;
	avl1.displayRotations = true;
	avl1.insert(new Node(1));
	avl1.insert(new Node(2));
	avl1.insert(new Node(3));
	avl1.insert(new Node(10));
	avl1.insert(new Node(15));
	avl1.insert(new Node(20));
	avl1.insert(new Node(25));
	avl1.insert(new Node(30));
	cout << "AVL root is : " << avl1.root->number << " " << endl;
	


	cout << "finding 25..." << endl;
	Node* sPtr2 = avl1.search(25, true);

	if (sPtr2 != NULL)
		cout << "Found " << sPtr2->number << " xxxx" << endl;
	else
		cout << "Wasn't able to find number in tree" << endl;

	system("pause");
}
