// next example
#include <iostream>  // cout
#include <iterator>  // next
#include <list>      // list
#include <algorithm> // for_each
using namespace std;

int main()
{
    list<int> mylist;
    for (int i = 0; i < 10; i++)
        mylist.push_back(i * 10);

    cout << "mylist:";
    for_each(mylist.begin(),
             next(mylist.begin(), 5),
             [](int x)
             { cout << ' ' << x; });

    cout << '\n';

    return 0;

    // mylist: 0 10 20 30 40
}