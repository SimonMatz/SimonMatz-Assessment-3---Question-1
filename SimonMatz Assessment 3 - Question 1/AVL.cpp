//Simon Matz A00018077 Assessment 3 - Question 1
//Github respository link: https://github.com/SimonMatz/SimonMatz-Assessment-3---Question-1

#include "AVL.h"

int AVL::height(Node* node)
{
    int h = 0;
    
    if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);

        int maxH = max(leftH, rightH);
        h = maxH + 1;
    }
    return h;
}

int AVL::difference(Node* node)
{
    //returns 0 when tree is empty
    if (node == NULL)
        return 0;

    int leftH = height(node->leftChild);
    int rightH = height(node->rightChild);
    int balanceFactor = leftH - rightH;

    return balanceFactor;
}

Node* AVL::RRrotation(Node* parent)
{
    Node* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;
    
    return temp;
}

Node* AVL::LLrotation(Node* parent)
{
    Node* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
    
    return temp;
}

Node* AVL::LRrotation(Node* parent)
{
    Node* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);
    
    return LLrotation(parent);
}

Node* AVL::RLrotation(Node* parent)
{
    Node* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);
   
    return RRrotation(parent);
}

Node* AVL::balance(Node* parent)
{
    int balanceFactor = difference(parent);

    if (balanceFactor > 1)
    {
        if (difference(parent->leftChild) > 0)
        {    
            //left child unbalanced
            parent = LLrotation(parent);
        }
        else
        {
            //right child unbalanced
            parent = LRrotation(parent);
        }
    }
    //right branch is the heavy one, checking which child
    else if (balanceFactor < -1)
    {
        if (difference(parent->rightChild) > 0)
        {   
            //left child is heavy      
            parent = RLrotation(parent);
        }
        else
        {
            //right child is heavy  
            parent = RRrotation(parent);
        }
    }
    return parent;
}

Node* AVL::insertAVL(Node* parent, Node* newNumber)
{
    // becomes the parent if sub tree is empty
    if (parent == NULL)
    {
        parent = newNumber;
        return parent;
    }
    // parent is not null - no empty space for new number - go down left or right
    if (newNumber->number < parent->number)
    {
        parent->leftChild = insertAVL(parent->leftChild, newNumber);
        parent = balance(parent);
    }
    else
    {
        parent->rightChild = insertAVL(parent->rightChild, newNumber);
        parent = balance(parent);
    }
}

void AVL::insert(Node* newNumber)
{
    root = insertAVL(root, newNumber);  
}
