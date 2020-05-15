
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

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
        cout << root.getValue() << " ";
        if (root.getValue() == value){
         cout << "\n";
         return true;
        }

        else if (root.getLeft() && (value < root.getValue()))
         return contains(*root.getLeft(),value);

        else if (root.getRight() && (value > root.getValue()))
         return contains(*root.getRight(),value);

        else
         return false;
    }
};

#ifndef RunTests
int main()
{
    Node n1(1, NULL, NULL);
    Node n3(3, NULL, NULL);
    Node n2(2, &n1, &n3);


    cout << boolalpha << BinarySearchTree::contains(n2, 3) << "\n";
    return 0;
}
#endif
