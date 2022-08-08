#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<vector<int> > grid(N+1, vector<int> (3));

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 3; j++) {
            grid[i][j] += grid[i - 1][j];
        }
        grid[i][arr[i] - 1]++;
    }

    // for(int i = 0; i <= N; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        for(int j = 0; j < 3; j++) {
            cout << grid[r][j] - grid[l-1][j];
            if(j != 2) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;

    fclose(stdin);
    fclose(stdout);
}