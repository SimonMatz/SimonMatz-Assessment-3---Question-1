#include <iostream>
#include <string>
#include "BST.h"
#include "AVL.h"

using namespace std;

void main()
{
	AVL avl1;
	avl1.displayRotations = true;
	avl1.insert(new Node(23));
	avl1.insert(new Node(12));
	avl1.insert(new Node(5));
	avl1.insert(new Node(8));
	avl1.insert(new Node(10));
	avl1.insert(new Node(21));
	avl1.insert(new Node(11));
	avl1.insert(new Node(17));

	cout << "AVL root is : " << avl1.root->number << " " << endl;
	
	avl1.show(avl1.root);

	cout << "\n\n\n";
	
}
