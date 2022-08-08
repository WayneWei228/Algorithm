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
    int Out[N][N], Answer;
    map<string, int> ToNumber;
    vector<int> P;

    int MapToNumber(const string& s) {
        auto result = ToNumber.emplace(s, ToNumber.size());
        return result.first->second;
    }

    void Put(int no, int current) {
        if (no == N) {
            if (current < Answer) Answer = current;
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
        while (true) {
            int d;
            if (scanf("%s to %s = %d", Buffer0, Buffer1, &d) < 3) break;
            int n0 = MapToNumber(Buffer0);
            int n1 = MapToNumber(Buffer1);
            Out[n0][n1] = Out[n1][n0] = d;
        }
        P.resize(N);
        for (int i = 0; i < N; ++i) P[i] = i;
        Answer = numeric_limits<int>::max();
        Put(0, 0);
        printf("%d\n", Answer);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                Out[i][j] = -Out[i][j];
            }
        }
        Answer = numeric_limits<int>::max();
        Put(0, 0);
        printf("%d\n", -Answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}