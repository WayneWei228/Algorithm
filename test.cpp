#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // double x = 3.4;
    // string x = "Mina is me";
    // cout << x << endl;
    vector<int> s;
    s.resize(8);
    int index = 0;
    while (index < s.size()) {
        s[index] = index;
        index = index + 1;
    }
    cout << endl;
}