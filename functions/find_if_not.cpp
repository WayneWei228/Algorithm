#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
// Returns an iterator to the first element in the range [first,last) for which pred returns false. If no such element is found, the function returns last
int main() {
    array<int,5> foo = {1,2,3,4,5};

    array<int,5>::iterator it = find_if_not(foo.begin(), foo.end(), [](int i){return i % 2;});
    cout << "The first even value is " << *it << '\n';
    return 0;
}