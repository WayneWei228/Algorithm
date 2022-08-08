// begin / end example
#include <iostream> // cout
#include <vector>   // vector, begin, end
using namespace std;

int main()
{
    int foo[] = {10, 20, 30, 40, 50};
    vector<int> bar;

    // iterate foo: inserting into bar
    for (auto it = begin(foo); it != end(foo); ++it)
        bar.push_back(*it);

    // iterate bar: print contents:
    cout << "bar contains:";
    for (auto it = begin(bar); it != end(bar); ++it)
        cout << ' ' << *it;
    cout << '\n';

    return 0;
//     bar contains: 10 20 30 40 50
}