#include "IntVectorIterator.h"
#include "IntVector.h"

IntVectorIterator::IntVectorIterator(const IntVector& aContainer, size_t aStart):fContainer(aContainer), fPosition(aStart) {
	
}

const int IntVectorIterator::operator*() const {
	return fContainer[fPosition];
}

IntVectorIterator& IntVectorIterator::operator++() {
	++fPosition;
	return *this;
}

IntVectorIterator IntVectorIterator::operator++(int) {
	IntVectorIterator temp = *this;
	++(*this);
	return temp;
}

bool IntVectorIterator::operator==(const IntVectorIterator& aRHS) const {
	return &fContainer == &aRHS.fContainer &&
		fPosition == aRHS.fPosition;
}

bool IntVectorIterator::operator!=(const IntVectorIterator& aRHS) const {
	return !(*this == aRHS);
}

IntVectorIterator IntVectorIterator::begin() const {
	IntVectorIterator temp = *this;
	temp.fPosition = 0;
	return temp;
}

IntVectorIterator IntVectorIterator::end() const {
	IntVectorIterator temp = *this;
	temp.fPosition = temp.fContainer.size();
	return temp;
	
}