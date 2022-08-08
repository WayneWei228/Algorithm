#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> mylist;
    for(int i = 0; i < 10; i++) {
        mylist.push_back(i * 10);
    }
    list<int>::iterator it = mylist.begin();
    
    advance (it, 5);

    cout << "The sixth element in mylist is: " << *it << '\n';
    
    return 0;
}