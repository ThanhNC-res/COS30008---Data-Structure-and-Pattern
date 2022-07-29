#pragma once 
#include "IntSorter.h" 
class CocktailShakerSort : public IntSorter
{
public:
	void operator()(IntVector& aContainer) const override;
};
