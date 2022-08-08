//  子区间最大/最小值
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

/*
6
3
0 4
2 5
1 3
*/
int main() {
    int N, Q;
    cin >> N >> Q;

    vl arr(N);
    for(int i = 0; i < N; i++) {
        arr[i] = rand() % (10 - 1 + 1) + 1;
        // rand() % (rangeR - rangeL + 1) + rangeL;
        // 随机生成数公式
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    vector<vl> MinQ(N, vl(N));
    vector<vl> MaxQ(N, vl(N));
    for(int i = 0; i < N; i++) {
        MinQ[i][i] = MaxQ[i][i] =arr[i];
    }

    int len = 2;
    while(len <= N) {
        for(int i = 0; i + len <= N; i++) {
            int l = i, r = len + i - 1;
            int w = len / 2;
            MinQ[l][r] = min(MinQ[l][l + w - 1], MinQ[l + w][r]);
            MaxQ[l][r] = max(MaxQ[l][l + w - 1], MaxQ[l + w][r]);
        }
        len *= 2;
    }

    for(auto x : MinQ) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    
    for(auto x : MaxQ) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        int k = log(b - a + 1) / log(2);
        k = pow(2, k);
        cout << k << " ";
        MinQ[a][b] = min(MinQ[a][a + k - 1], MinQ[b - k + 1][b]);
        MaxQ[a][b] = max(MaxQ[a][a + k - 1], MaxQ[b - k + 1][b]);
        cout << MinQ[a][b] << " " << MaxQ[a][b] << endl;
    }
    return 0;
}