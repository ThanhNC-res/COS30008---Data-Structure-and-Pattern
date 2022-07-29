#include <iostream>
using namespace std;
#define P1
#define P2
#define P3
#ifdef P1
#include "BNode.h"
void testBNode()
{
    BNode<int>* lRoot = &BNode<int>::NIL;

    cout << "Test BNode" << endl;

    if (lRoot->insert(25))
    {
        cerr << "This message must not appear!" << endl;
    }
    int lValues[] = { 25, 10, 15, 37, 10, 30, 65 };

    lRoot = new BNode<int>(lValues[0]);
    cout << "insert of " << lValues[0] << " as root." << endl;
    for (size_t i = 1; i < sizeof(lValues) / sizeof(int); i++)
    {
        if (lRoot->insert(lValues[i]))
        {
            cout << "insert of " << lValues[i] << " succeeded." << endl;
        }
        else
        {
            cout << "insert of " << lValues[i] << " failed." << endl;
        }
    }
    cout << "Height of tree: " << lRoot->height() << endl;

    cout << "Delete BNode tree" << endl;

    if (!lRoot->empty())
    {
        delete lRoot;
    }
    else
    {
        cerr << "This message must not appear!" << endl;
    }

    cout << "Test BNode completed." << endl;

}
#endif
#ifdef P2
#include "BinarySearchTree.h"
void testBinarySearchTree()
{
    cout << "Test Binary Search Tree" << endl;
    BinarySearchTree<int> lTree;
    int lValues[] = { 25, 10, 15, 37, 10, 30, 65 };
    for (size_t i = 0; i < sizeof(lValues) / sizeof(int); i++)
    {
        if (lTree.insert(lValues[i]))
        {
            cout << "insert of " << lValues[i] << " succeeded." << endl;
        }
        else
        {
            cout << "insert of " << lValues[i] << " failed." << endl;
        }
    }
    cout << "Height of tree: " << lTree.height() << endl;

    cout << "Delete binary search tree now." << endl;
    cout << "Test Binary Search Tree completed." << endl;
}
#endif
#ifdef P3

#include "BinarySearchTreeIterator.h"
#include "BinarySearchTree.h"
void testIterator()
{
    cout << "Test Binary Search Tree Iterator DFS" << endl;
    BinarySearchTree<int> lTree;
    int lValues[] = { 25, 10, 15, 37, 10, 30, 65, 8 };
    for (size_t i = 0; i < sizeof(lValues) / sizeof(int); i++)
    {
        if (lTree.insert(lValues[i]))
        {
            cout << "insert of " << lValues[i] << " succeeded." << endl;
        }
        else
        {
            cout << "insert of " << lValues[i] << " failed." << endl;
        }
    }

    cout << "DFS:";

    for (const int& i : lTree)
    {
        cout << " " << i;
    }
    cout << endl;
    cout << "Test Binary Search Tree Iterator DFS completed." << endl;
}

#endif
int main()
{
#ifdef P1

    testBNode();

#endif
#ifdef P2

    testBinarySearchTree();

#endif
#ifdef P3

    testIterator();

#endif
    return 0;
}
