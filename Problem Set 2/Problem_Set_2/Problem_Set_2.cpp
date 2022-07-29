#include "IntVector.h"
#include "IntVectorIterator.h"
#include "IntSorter.h"

#include <iostream>
#include <stdexcept>

using namespace std;

#define P1
#define P2

#ifdef P1

void runP1()
{
    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);

    IntVector lVector(lArray, lArrayLength);

    cout << "Test iterator:" << endl;

    for (const int i : lVector)
    {
        cout << i << ' ';
    }

    cout << endl;

    cout << "Test range check" << endl;

    try
    {
        int lValue = lVector[lArrayLength];

        cerr << "We should not see " << lValue << " here!" << endl;
    }
    catch (out_of_range e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "This message must not be printed!" << endl;
    }

    cout << "Test swap" << endl;

    try
    {
        cout << "lVector[3] = " << lVector[3] << endl;
        cout << "lVector[6] = " << lVector[6] << endl;

        lVector.swap(3, 6);

        cout << "lVector[3] = " << lVector[3] << endl;
        cout << "lVector[6] = " << lVector[6] << endl;

        lVector.swap(5, 20);

        cerr << "We should not see this message!" << endl;
    }
    catch (out_of_range e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "This message must not be printed!" << endl;
    }

    cout << endl;
    cout << endl;
}

#endif

#ifdef P2

#include "CocktailShakerSort.h"

void runP2()
{
    int lArray[] = { 100, 50, 60, 45, 60, 567 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);

    IntVector lVector(lArray, lArrayLength);

    cout << "Before sorting:" << endl;

    for (const int i : lVector)
    {
        cout << i << ' ';
    }

    cout << endl;

    CocktailShakerSort lSorter;

    lVector.sort(lSorter);

    cout << "After sorting:" << endl;

    for (const int i : lVector)
    {
        cout << i << ' ';
    }

    cout << endl;
}

#endif

int main()
{
#ifdef P1

    runP1();

#endif

#ifdef P2

    runP2();

#endif

    return 0;
}

