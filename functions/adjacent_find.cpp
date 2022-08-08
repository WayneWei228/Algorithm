#include <bits/stdc++.h>
using namespace std;

bool myfunction(int i, int j) {
    return (i == j);
}
// Searches the range [first,last) for the first occurrence of two consecutive elements that match, and returns an iterator to the first of these two elements, or last if no such pair is found.
int main() {
    int myints[] = {5, 20, 5, 30, 30, 20, 10, 10, 20};
    vector<int> myvector (myints, myints + 8);
    vector<int>::iterator it;

    it = adjacent_find(myvector.begin(), myvector.end());

    if(it != myvector.end()) {
        cout << "the first pair of repeated elements are: " << *it << '\n';
    }

    it = adjacent_find (++it, myvector.end(), myfunction);

    if (it != myvector.end()) 
        cout << "the second pair of repeated elements are: " << *it << '\n';
    
    return 0;
}