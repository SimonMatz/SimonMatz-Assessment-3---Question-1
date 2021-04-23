#pragma once
#include "BST.h"

class AVL : public BST
{
public:

	// calculates the height of the sub tree
	int height(Node* node);
	// calculates the difference between the left and the right sub tree
	int difference(Node* node);
	// right branch, right child
	Node* RRrotation(Node* parent);
	// left branch, left child
	Node* LLrotation(Node* parent);
	// left branch, right child
	Node* LRrotation(Node* parent);
	// right branch, left child
	Node* RLrotation(Node* parent);
	// returns the new parent after the rotations
	Node* balance(Node* parent);
	// inserts and returns the tree's new root node
	Node* insertAVL(Node* parent, Node* newNumber);
	// overriding insert
	void insert(Node* newNumber);
};

