#include <cstdio>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <limits>
using namespace std;

struct Coordinate {
    int X, Y;
    
    bool operator == (const Coordinate& that) const {
        return that.X == X && that.Y == Y;
    }
};

struct CoordinateHash {
    size_t operator () (const Coordinate& that) const {
        return that.X * size_t(9875321) + that.Y;
    }
};

struct Solution {
    int N;
    unordered_map<Coordinate, int, CoordinateHash> ToNumber;
    vector<Coordinate> C;
    vector<int> Cook, Tool;
    vector<int> Answer, State;
    int MapToNumber(const Coordinate& c) {
        return ToNumber.emplace(c, ToNumber.size()).first->second;
    }

    void Solve() {
        scanf("%d", &N);
        MapToNumber({0, 0}); // important
        Cook.resize(N);
        Tool.resize(N);
        for (int i = 0; i < N; i++) {
            Coordinate c, t;
            scanf("%d%d%d%d", &c.X, &c.Y, &t.X, &t.Y);
            Cook[i] = MapToNumber(c);
            Tool[i] = MapToNumber(t);
        }
        C.resize(ToNumber.size());
        for (const auto& i : ToNumber) {
            C[i.second] = i.first;
        }
        int answerSize = C.size();
        for (int i = 0; i < N; i++) {
            answerSize *= 3;
        }
        Answer.resize(answerSize);
        State.resize(N);
        printf("%d\n", Compute(0));
    }

    int GetLabel(int p) {
        for (int i = 0; i < N; ++i) {
            p = p * 3 + State[i];
        }
        return p;
    }

    int Distance (int a, int b) {
        return abs(C[a].X - C[b].X) + abs(C[a].Y - C[b].Y);
    }

    int Compute(int p) {
        int Label = GetLabel(p);
        if (Answer[Label]) return Answer[Label];
        int state1 = 0, state2 = 0;
        for (int i = 0; i < N; ++i) {
            if (State[i] == 1) ++state1;
            if (State[i] == 2) ++state2;
        }
        int answer = numeric_limits<int>::max();
        if (state2 == N) return Answer[Label] = Distance(p, 0);
        for (int i = 0; i < N; ++i) {
            if (State[i] == 1) {
                State[i] = 2;
                int res = Compute(Cook[i]) + Distance(p, Cook[i]);
                if (res < answer) {
                    answer = res;
                }
                State[i] = 1;
            }
        }
        if (state1 == 2) return Answer[Label] = answer;
        for (int i = 0; i < N; i++) {
            if (State[i] == 0) {
                State[i] = 1;
                int res = Compute(Tool[i]) + Distance(p, Tool[i]);
                if (res < answer) answer = res;
                State[i] = 0;
            }
        }
        return Answer[Label] = answer;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}