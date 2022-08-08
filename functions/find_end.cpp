#include <bits/stdc++.h>

using namespace std;

// Searches the range [first1,last1) for the last occurrence of the sequence defined by [first2,last2), 
// and returns an iterator to its first element, or last1 if no occurrences are found.

bool myfunction(int i, int j) {
    return (i == j);
}

int main () {
    int myints[] = {1,2,3,4,5,1,2,3,4,5};
    vector<int> haystack (myints, myints + 10);
    
    int needle1[] = {1, 2, 3};

    vector<int>::iterator it;
    it = find_end (haystack.begin(), haystack.end(), needle1, needle1 + 3);

    if(it != haystack.end()) {
        cout << "needle1 last found at position " << (it - haystack.begin()) << '\n';
    }

    int needle2[] = {4, 5, 1};

    it = find_end (haystack.begin(), haystack.end(), needle2, needle2 + 3, myfunction);

    if(it != haystack.end()) 
        cout << "needle2 last found at position " << (it - haystack.begin()) << '\n';

    return 0;
}