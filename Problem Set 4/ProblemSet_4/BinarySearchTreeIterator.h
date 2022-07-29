#pragma once

#include <stack>

#include "BNode.h"

template<typename T>
class BinarySearchTreeIterator
{
private:
	const BNode<T>* fBNodeTree;				// binary search tree
	std::stack<const BNode<T>*> fStack;		// DFS traversal stack

public:

	using Iterator = BinarySearchTreeIterator<T>;

	BinarySearchTreeIterator(const BNode<T>* aBNodeTree)
		: fBNodeTree(aBNodeTree)
	{
		if (!fBNodeTree->empty())
		{
			const BNode<T>* lNode = fBNodeTree;
			fStack.push(lNode);

			while (!lNode->left->empty()) {
				fStack.push(fStack.top()->left);
				lNode = lNode->left;
			}
		}
	}

	const T& operator*() const {
		return fStack.top()->key;
	}

	Iterator& operator++() {
		if (!fStack.empty()) {
			const BNode<T>* lNode = fStack.top();
			fStack.pop();
			if (!lNode->right->empty()) {
				fStack.push(lNode->right);
				while (!fStack.top()->left->empty())
					fStack.push(fStack.top()->left);
			}
		}

		if (fStack.empty())
			fStack.push(&BNode<T>::NIL);

		return *this;
	}
	Iterator operator++(int) {
		Iterator temp = Iterator(*this);
		++(*this);
		return temp;
	}

	bool operator==(const Iterator& aOtherIter) const {
		return fStack.top()->key == aOtherIter.fBNodeTree->key;
	}
	bool operator!=(const Iterator& aOtherIter) const {
		return fStack.top()->key != aOtherIter.fBNodeTree->key;
	}

	Iterator begin() const {
		return Iterator(fBNodeTree);
	}
	Iterator end() const {
		return Iterator(&BNode<T>::NIL);
	}
};
