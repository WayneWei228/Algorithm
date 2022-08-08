#include <cstdio>
#include <limits>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int N = 8;

char Buffer0[80], Buffer1[80];

struct Solution {
    int Out[N][N];
    map<string, int> ToNumber;
    vector<int> Answer;

    int MapToNumber(const string& s) {
        auto result = ToNumber.emplace(s, ToNumber.size());
        return result.first->second;
    }

    int GetLabel(int p, const vector<bool>& state) {
        int answer = p;
        for (int i = 0; i < N; ++i) {
            answer = answer + answer + state[i];
        }
        return answer;
    }

    int GetMin(int p, const vector<bool>& state) { // GetMin(要去的地点, 现在的状态)
        int label = GetLabel(p, state);
        if (Answer[label] != -1) return Answer[label]; // 已经计算过，返回
        vector<bool> newState(state);
        newState[p] = false; // p 位置 来过了
        int answer = numeric_limits<int>::max();
        for (int i = 0; i < N; ++i) {
            if (i != p && state[i]) {
                int result = GetMin(i, newState) + Out[p][i];
                if (result < answer) answer = result;
            }
        }
        return Answer[label] = answer;
    }

    int GetMax(int p, const vector<bool>& state) {
        int label = GetLabel(p, state);
        if (Answer[label] != -1) return Answer[label];
        vector<bool> newState(state);
        newState[p] = false;
        int answer = numeric_limits<int>::min();
        for (int i = 0; i < N; ++i) {
            if (i != p && state[i]) {
                int result = GetMax(i, newState) + Out[p][i];
                if (answer < result) answer = result;
            }
        }
        return Answer[label] = answer;
    }

    void Solve() {
        while (true) {
            int d;
            if (scanf("%s to %s = %d", Buffer0, Buffer1, &d) < 3) break;
            int n0 = MapToNumber(Buffer0);
            int n1 = MapToNumber(Buffer1);
            Out[n0][n1] = Out[n1][n0] = d;
        }
        Answer.resize(N << N); // N 乘上 N 个 2
        for (int i = 0; i < Answer.size(); ++i) Answer[i] = -1;
        for (int i = 0; i < N; ++i) {
            vector<bool> state(N);
            state[i] = true;
            Answer[GetLabel(i, state)] = 0;
        }
        vector<bool> state(N);
        state.flip(); // 全设为 true 都没去过
        // false 去过 true 没去过
        int minAnswer = numeric_limits<int>::max();
        for (int i = 0; i < N; ++i) {
            int answer = GetMin(i, state);
            if (answer < minAnswer) minAnswer = answer;
        }
        printf("%d\n", minAnswer);
        for (int i = 0; i < Answer.size(); ++i) Answer[i] = -1;
        for (int i = 0; i < N; ++i) {
            vector<bool> state(N);
            state[i] = true;
            Answer[GetLabel(i, state)] = 0;
        }
        int maxAnswer = numeric_limits<int>::min();
        for (int i = 0; i < N; ++i) {
            int answer = GetMax(i, state);
            if (maxAnswer < answer) maxAnswer = answer;
        }
        printf("%d\n", maxAnswer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}