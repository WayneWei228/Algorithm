#include <bits/stdc++.h>
using namespace std;

bool comp_case_insensitive(char c1, char c2) {
    return tolower(c1) == tolower(c2);
}

int main() {
    int mychars[] = {'a', 'b', 'c', 'A', 'B', 'C'};
    vector<char> haystack (mychars, mychars + 6);
    vector<char>::iterator it;

    int needle[] = {'A', 'B', 'C'};

    it = find_first_of (haystack.begin(), haystack.end(), needle, needle + 3);

    if(it != haystack.end()) {
        cout << "The first match is: " << *it << '\n';
    }

    it = find_first_of(haystack.begin(), haystack.end(), needle, needle + 3, comp_case_insensitive);

    if(it != haystack.end()) {
        cout << "The first match is: " << *it << '\n';
    }

    return 0;
}