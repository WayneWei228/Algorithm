#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int N;
int arr[5005];
int V[5005][5005];
vector<int> D[5005];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            V[i][j] = abs(arr[i] - arr[j]);
        }
    }
    // for (int i = 0; i < 5005; i++) {
    //     for (int j = 0; j < 5005; j++) {
    //         D[i][j] = numeric_limits<int>::max();
    //     }
    // }
    for (int i = 1; i < 5005; i++) {
        D[i].resize(5005);
    }
    for (int i = 1; i <= N; i++) {
        D[1][i] = V[i][i];
    }
    for (int i = 1; i + 1 <= N; i++) {
        D[2][i] = V[i][i + 1];
    }
    for (int l = 3; l <= N; l++) {
        for (int i = 1; i + l - 1 <= N; i++) {
            int endi = i + l - 1;
            // cout << "i : " << i << " endi :" << endi << endl;
            D[l][i] = V[i][endi] + D[l - 2][i + 1];
        }
    }

    // cout << endl;
    // for (int l = 1; l <= N; l++) {
    //     cout << "L = " << l << ": ";
    //     for (int i = 1; i + l - 1 <= N; i++) {
    //         cout << D[l][i] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    vector<int> answer;
    for (int l = 1; l <= N; l++) {
        int ans = numeric_limits<int>::max();
        for (int i = 1; i + l - 1 <= N; i++) {
            ans = min(ans, D[l][i]);
        }
        if (l == 1) {
            cout << ans;
        } else {
            cout << " " << ans;
        }
    }
    cout << endl;

    return 0;
}