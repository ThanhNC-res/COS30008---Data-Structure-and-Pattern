#include <iostream>
#include <string>

#include "List.h"

using namespace std;

#define P1
#define P2
#define P3
#define P4
#define P5

#ifdef P1

void testP1()
{
    string s1("AAAA");
    string s2("BBBB");
    string s3("CCCC");
    string s4("DDDD");

    List<string> lList;

    lList.push_front(s4);
    lList.push_front(s3);
    lList.push_front(s2);
    lList.push_front(s1);

    // iterate from the top
    cout << "Top to bottom " << lList.size() << " elements:" << endl;
    for (const string& element : lList)
    {
        cout << element << endl;
    }
}

#endif

#ifdef P2

void testP2()
{
    string s1("AAAA");
    string s2("BBBB");
    string s3("CCCC");
    string s4("DDDD");

    List<string> lList;

    lList.push_front(s4);
    lList.push_front(s3);
    lList.push_front(s2);
    lList.push_front(s1);

    string s5("EEEE");
    string s6("FFFF");

    lList.push_back(s5);
    lList.push_back(s6);

    // iterate from the top
    cout << "Bottom to top" << lList.size() << " elements:" << endl;
    for (List<string>::Iterator iter = lList.rbegin();
        iter != iter.rend(); iter--)
    {
        cout << *iter << endl;
    }
}

#endif

#ifdef P3

void testP3()
{
    string s1("AAAA");
    string s2("BBBB");
    string s3("CCCC");
    string s4("DDDD");
    string s5("EEEE");
    string s6("FFFF");

    List<string> lList;

    lList.push_front(s4);
    lList.push_front(s3);
    lList.push_front(s2);
    lList.push_front(s1);
    lList.push_back(s5);
    lList.push_back(s6);

    cout << "Element at index 4: " << lList[4] << endl;
    lList.remove(s5);
    cout << "Element at index 4: " << lList[4] << endl;
}

#endif

#ifdef P4

void testP4()
{
    string s1("AAAA");
    string s2("BBBB");
    string s3("CCCC");
    string s4("DDDD");
    string s5("EEEE");
    string s6("TTTT");

    List<string> lList;

    lList.push_front(s4);
    lList.push_front(s3);
    lList.push_front(s2);

    List<string> copy(lList);

    // iterate from the top
    cout << "A - Top to bottom " << copy.size() << " elements:" << endl;

    for (const string& element : copy)
    {
        cout << element << endl;
    }

    // override list
    lList = copy;

    lList.push_front(s1);
    lList.push_back(s5);

    // iterate from the top
    cout << "B - Bottom to top " << lList.size() << " elements:" << endl;

    for (auto iter = lList.rbegin(); iter != iter.rend(); iter--)
    {
        cout << *iter << endl;
    }
}

#endif

#ifdef P5

void testP5()
{
    List<string> lList;

    lList.push_front("DDDD");
    lList.push_front("CCCC");
    lList.push_front("BBBB");

    List<string> move(std::move(lList));

    // iterate from the top
    cout << "A - Top to bottom " << move.size() << " elements:" << endl;

    for (const string& element : move)
    {
        cout << element << endl;
    }

    // override list
    lList = std::move(move);

    lList.push_front("AAAA");
    lList.push_back("EEEE");

    // iterate from the top
    cout << "B - Bottom to top " << lList.size() << " elements:" << endl;

    for (auto iter = lList.rbegin(); iter != iter.rend(); iter--)
    {
        cout << *iter << endl;
    }
}

#endif

int main()
{
#ifdef P1
    testP1();
#endif

#ifdef P2
    testP2();
#endif

#ifdef P3
    testP3();
#endif

#ifdef P4
    testP4();
#endif

#ifdef P5
    testP5();
#endif

    return 0;
}

