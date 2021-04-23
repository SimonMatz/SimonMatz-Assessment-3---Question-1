#pragma once
#include <queue>
#include "Node.h"

//Class for breadth first traversal
class LevelNode
{
	public:
		Node* number1;
		int level;

		LevelNode(Node* number1, int level)
		{
			this->number1 = number1;
			this->level = level;
		}
};

class BST
{
	public:

		Node* root = NULL;
		virtual void insert(Node* newNumber);

		//outputs tree in breadth-first traversal
		void show(Node* p);
};

