#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool myfunction (int i, int j) {
    return (i < j);
}


int main() {
    int a[] = {2,45,2,3,66,4,5,7,83,3,4,6,9};
    vector<int> arr(a,a + 13);

    // sort(arr.begin(),arr.end());

    // if(binary_search(arr.begin(),arr.end(),3)) {
    // cout << "found\n";
    // } else
    // {
    //     cout << "not found\n";
    // }

    if(binary_search(arr.begin(),arr.end(), 6, myfunction)) {
        cout << "found!\n";
    }   else
    {
        cout << "not found\n";
    }
    

    return 0;

}