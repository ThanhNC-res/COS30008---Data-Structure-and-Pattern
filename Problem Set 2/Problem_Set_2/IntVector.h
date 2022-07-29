#pragma once 
// include for size_t (unsigned integral type) 
#include <cstddef> 
// include basic sorter definition 
#include "IntSorter.h" 
// include iterator definition 
#include "IntVectorIterator.h" 
class IntVector
{
private:
	int* fElements;
	size_t fNumberOfElements;
public:
	// Constructor: copy argument array 
	IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements);
	// Destructor: release memory 
	~IntVector();
	// size getter 
	size_t size() const;
	// swap two elements within the vector 
	void swap(size_t aSourceIndex, size_t aTargetIndex);
	// sort receives a callable Sorter object 
	void sort(const IntSorter& aSorter);  
	// indexer 
	const int operator[](size_t aIndex) const;
	// iterator auxiliary methods (required for C++11 for-range loop) 
	IntVectorIterator begin() const;
	IntVectorIterator end() const;
};
