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
    if (displayRotations)
        cout << "RR rotation on " << parent->number << endl;

    return temp;
}

Node* AVL::LLrotation(Node* parent)
{
    Node* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
    if (displayRotations)
        cout << "RR rotation on " << parent->number << endl;

    return temp;
}

Node* AVL::LRrotation(Node* parent)
{
    Node* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);
    if (displayRotations)
        cout << "LR rotation on " << parent->number << endl;
    return LLrotation(parent);
}

Node* AVL::RLrotation(Node* parent)
{
    Node* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);
    if (displayRotations)
        cout << "RL rotation on " << parent->number << endl;
    return RRrotation(parent);
}

Node* AVL::balance(Node* parent)
{
    
    int balanceFactor = difference(parent);

    
    if (balanceFactor > 1)
    {
        
        if (difference(parent->leftChild) > 0)
        {            
            parent = LLrotation(parent);
        }
        else
        {
            parent = LRrotation(parent);
        }
    }
    else if (balanceFactor < -1)
    {
        if (difference(parent->rightChild) > 0)
        {           
            parent = RLrotation(parent);
        }
        else
        {
            parent = RRrotation(parent);
        }
    }

    return parent;
}

Node* AVL::insertAVL(Node* parent, Node* newNumber)
{
    if (parent == NULL)
    {
        parent = newNumber;
        return parent;
    }

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
    cout << "Inserting " << newNumber->number << endl;
    root = insertAVL(root, newNumber);
    cout << endl;
}
