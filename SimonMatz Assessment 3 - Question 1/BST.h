#pragma once
#include <queue>
#include "Node.h"

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
		Node* search(int number, bool showSearchpath = false);

		void inOrderTraversal(Node* current);
		void preOrderTraversal(Node* current);
		void postOrderTraversal(Node* current);

		void show(Node* p);
};

