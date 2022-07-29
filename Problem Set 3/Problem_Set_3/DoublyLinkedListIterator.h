
// COS30008, Doubly-linked Node Iterator, 2021

#pragma once

#include "DoublyLinkedList.h"

template<typename T>
class DoublyLinkedListIterator
{
private:
	enum class States { BEFORE, DATA , AFTER };					// iterator states

	using Node = DoublyLinkedList<T>;

	const Node* fRoot;											// doubly-linked list

    States fState;												// iterator state
    const Node* fCurrent;										// iterator position
    
public:
    
	using Iterator = DoublyLinkedListIterator<T>;

	// constructor
	DoublyLinkedListIterator(const Node* aRoot) {
		fRoot = aRoot;
		fCurrent = fRoot;

		if (fCurrent != nullptr)
		{
			fState = States::DATA;
		}
		else
		{
			// empty doubly linked list of nodes
			fState = States::AFTER;
		}
	}

	// dereference    
	const T& operator*() const {
		return **fCurrent;
	}
	// prefix increment
	Iterator& operator++() {
        switch (fState)
        {
        case States::BEFORE:

            fCurrent = fRoot;   // set to first element

            if (fCurrent == nullptr)
            {
                fState = States::AFTER;
            }
            else
            {
                fState = States::DATA;
            }

            break;

        case States::DATA:

            // Is current previous of root (last element forward)?
            // Current cannot be nullptr as we are in state DATA.
            if (fCurrent == &fRoot->getPrevious())
            {
                // Yes, we are done
                fCurrent = nullptr;
                fState = States::AFTER;
            }
            else
            {
                // No, we can advance
                fCurrent = &fCurrent->getNext();
            }

            break;

        default:

            break;
        }

        return *this;
	}
	// postfix increment
	Iterator operator++(int) {
		Iterator temp = *this;

		++(*this);

		return temp;
	}
	// prefix decrement
	Iterator& operator--() {
        switch (fState)
        {
        case States::AFTER:

            fCurrent = fRoot;

            if (fCurrent == nullptr)
            {
                fState = States::BEFORE;
            }
            else
            {
                fCurrent = &fCurrent->getPrevious();    // set to last element
                fState = States::DATA;
            }

            break;

        case States::DATA:

            // Is current root (last element backwards)?
            // Current cannot be nullptr as we are in state DATA.

            if (fCurrent == fRoot)
            {
                // Yes, we are done
                fCurrent = nullptr;
                fState = States::BEFORE;
            }
            else
            {
                // No, we can advance
                fCurrent = &fCurrent->getPrevious();
            }

            break;

        default:

            break;
        }

        return *this;
	}
	// postfix decrement
    Iterator operator--(int) {
        Iterator temp = *this;

        --(*this);

        return temp;
    }
	// equivalence
    bool operator==(const Iterator& aOtherIter) const {
        return
            fRoot == aOtherIter.fRoot &&
            fCurrent == aOtherIter.fCurrent &&
            fState == aOtherIter.fState;
    }
	// not equal
    bool operator!=(const Iterator& aOtherIter) const {
        return !(*this == aOtherIter);
    }

    // first element forward
    Iterator begin() const {
        return ++(rend());
    }
    
    // after last element forward
    Iterator end() const {
        Iterator iterator = *this;

        iterator.fCurrent = nullptr;
        iterator.fState = States::AFTER;

        return iterator;
    }

    // first element backwards
    Iterator rbegin() const {
        return --(end());
    }

    // before first element backwards
    Iterator rend() const {	
        Iterator iterator = *this;

        iterator.fCurrent = nullptr;
        iterator.fState = States::BEFORE;

        return iterator;
    }
};
