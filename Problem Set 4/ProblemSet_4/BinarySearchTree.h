#pragma once 
#include "BNode.h" 
template<typename T>
class BinarySearchTreeIterator;

template<typename T>
class BinarySearchTree
{
private:
	BNode<T>* fRoot;

public:
	using Iterator = BinarySearchTreeIterator<T>;

	BinarySearchTree() : fRoot(&BNode<T>::NIL) {
	}
	~BinarySearchTree() {
		remove(NULL);
	}

	bool empty() const {
		return fRoot->empty(); 
	}
	bool insert(const T& aKey) {
		if (empty())
			return fRoot = new BNode<T>(aKey);
		return fRoot->insert(aKey);
	}
	bool remove(const T& aKey) {
		return fRoot->remove(aKey, fRoot);
	}

	size_t height() const {
		return fRoot->height();
	}
	Iterator begin() const {
		return Iterator(const_cast<const BNode<T>*>(fRoot));
	}
	Iterator end() const {
		return Iterator(&BNode<T>::NIL);
	}

};

