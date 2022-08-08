//Maximum subarray sum
//  the largest possible sum of a sequence of consecutive values in the array

#include <iostream>
using namespace std;
#define MAXN 100000

int n;
int array[MAXN];

int main() {
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int best = 0, sum = 0;
    for(int k = 0; k < n; k++) {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    cout << best << "\n";
    return 0;
}
