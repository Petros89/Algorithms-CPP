#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
Node(int value, Node* left, Node* right)
{
    this->value = value;
    this->left = left;
    this->right = right;
}

int getValue() const
{
    return value;
}

Node* getLeft() const
{
    return left;
}

Node* getRight() const
{
    return right;
}

private:
int value;
Node* left;
Node* right;
};

class BinarySearchTree
{
public:
static bool contains(const Node& root, int value)
{
    Node* tree;
    int val = root.getValue();
    std::cout<<"current node's value is:"<<val<<'\n';

        if (val==value)
        {
            return true;
        }
        else if (val>value)
        {
            tree = root.getLeft();                
            if(tree != NULL)
            {
                std::cout<<"left node's value is:"<<tree->getValue()<<'\n';
                return contains(*tree, value);
            }
            else 
            {
                return false;
            }
        }
        else
        {
            tree = root.getRight();
            if(tree != NULL)
            {
                std::cout<<"right node's value is:"<<tree->getValue()<<'\n';
                return contains(*tree, value);
            }
            else 
            {
                return false;
            }
        }      
    //throw std::logic_error("Waiting to be implemented");
   }   
};

#ifndef RunTests
int main()
{
Node n1(1, NULL, NULL);
Node n3(3, NULL, NULL);
Node n2(2, &n1, &n3);
std::cout << BinarySearchTree::contains(n2, 3);
}
#endif
