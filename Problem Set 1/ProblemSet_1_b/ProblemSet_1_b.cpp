#include <iostream>
#include "Combination.h"

int main()
{
	Combination a(6, 2);
	Combination b(5, 2);
	Combination c(28, 14);
	Combination d(52, 5);
	Combination e(5, 5);
	cout << a.getN() << " over " << a.getK() << " = " << a() << endl;
	cout << b.getN() << " over " << b.getK() << " = " << b() << endl;
	cout << c.getN() << " over " << c.getK() << " = " << c() << endl;
	cout << d.getN() << " over " << d.getK() << " = " << d() << endl;
	cout << e.getN() << " over " << e.getK() << " = " << e() << endl;
}

