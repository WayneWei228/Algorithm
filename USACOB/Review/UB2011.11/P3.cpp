#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Solution {
    int N, C;
    vector<int> music, chord;

    void Normalize (vector<int>& v) {
        int min = *min_element(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            v[i] -= min;
        }
        sort(v.begin(), v.end());
    }

    vector<int> Find() {
        vector<int> Answer;
        Normalize(chord);
        for (int i = 0; i < N - C; i++) {
            vector<int> piece (music.begin() + i, music.begin() + i + C);
            Normalize(piece);
            if (piece == chord) Answer.emplace_back(i + 1);
        }
        return Answer;
    }

    void Solve() {
        scanf("%d", &N);
        music.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &music[i]);
        }
        scanf("%d", &C);
        chord.resize(C);
        for (int i = 0; i < C; i++) {
            scanf("%d", &chord[i]);
        }
        vector<int> indexes = Find();
        printf("%d\n", int(indexes.size()));
        for (auto i : indexes) {
            printf("%d\n", i);
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}