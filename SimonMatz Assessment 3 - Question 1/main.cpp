#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include "AVL.h"

using namespace std;

void main()
{
	//reading from input file
	ifstream readFile;
	readFile.open("input-q1-a2.txt");

	int amountOfNumbers;

	readFile >> amountOfNumbers;

	//using pointers to create dynamic size array
	int* numbersToInsert = new int[amountOfNumbers];
	//variable for looping through array
	int count1 = 0;

	//looping through line 4 until end of file and storing numbers in array
	while (!readFile.eof())
	{
		readFile >> numbersToInsert[count1];
		count1++;
	}

	readFile.close();

	//creating empty AVL tree
	AVL avl1;

	for (int i = 0; i < amountOfNumbers; i++)
	{
		avl1.insert(new Node(numbersToInsert[i]));	
	}
	
	avl1.show(avl1.root);


	cout << "\n\n\n";

	//deleting the temp array to avoid memory leak
	delete[] numbersToInsert;
	
}
