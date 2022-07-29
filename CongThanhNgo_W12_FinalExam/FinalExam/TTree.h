// COS30008, Final Exam, 2021
#pragma once
#include <stdexcept>

using namespace std;

template<typename T>
class TTreePostfixIterator;
template<typename T>
class TTree
{
private:

    T fKey;
    TTree<T>* fLeft;
    TTree<T>* fMiddle;
    TTree<T>* fRight;

    TTree() : fKey(T())     // use default constructor to initialize fKey
    {
        fLeft = &NIL;       // loop-back: The sub-trees of a TTree object with
        fMiddle = &NIL;     //            no children point to NIL.
        fRight = &NIL;
    }

    void addSubTree(TTree<T>** aBranch, const TTree<T>& aTTree)
    {
        if (!(*aBranch)->empty())
        {
            delete* aBranch;
        }
        *aBranch = const_cast<TTree<T>*>(&aTTree);
    }
public:
    using Iterator = TTreePostfixIterator<T>;

    static TTree<T> NIL;    // sentinel
    // getters for subtrees
    const TTree<T>& getLeft() const { return *fLeft; }
    const TTree<T>& getMiddle() const { return *fMiddle; }
    const TTree<T>& getRight() const { return *fRight; }
    // add a subtree
    void addLeft(const TTree<T>& aTTree) { addSubTree(&fLeft, aTTree); }
    void addMiddle(const TTree<T>& aTTree) { addSubTree(&fMiddle, aTTree); }
    void addRight(const TTree<T>& aTTree) { addSubTree(&fRight, aTTree); }

    // remove a subtree, may through a domain error
    const TTree<T>& removeLeft() { return removeSubTree(&fLeft); }
    const TTree<T>& removeMiddle() { return removeSubTree(&fMiddle); }
    const TTree<T>& removeRight() { return removeSubTree(&fRight); }
    // Problem 1: TTree Basic Infrastructure
private:
    // remove a subtree, may through a domain error
    const TTree<T>& removeSubTree(TTree<T>** aBranch) {
        if (!(*aBranch)->empty()) {
            *aBranch = &NIL; 
        }
        return *this;
    }

public:

    // TTree l-value constructor
    TTree(const T& aKey) : fKey(aKey){
        fLeft = &NIL;
        fRight = &NIL;
        fMiddle = &NIL;
    }

    // destructor (free sub-trees, must not free empty trees)
    ~TTree() {
        if (this->empty()) {
            throw domain_error("Empty TTree encountered. ");
        }
        if (!fLeft->empty()) {
            fLeft = &NIL;
        }
        if (!fRight->empty()) {
            fRight = &NIL;
        }
        if (!fMiddle->empty()) {
            fMiddle = &NIL;
        }
    }

    // return key value, may throw domain_error if empty
    const T& operator*() const {
        if (this->empty()) {
            throw domain_error("Empty TTree encountered.");
        }
        return fKey; 
    }
    // returns true if this TTree is empty
    bool empty() const {
        return this==&NIL; 
    }
    // returns true if this TTree is a leaf
    bool leaf() const {
        return fLeft == &NIL && fRight == &NIL && fMiddle == &NIL; 
    }

    // Problem 2: TTree Copy Semantics

        // copy constructor, must not copy empty TTree
    TTree(const TTree<T>& aOtherTTree) : fKey(move(aOtherTTree.fKey)){
        if (empty()) {
            throw domain_error("Copying NIL. ");
        }

        fLeft = const_cast<TTree<T>&>(aOtherTTree.getLeft()).clone();
        fMiddle = const_cast<TTree<T>&>(aOtherTTree.getMiddle()).clone();
        fRight = const_cast<TTree<T>&>(aOtherTTree.getRight()).clone();
    }
    // copy assignment operator, must not copy empty TTree
    TTree<T>& operator=(const TTree<T>& aOtherTTree) {
        if (&aOtherTTree == &NIL) {
            throw domain_error("Copying NIL. ");
        }
        if (&aOtherTTree != this)
        {
            fKey = aOtherTTree.fKey;
            if (fLeft != &NIL) {
                delete fLeft;
            }
            if (fMiddle != &NIL) {
                delete fMiddle;
            }
            if (fRight != &NIL) {
                delete fRight;
            }

      

            fLeft = const_cast<TTree<T>&>(aOtherTTree.getLeft()).clone();
            fMiddle = const_cast<TTree<T>&>(aOtherTTree.getMiddle()).clone();
            fRight = const_cast<TTree<T>&>(aOtherTTree.getRight()).clone();
        }
        return *this;
    }

    // clone TTree, must not copy empty trees
    TTree<T>* clone() const {
        if (!empty()) {
            return new TTree(*this);
        }
        else {
            return &NIL;
        }

    }
    // Problem 3: TTree Move Semantics
        // TTree r-value constructor
    TTree(T&& aKey) : fKey(move(aKey)), fLeft(&NIL), fMiddle(&NIL), fRight(&NIL) {}

    // move constructor, must not copy empty TTree
    TTree(TTree<T>&& aOtherTTree) {
        if (&aOtherTTree == &NIL)
        {
            throw std::domain_error("Moving NIL.");
        }

        *this = move(aOtherTTree);
    }

    // move assignment operator, must not copy empty TTree
    TTree<T>& operator=(TTree<T>&& aOtherTTree) {
        if (&aOtherTTree != this)
        {
            fKey = move(aOtherTTree.fKey);

            if (fLeft != &NIL) {
                delete fLeft;
            }
            if (fMiddle != &NIL) {
                delete fMiddle;
            }
            if (fRight != &NIL) {
                delete fRight;
            }

            fLeft = const_cast<TTree<T>&>(aOtherTTree.getLeft()).clone();
            fMiddle = const_cast<TTree<T>&>(aOtherTTree.getMiddle()).clone();
            fRight = const_cast<TTree<T>&>(aOtherTTree.getRight()).clone();
        }
        return *this;
    }

    // Problem 4: TTree Postfix Iterator
        // return TTree iterator positioned at start
    Iterator begin() const {

    }
    // return TTree iterator positioned at end
    Iterator end() const;
};
template<typename T>
TTree<T> TTree<T>::NIL;

