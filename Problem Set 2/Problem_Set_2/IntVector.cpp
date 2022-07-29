#include "IntVector.h"
#include <iostream>
IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
{
	fNumberOfElements = aNumberOfElements;
	fElements = new int[fNumberOfElements];
	for (size_t i = 0; i < fNumberOfElements; i++)
	{
		fElements[i] = aArrayOfIntegers[i];
	}
}

IntVector::~IntVector()
{
	delete fElements;
}

size_t IntVector::size() const {
	return fNumberOfElements; 
}

void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex) {
	if (aSourceIndex >= fNumberOfElements) {
		printf("Invalid Source index. ");
	}
	else if (aSourceIndex == aTargetIndex) {
		printf("Cannot exchange the same elements. ");
	}
	else if (aTargetIndex >= fNumberOfElements) {
		printf("Invalid Target index. ");
	}
	int temp = fElements[aSourceIndex];
	fElements[aSourceIndex] = fElements[aTargetIndex];
	fElements[aTargetIndex] = temp;
	return;
}



const int IntVector::operator[](size_t aIndex) const {

	if (aIndex >= fNumberOfElements) {
		printf("Invalid IntVector Index");
	}
	return fElements[aIndex];
	
}

IntVectorIterator IntVector::begin() const {
	return IntVectorIterator(*this);
}

IntVectorIterator IntVector::end() const {
	return IntVectorIterator(*this, size());
}

void IntVector::sort(const IntSorter& aSorter) {
	aSorter(*this);
}