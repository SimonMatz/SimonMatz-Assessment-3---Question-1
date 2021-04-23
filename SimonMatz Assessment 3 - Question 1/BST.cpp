//Simon Matz A00018077 Assessment 3 - Question 1
//Github respository link: https://github.com/SimonMatz/SimonMatz-Assessment-3---Question-1

#include "BST.h"
#include <fstream>

void BST::insert(Node* newNumber)
{
	// if the tree is empty newNumber will become root
	if (root == NULL)
	{
		root = newNumber;
		return;
	}
	// to navigate through tree and find correct spot to insert numbers
	Node* current = root;
	Node* parent = NULL;

	while (true)
	{
		parent = current;

		//going left if new number is less than current number
		if (newNumber->number < current->number)
		{
			current = current->leftChild;

			//finding empty space to add new number
			if (current == NULL)
			{
				parent->leftChild = newNumber;
				return;
			}
		}
		//going right down the tree
		else
		{
			current = current->rightChild;
			
			if (current == NULL)
			{
				parent->rightChild = newNumber;
				return;
			}
		}
	}
}

void BST::show(Node* p)
{
	ofstream  writeFile;
	writeFile.open("output-q1-a2.txt");

	if (root == NULL)  return;

	// Creating empty queue 
	queue<LevelNode> q;

	//Adding root to queue and setting height
	q.push(LevelNode(root, 0));

	int previousOutputLevel = -1;

	while (q.empty() == false)
	{
		LevelNode node = q.front();
		if (node.level != previousOutputLevel)
		{
			writeFile << endl;
			writeFile << node.level << ": ";

			previousOutputLevel = node.level;
		}
		writeFile << node.number1->number << " ";
		q.pop();

		//Enqueue left child
		if (node.number1->leftChild != NULL)
			q.push(LevelNode(node.number1->leftChild, node.level + 1));

		//Enqueue right child
		if (node.number1->rightChild != NULL)
			q.push(LevelNode(node.number1->rightChild, node.level + 1));
	}
	writeFile.close();
}
