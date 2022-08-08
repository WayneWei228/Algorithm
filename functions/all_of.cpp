#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    array<int,8> foo = {3,5,7,11,13,17,19,23};
    if(all_of(foo.begin(), foo.end(), [](int i) {return i % 2;})) {
        cout << "All the elements are odd numbers.\n";
    }
    return 0;
}