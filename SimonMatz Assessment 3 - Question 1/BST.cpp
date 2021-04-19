#include "BST.h"

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
