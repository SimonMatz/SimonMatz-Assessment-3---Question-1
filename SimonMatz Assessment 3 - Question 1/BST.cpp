#include "BST.h"
#include <fstream>

void BST::insert(Node* newNumber)
{

	if (root == NULL)
	{
		root = newNumber;
		return;
	}

	Node* current = root;
	Node* parent = NULL;

	while (true)
	{
		parent = current;

		if (newNumber->number < current->number)
		{
			current = current->leftChild;

			if (current == NULL)
			{
				parent->leftChild = newNumber;
				return;
			}
		}
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

Node* BST::search(int number, bool showSearchPath)
{
	if (root == NULL)
	{
		return NULL;
	}
	
	Node* current = root;

	while (current->number != number)
	{

		if (showSearchPath)
			cout << current->number << endl;

		if (number < current->number)
		{
			current = current->leftChild;
		}
		else
		{
			current = current->rightChild;
		}

		if (current == NULL)
		{
			return NULL;
		}
	}

	return current;
}

void BST::inOrderTraversal(Node* current)
{
	if (current != NULL)
	{
		inOrderTraversal(current->leftChild);
		cout << current->number << " " << endl;
		inOrderTraversal(current->rightChild);
	}
}

void BST::preOrderTraversal(Node* current)
{
	if (current != NULL)
	{
		cout << current->number << " " << endl;
		preOrderTraversal(current->leftChild);
		preOrderTraversal(current->rightChild);
	}
}

void BST::postOrderTraversal(Node* current)
{
	if (current != NULL)
	{
		postOrderTraversal(current->leftChild);
		postOrderTraversal(current->rightChild);
		cout << current->number << " " << endl;
	}
}

void BST::show(Node* p)
{
	ofstream  writeFile;
	writeFile.open("output-q1-a2.txt");

	if (root == NULL)  return;

	queue<LevelNode> q;

	q.push(LevelNode(root, 0));

	int previousOutputLevel = -1;

	while (q.empty() == false)
	{

		LevelNode node = q.front();
		if (node.level != previousOutputLevel)
		{
			cout << endl;
			cout << node.level << ": ";
			writeFile << endl;
			writeFile << node.level << ": ";


			previousOutputLevel = node.level;
		}
		cout << node.number1->number << " ";
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
