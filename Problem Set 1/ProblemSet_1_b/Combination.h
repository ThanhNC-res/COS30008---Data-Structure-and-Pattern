#pragma once
#include <iostream>
#include <string>

using namespace std; 

class Combination {
private: 
	unsigned fK, fN;

public: 
	Combination(unsigned aN, unsigned aK) : fN(aN), fK(aK) {}

	unsigned long long operator()() const {
		unsigned result = 1.0;

		if (fK > fN) {
			return 0; 
		}
		for (unsigned i = 1.0; i <= fK; i++) {
			result *= (fN - i + 1.0) / i;
		}
		return result;

	}

	// getters

	unsigned getK() const {
		return fK; 
	}
		
	unsigned getN() const {
		return fN; 
	}
	
};


