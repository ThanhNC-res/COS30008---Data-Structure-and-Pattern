#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

#include <stdexcept>

using namespace std;
template<typename T>
class List
{
private:
    // auxiliary definition to simplify node usage
    using Node = DoublyLinkedList<T>;

    Node* fRoot;	// the first element in the list
    size_t fCount;	// number of elements in the list

public:
    // auxiliary definition to simplify iterator usage
    using Iterator = DoublyLinkedListIterator<T>;

    // destructor - frees all nodes
    ~List()                                
    {
        while (fRoot != nullptr)
        {
            if (fRoot != &fRoot->getPrevious())                       // more than one element
            {
                Node* lTemp = const_cast<Node*>(&fRoot->getPrevious()); // select last

                lTemp->isolate();                                       // remove from list
                delete lTemp;                                           // free
            }
            else
            {
                delete fRoot;                                           // free last
                break;                                                  // stop loop
            }
        }
    }

    // remove first match from list
    void remove(const T& aElement)	                                
    {
        Node* lTemp = fRoot;                                            // start at first

        while (lTemp != nullptr)                                      // Are there still nodes available?
        {
            if (**lTemp == aElement)                                  // Have we found the node?
            {
                break;                                                  // stop the search
            }

            if (lTemp != &fRoot->getPrevious())                       // not reached last
            {
                lTemp = const_cast<Node*>(&lTemp->getNext());           // go to next
            }
            else
            {
                lTemp = nullptr;                                        // stop search
            }
        }

        // At this point we have either reached the end or found the node.
        if (lTemp != nullptr)                                         // We have found the node.
        {
            if (fCount != 1)                                          // not the last element
            {
                if (lTemp == fRoot)
                {
                    fRoot = const_cast<Node*>(&fRoot->getNext());       // make next root
                }
            }
            else
            {
                fRoot = nullptr;                                        // list becomes empty
            }

            lTemp->isolate();                                           // isolate node
            delete lTemp;                                               // release node's memory
            fCount--;                                                   // decrement count
        }
    }

    // PS3 starts here

    // P1

    // default constructor
    List() :
        fRoot(nullptr),
        fCount(0) {}                                                   

    // Is list empty?
    bool isEmpty() const	           
    {
        return fRoot == nullptr;
    }

    // list size
    size_t size() const                					    			
    {
        return fCount + 1;
    }

    // adds aElement at front
    void push_front(const T& aElement)	    			    			
    {
        if (isEmpty()) {
            fRoot = new Node(aElement);
            return;
        }
        Node* lTempInsert = new Node(aElement);
        *fRoot->push_front(*lTempInsert);
        fRoot = lTempInsert;
        fCount++;
    }

    // return a forward iterator
    Iterator begin() const                       						
    {
        Iterator iterator(fRoot);
        return iterator.begin();
    }

    // return a forward end iterator
    Iterator end() const                           						
    {
        Iterator iterator(fRoot);
        return iterator.end();
    }

    // return a backwards iterator
    Iterator rbegin() const                     					
    {
        Iterator iterator(fRoot);
        return iterator.rbegin();
    }

    // return a backwards end iterator
    Iterator rend() const                      			
    {
        Iterator iter(fRoot);
        return iterator.rend();
    }

    // P2

    // adds aElement at back
    void push_back(const T& aElement)              						
    {
        if (isEmpty()) {
            fRoot = new Node(aElement);
            return;
        }
        Node* lTempInsert = new Node(aElement);
        const_cast<Node*>(&fRoot->getPrevious())->push_back(*lTempInsert);
        fCount++;
    }

    // P3

    // list indexer
    const T& operator[](size_t aIndex) const							
    {
        if (aIndex > fCount)
            throw range_error("Index is out of range.");

        Node* lCurrentNode = fRoot;
        int lCount = 0;
        while (lCurrentNode != nullptr)
        {
            if (lCount == aIndex)
                return lCurrentNode->getPayload();
            lCount++;
            lCurrentNode = const_cast<Node*>(&lCurrentNode->getNext());
        }
    }

    // P4
    // copy constructor
    List(const List& aOtherList) :
        fRoot(nullptr),
        fCount(0)
    {
        for (size_t i = 0; i < aOtherList.size(); i++)
            push_back(aOtherList[i]);
    }

    // assignment operator
    List& operator=(const List& aOtherList) 
    {
        for (size_t i = 0; i < size(); i++)
            remove(operator[](i));

        for (size_t i = 0; i < aOtherList.size(); i++)
            push_back(aOtherList[i]);

        return *this;
    }

    // P5X

    // move features

     // move constructor
    List(List&& aOtherList) :
        fRoot(nullptr),
        fCount(0)    	                            
    {
        for (size_t i = 0; i < aOtherList.size(); i++)
            push_back(aOtherList[i]);
    }

    // move assignment operator
    List& operator=(List&& aOtherList)           						
    {
        operator=(aOtherList);
        return *this;
    }

    // adds aElement at front
    void push_front(T&& aElement)        
    {
        push_front(aElement);
    }

    // adds aElement at back
    void push_back(T&& aElement)           
    {
        push_back(aElement);
    }
};

