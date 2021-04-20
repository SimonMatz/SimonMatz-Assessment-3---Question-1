#pragma once
#include "BST.h"

class AVL : public BST
{
public:

	int height(Node* node);
	int difference(Node* node);

	Node* RRrotation(Node* parent);
	
	Node* LLrotation(Node* parent);
	
	Node* LRrotation(Node* parent);
	
	Node* RLrotation(Node* parent);

	Node* balance(Node* parent);

	Node* insertAVL(Node* parent, Node* newNumber);

	void insert(Node* newNumber);

};

