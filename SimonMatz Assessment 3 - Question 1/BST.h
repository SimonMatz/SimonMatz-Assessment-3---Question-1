#pragma once
#include <queue>
#include "Node.h"

class BST
{
	public:
		Node* root = NULL;
		virtual void insert(Node* newNumber);
		Node* search(int number, bool showSearchpath = false);

		void inOrderTraversal(Node* current);
		void preOrderTraversal(Node* current);
		void postOrderTraversal(Node* current);

};

