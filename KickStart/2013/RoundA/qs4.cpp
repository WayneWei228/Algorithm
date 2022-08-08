#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int T;

struct Solution {
    int N;
    vector<string> Map;
    int sx, sy, ex, ey;
    void Solve() {
        cin >> N;
        Map.resize(N + 2);
        Map[0] = string('#', N + 2);
        for (int i = 1; i <= N; i++) {
            string s;
            cin >> s;
            Map[i] = '#' + s + '#';
        }
        Map[N - 1] = string('#', N + 2);
        cin >> sx >> sy >> ex >> ey;
        for (auto i : Map) {
            printf("%s\n", i.c_str());
        }
    }
};

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        Solution().Solve();
    }
    return 0;
}