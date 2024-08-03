#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        int most_same;
        if (n % m == 0) {
            most_same = n / m;
        } else {
            most_same = n / m + 1;
        }
        // most_same = (n + m - 1) / m
        if (k < n - most_same) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

/*

6 3

1 2 3 1 2 3

5 3

1 2 3 1 2

4 3

1 2 3 1

*/