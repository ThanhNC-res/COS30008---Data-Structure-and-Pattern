#pragma once 
// include for size_t (unsigned integral type) 
#include <cstddef> 
// forward declaration of container class 
class IntVector;
class IntVectorIterator
{
private:
	const IntVector& fContainer;
	size_t fPosition;
public:
	IntVectorIterator(const IntVector& aContainer, size_t aStart = 0);
	const int operator*() const;
	IntVectorIterator& operator++(); // prefix 
	IntVectorIterator operator++(int); // postfix 
	bool operator==(const IntVectorIterator& aRHS) const;
	bool operator!=(const IntVectorIterator& aRHS) const;
	IntVectorIterator begin() const;
	IntVectorIterator end() const;
};
