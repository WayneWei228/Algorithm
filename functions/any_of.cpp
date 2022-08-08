#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    array<int,7> foo = {0,1,-1,3,-3,5,-5};
    if(any_of(foo.begin(), foo.end(), [](int i) {return i < 0;})) {
        cout << "There are negative elements in the range.\n";
    }
    return 0;
}