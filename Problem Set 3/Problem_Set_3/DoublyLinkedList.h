
// COS30008, Doubly-linked Nodes, 2021
#include "iostream"
#pragma once

template<typename T>
class DoublyLinkedList
{
private:

    T fPayload;													// payload
    DoublyLinkedList* fNext;									// next element
    DoublyLinkedList* fPrevious;								// previous element

public:

    explicit DoublyLinkedList(const T &aPayload) : fPayload(aPayload), fNext(this), fPrevious(this) {}			// l-value constructor
    explicit DoublyLinkedList(T &&aPayload) :fPayload(std::move(aPayload)), fNext(this), fPrevious(this) {}				// r-value constructor

    // aNode becomes previous of this
    DoublyLinkedList& push_front(DoublyLinkedList& aNode) {
        aNode.fNext = this;                     // make this the forward pointer of aNode

        aNode.fPrevious = fPrevious;            // make this's backward pointer aNode's
        fPrevious->fNext = &aNode;              // tie back to Node

        fPrevious = &aNode;                     // this' backward pointer becomes aNode

        return aNode;                           // last node inserted
    }

    // aNode becomes next of this    
    DoublyLinkedList& push_back(DoublyLinkedList& aNode) {
        aNode.fPrevious = this;                 // make this the backwards pointer of aNode

        aNode.fNext = fNext;                    // make this's forward pointer aNode's
        fNext->fPrevious = &aNode;              // tie back to Node

        fNext = &aNode;                         // this' forward pointer becomes aNode

        return aNode;
    }

    // removes this node
    void isolate() {
        fPrevious->fNext = fNext;               // unlink previous
        fNext->fPrevious = fPrevious;           // unlink next

        fPrevious = this;                       // isolate this node
        fNext = this;
    }

    // exchange payloads
    void swap(DoublyLinkedList& aNode) {
        std::swap(fPayload, aNode.fPayload);    // exchange list elements
    }

    // dereference operator, payload
    const T& operator*() const {
        return getPayload();
    }

    // returns constant reference to paylod
    const T& getPayload() const {
        return fPayload;
    }
    // returns constant reference to next
    const DoublyLinkedList& getNext() const {
        return *fNext;
    }
    // returns constant reference to previous
    const DoublyLinkedList& getPrevious() const {
        return *fPrevious;
    }
};