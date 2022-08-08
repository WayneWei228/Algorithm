#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int64;

struct Node {
    int64 pre;
    int64 nex;
};

int N;

struct Solution {
    vector<int> V;
    unordered_map<int, Node> M;
    int64 Sum = 0;

    void Solve() {
        cin >> N;
        V.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            int a;
            cin >> a;
            V[a] = i;
            M[i].pre = i - 1;
            M[i].nex = i + 1;
        }
        for (int i = 1; i <= N; i++) {
            int a = V[i];
            int l = M[a].pre;
            int r = M[a].nex;
            if (l != 0) {
                Sum += abs(a - l) + 1;
            }
            if (r != N + 1) {
                Sum += abs(a - r) + 1;
            }
            M.erase(a);
            if (l == 0) {
                M[r].pre = 0;
                continue;
            }
            if (r == N + 1) {
                M[l].nex = N + 1;
                continue;
            }
            M[l].nex = r;
            M[r].pre = l;
        }
        printf("%lld\n", Sum);
    }
};

int main() {
    Solution().Solve();
    return 0;
}