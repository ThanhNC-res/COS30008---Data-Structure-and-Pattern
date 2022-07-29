// COS30008, Final Exam, 2021
#pragma once
#include "TTree.h"
#include <stack>
template<typename S>
struct TTreeFrontier
{
    size_t stage;                           // frontier stages: 0, 1, 2
    const TTree<S>* node;                   // frontier TTree node

    TTreeFrontier(const TTree<S>* aNode) :
        node(aNode),                        // TTree node
        stage(0)                            // 0 - start right
    {}
};
template<typename T>
class TTreePostfixIterator
{
private:
    const TTree<T>* fTTree;                 // 3-way tree
    std::stack<TTreeFrontier<T>> fStack;    // DFS traversal stack
    using Frontier = TTreeFrontier<T>;
    // push subtree starting with aNode
    void push_nodes(const TTree<T>* aNode);

public:
    using Iterator = TTreePostfixIterator<T>;

    Iterator operator++(int)
    {
        Iterator old = *this;
        ++(*this);

        return old;
    }

    bool operator!=(const Iterator& aOtherIter) const
    {
        return !(*this == aOtherIter);
    }
    // iterator constructor
    TTreePostfixIterator(const TTree<T>* aTTree);
    // iterator dereference
    const T& operator*() const;
    // prefix increment
    Iterator& operator++();
    // iterator equivalence
    bool operator==(const Iterator& aOtherIter) const;
    // auxiliaries
    Iterator begin() const;
    Iterator end() const;
};
