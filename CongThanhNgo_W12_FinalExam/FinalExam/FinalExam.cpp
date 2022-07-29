// COS30008, Final Exam, 2021
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#define P1
#define P2
#define P3
//#define P4
#ifdef P1
#include "TTree.h"
void runP1()
{
    cout << "Test P1:" << endl;
    using S3Tree = TTree<string>;

    string s1("A");
    string s2("B");
    string s3("C");
    string s4("D");
    string s5("E");
    S3Tree tree(s1);
    S3Tree nB(s2);
    S3Tree nC(s3);
    S3Tree nD(s4);
    S3Tree nE(s5);

    tree.addLeft(nB);
    tree.addRight(nC);
    nB.addMiddle(nD);
    nC.addMiddle(nE);
    cout << "The payload of tree: " << *tree << endl;
    cout << "The payload of tree.getLeft():\t" << *tree.getLeft() << endl;
    cout << "The payload of tree.getRight():\t" << *tree.getRight() << endl;
    if (nD.leaf())
    {
        cout << "nD is a leaf node." << endl;
    }
    else
    {
        cout << "You should not see this message as nD is a leaf node." << endl;
    }

    try
    {
        *tree.getMiddle();
    }
    catch (domain_error e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    nB.removeMiddle();
    nC.removeMiddle();
    tree.removeLeft();
    tree.removeRight();

    cout << "Test P1 complete." << endl;
}
#endif
#ifdef P2
#include "TTree.h"
void runP2()
{
    cout << "Test P2:" << endl;
    using S3Tree = TTree<string>;

    string s1("A");
    string s2("B");
    string s3("C");
    string s4("D");
    string s5("E");
    S3Tree tree(s1);
    S3Tree* nB = new S3Tree(s2);
    S3Tree* nC = new S3Tree(s3);
    S3Tree* nD = new S3Tree(s4);
    S3Tree* nE = new S3Tree(s5);
    tree.addLeft(*nB);
    tree.addRight(*nC);
    nB->addMiddle(*nD);
    nC->addMiddle(*nE);
    S3Tree copy = tree;

    if (&tree.getLeft().getMiddle() == &copy.getLeft().getMiddle())
    {
        cout << "Error: shallow copy detected." << endl;
    }
    else
    {
        cout << "Copy constructor appears to work properly." << endl;
    }
    tree = copy;

    if (&tree.getLeft().getMiddle() == &copy.getLeft().getMiddle())
    {
        cout << "Error: shallow copy detected." << endl;
    }
    else
    {
        cout << "Assignment appears to work properly." << endl;
    }

    try
    {
        tree = S3Tree::NIL;

        cout << "Copy of NIL! You should not see this message." << endl;
    }
    catch (domain_error e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    S3Tree* clone = tree.clone();
    if (&tree.getLeft().getMiddle() == &clone->getLeft().getMiddle())
    {
        cout << "Error: shallow copy detected." << endl;
    }
    else
    {
        cout << "Clone appears to work properly." << endl;
    }
    delete clone;

    cout << "Test P2 complete." << endl;
}
#endif
#ifdef P3
#include "TTree.h"
void runP3()
{
    cout << "Test P3:" << endl;
    using S3Tree = TTree<string>;

    string s1("A");
    string s2("B");
    string s3("C");
    string s4("D");
    string s5("E");
    S3Tree tree("A");
    S3Tree* nB = new S3Tree("B");
    S3Tree* nC = new S3Tree("C");
    S3Tree* nD = new S3Tree("D");
    S3Tree* nE = new S3Tree("E");
    tree.addLeft(*nB);
    tree.addRight(*nC);
    nB->addMiddle(*nD);
    nC->addMiddle(*nE);
    S3Tree copy = std::move(tree);

    if (tree.leaf())
    {
        cout << "std::move makes tree a leaf node." << endl;
    }
    else
    {
        cout << "You should not see this message as tree must become a leaf node."
            << endl;
    }

    cout << "The payload of tree: " << *copy << endl;
    cout << "The payload of tree.getLeft():\t" << *copy.getLeft() << endl;
    cout << "The payload of tree.getRight():\t" << *copy.getRight() << endl;
    tree = std::move(copy);

    if (copy.leaf())
    {
        cout << "std::move makes copy a leaf node." << endl;
    }
    else
    {
        cout << "You should not see this message as copy must become a leaf node."
            << endl;
    }
    cout << "The payload of tree: " << *tree << endl;
    cout << "The payload of tree.getLeft():\t" << *tree.getLeft() << endl;
    cout << "The payload of tree.getRight():\t" << *tree.getRight() << endl;
    try
    {
        tree = std::move(S3Tree::NIL);

        cout << "Move of NIL! You should not see this message." << endl;
    }
    catch (domain_error e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    cout << "Test P3 complete." << endl;
}
#endif
#ifdef P4
#include "TTree.h"
#include "TTreePostfixIterator.h"
void runP4()
{
    using S3Tree = TTree<string>;

    string s1("A");
    string s2("B");
    string s3("E");
    string s4("G");
    S3Tree tree(s1);
    S3Tree* nB = new S3Tree(s2);
    S3Tree* nC = new S3Tree("C");
    S3Tree* nD = new S3Tree("D");
    S3Tree* nE = new S3Tree(s3);
    S3Tree* nF = new S3Tree("F");
    S3Tree* nG = new S3Tree(s4);
    nE->addMiddle(*nG);
    nC->addRight(*nE);
    nD->addLeft(*nF);
    tree.addLeft(*nB);
    tree.addMiddle(*nD);
    tree.addRight(*nC);
    cout << "Test postfix iterator:";

    for (const string& k : tree)
    {
        cout << ' ' << k;
    }

    cout << endl;
}
#endif
int main()
{
#ifdef P1
    runP1();
#endif
#ifdef P2
    runP2();
#endif
#ifdef P3
    runP3();
#endif
#ifdef P4
    runP4();
#endif
    return 0;
}
