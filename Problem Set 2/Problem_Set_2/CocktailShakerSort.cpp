#include "CocktailShakerSort.h"
#include "IntVector.h"

void CocktailShakerSort::operator()(IntVector& aContainer) const {
	size_t aStart = 0;
	size_t aEnd = aContainer.size() - 1;
	for (aStart; aStart < aEnd; aStart++) {
		for (size_t i = aStart + 1; i <= aEnd; i++) {
			if (aContainer[aStart] > aContainer[i]) {
				aContainer.swap(aStart, i);
			}
		}
	}
}
