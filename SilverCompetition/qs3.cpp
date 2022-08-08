#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N, M;

struct Solution {
    vector<vector<int>> V;
    vector<int> Mathed;
    vector<bool> Visited;
    void Go() {
        Mathed.resize(N, -1);
        for (int i = 0; i < N; i++) {
            Visited.clear();
            Visited.resize(M);
            Find(i);
        }
    }

    bool Find(int no) {
        for (auto i : V[no]) {
            if (!Visited[i]) {
                Visited[i] = true;
                if (Mathed[i] == -1 || Find(Mathed[i])) {
                    Mathed[i] = no;
                    return true;
                }
            }
        }
        return false;
    }
    void Solve() {
        cin >> N >> M;
        V.resize(N);
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            V[i].emplace_back(a - 1);
            V[i].emplace_back(b - 1);
        }
        Go();

        int ans = 0;
        for (auto& i : Mathed) {
            if (i == -1) ans++;
            i++;
        }
        printf("%d\n", ans);
        int total = N;
        for (int i = 0; i < N; i++) {
            if (Mathed[i] == 0) {
                Mathed[i] = N;
                N--;
            }
        }
        for (auto i : Mathed) {
            printf("%d\n", i);
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}