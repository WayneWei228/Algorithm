// advance example
#include <iostream>     // cout
#include <iterator>     // distance
#include <list>         // list
using namespace std;

int main () {
    list<int> mylist;

    for (int i=0; i<10; i++) mylist.push_back (i*10);   
    // 0, 10, 20, 30, 40, 50, 60, 70, 80, 90
    // |                                       |
    // 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10

    list<int>::iterator first = mylist.begin();
    list<int>::iterator last = mylist.end();    
    
    cout << "The distance is: " << distance(first,last) << '\n';    
    
    return 0;
}