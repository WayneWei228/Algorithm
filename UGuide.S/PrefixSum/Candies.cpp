#include <bits/stdc++.h>
using namespace std;


vector <int> calcuS(const vector<int> &arr, int n) {
    vector<int> S(n + 1);
    for(int i = 1; i <= n; i++) {
        S[i] = pow(-1, i - 1) * arr[i] + S[i - 1];
    }
    return S;
}

vector <int> calcuMS(const vector<int> &arr, int n) {
    vector<int> MS(n + 1);
    for(int i = 1; i <= n; i++) {
        MS[i] = pow(-1, i - 1) * arr[i] * i + MS[i - 1];
    }
    return MS;
}

int calcu(const vector<int> &s, const vector<int>&ms, int l, int r) {
    // if (l % 2 == 0){
    return pow(-1, l - 1) * (ms[r] - ms[l - 1] - (l - 1) * (s[r] - s[l - 1]));
    // }
    // return -pow(-1, l - 1) * (ms[r] - ms[l - 1] - (l - 1) * (s[r] - s[l - 1]));
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int res = 0;
        int n, q;
        cin >> n >> q;
        vector<int> arr(n + 1);
        for(int j = 1; j <= n; j++) {
            cin >> arr[j];
        }
        vector<int> s = calcuS(arr, n);
        vector<int> ms = calcuMS(arr, n);
        for(int k = 0; k < q; k++) {
            char temp;
            int l, r;
            cin >> temp >> l >> r;
            if (temp == 'Q') {
                res += calcu(s, ms, l, r);
                // cout << res << " ";
            }
            if(temp == 'U') {
                arr[l] = r;
                s = calcuS(arr, n);
                ms = calcuMS(arr, n);
            }
        }
        cout << res << endl;
    }
}

/*
2
5 4
1 3 9 8 2
Q 2 4
Q 5 5
U 2 10
Q 1 2
3 3
4 5 5
U 1 2
U 1 7
Q 1 2
*/
