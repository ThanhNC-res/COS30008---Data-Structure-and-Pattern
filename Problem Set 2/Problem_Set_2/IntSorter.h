#pragma once 
// forward declaration for container 
class IntVector;
class IntSorter
{
public:
	virtual ~IntSorter() {}
	virtual void operator()(IntVector& aContainer) const {}
};
