#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Returns an iterator to the first element in the range [first,last) that compares equal to val. 
// If no such element is found, the function returns last
int main() {
    int myints[] = { 10, 20, 30, 40 };
    int* p;

    p = find(myints, myints + 4, 30);
    if(p != myints + 4) {
        cout << "Element found in myints: " << *p << '\n';
    } else {
        cout << "Elements not found in myints\n";
    }

    vector<int> myvector (myints, myints + 4);
    vector<int>::iterator it;

    it = find(myvector.begin(), myvector.end(), 30);
    if(it != myvector.end()) {
        cout << "Elements found in myvector: " << *it << '\n';
    } else
    {
        cout << "Element not found in myvector\n";
    }
    return 0;
}