#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int number;
	Node* leftChild;
	Node* rightChild;

	Node(int number);
};

