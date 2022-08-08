#include <cstdio>
#include <limits>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

char Buffer0[80], Buffer1[80], Buffer2[80];

struct Solution {
    int N, Answer;
    vector<vector<int>> Out;
    map<string, int> ToNumber;
    vector<int> P;

    int MapToNumber(const string& s) {
        auto result = ToNumber.emplace(s, ToNumber.size());
        return result.first->second;
    }

    void Put(int no, int current) {
        if (no == N) {
            current += Out[P[no - 1]][P[0]];
            if (Answer < current) Answer = current;
            return;
        }
        for (int i = no; i < N; ++i) {
            swap(P[no], P[i]);
            int next = current;
            if (no != 0) next += Out[P[no - 1]][P[no]];
            Put(no + 1, next);
            swap(P[no], P[i]);
        }
    }

    void Solve() {
        N = 8;
        Out.resize(N);
        for (int i = 0; i < Out.size(); ++i) Out[i].resize(N);
        while (true) {
            int d;
            if (scanf("%s would %s %d happiness units by sitting "
                      "next to %[^.].",
                      Buffer0, Buffer1, &d, Buffer2) < 3) {
                break;
            }
            string verb = Buffer1;
            if (verb == "lose") d = -d;
            int n0 = MapToNumber(Buffer0);
            int n1 = MapToNumber(Buffer2);
            Out[n0][n1] += d; // 我跟你一起坐好感度相加， 你跟我一起做好感度减少， 两人一起坐好感度为净好感度
            Out[n1][n0] += d;
        }
        P.resize(N);
        for (int i = 0; i < N; ++i) P[i] = i;
        Answer = numeric_limits<int>::min();
        Put(0, 0);
        printf("%d\n", Answer);
        ++N;
        Out.resize(N);
        for (int i = 0; i < Out.size(); ++i) Out[i].resize(N);
        P.resize(N);
        for (int i = 0; i < N; ++i) P[i] = i;
        Answer = numeric_limits<int>::min();
        Put(0, 0);
        printf("%d\n", Answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
