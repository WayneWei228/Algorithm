// prev example
#include <iostream>     // cout
#include <iterator>     // next
#include <list>         // list
#include <algorithm>    // for_each
using namespace std;


int main () {
  list<int> mylist;
  for (int i=0; i<10; i++) mylist.push_back (i*10);

  cout << "The last element is " << *prev(mylist.end()) << '\n';

  return 0;

  // The last element is 90
}