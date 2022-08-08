#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;


// 自动机状态

/*
该题状态循环，初始态等于接受态
abcdabcd
{'d', 0, 0}
状态转移需能进行批量操作，而不是多次单操作
*/

struct State {
    char Last;
    int BalanceAC, BalanceBD;

    bool operator==(const State& that) const {
        return Last == that.Last &&  //
               BalanceAC == that.BalanceAC &&
               BalanceBD == that.BalanceBD;
    }
};

struct StateHash {
    size_t operator()(const State& s) const {
        size_t answer = s.Last;
        answer = answer * 9875321 + s.BalanceAC;
        answer = answer * 9875321 + s.BalanceBD;
        return answer;
    }
};

char Buffer[501];

const int M = 1000000007;

// 状态合并 2^N -> 1000000

struct Solution {
    unordered_map<State, int, StateHash> Count;
    State S{'d', 0, 0}; // 接受态

    void Solve(int caseNo) {
        Count[S] = 1;
        scanf("%s", Buffer);
        string s = Buffer;
        for (char i : s) {
            auto count0 = Count;
            for (const auto& j : count0) {
                State state = j.first;
                if (Go(state, i)) {
                    auto& c = Count[state];
                    c = (c + j.second) % M;
                }
            }
        }
        printf("Case #%d: %d\n", caseNo, Count[S] - 1); // 空串不要
    }

    bool Go(State& state, char c) {
        if ((state == S && c == 'a') ||  // abcddabcd
            c == state.Last ||           // 
            c == state.Last + 1) {
            state.Last = c;
            switch (c) {
                case 'a':
                    ++state.BalanceAC;
                    break;
                case 'b':
                    ++state.BalanceBD;
                    break;
                case 'c':
                    --state.BalanceAC;
                    break;
                case 'd':
                    --state.BalanceBD;
                    break;
            }
            return true;
        }
        return false;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}