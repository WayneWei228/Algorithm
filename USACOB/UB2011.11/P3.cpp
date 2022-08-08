#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, C;
    vector<int> Music, Chord;

    void Normalize(vector<int>& a) { // 正则化，统一度量衡
        int min = *min_element(a.begin(), a.end());
        for (int i = 0; i < a.size(); ++i) a[i] -= min;
        sort(a.begin(), a.end());
    }

    vector<int> Find() {
        vector<int> answer;
        Normalize(Chord);
        for (int i = 0; i <= N - C; ++i) {
            vector<int> music(Music.begin() + i, Music.begin() + i + C);
            Normalize(music);
            if (music == Chord) answer.emplace_back(i + 1);
        }
        return answer;
    }

    void Solve() {
        scanf("%d", &N);
        Music.resize(N);
        for (int i = 0; i < N; ++i) scanf("%d", &Music[i]);
        scanf("%d", &C);
        Chord.resize(C);
        for (int i = 0; i < C; ++i) scanf("%d", &Chord[i]);
        vector<int> indices = Find();
        printf("%d\n", (int)indices.size());
        for (int i = 0; i < indices.size(); ++i) {
            printf("%d\n", indices[i]);
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}