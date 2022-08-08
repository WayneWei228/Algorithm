#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Returns an iterator to the first element in the range [first,last) for which pred returns true. If no such element is found, the function returns last.


bool IsOdd (int i) {
    return ((i % 2) == 1);
}

int main() {
    vector<int> myvector;
    
    myvector.push_back(10);
    myvector.push_back(25);
    myvector.push_back(40);
    myvector.push_back(55);

    vector<int>::iterator it = find_if (myvector.begin(), myvector.end(), IsOdd);
    cout << "There first odd value is " << *it << endl;
    
    return 0;
}