#include <cstdio>
#include <string>
using namespace std;

char Buffer[101];

typedef long long int64;

struct Solution {
    string S;
    int64 Begin, End;

    void Solve(int caseNo) {
        scanf("%s%lld%lld", Buffer, &Begin, &End);
        S = Buffer;
        --Begin;
        printf("Case #%d: %lld\n", caseNo, F(End) - F(Begin));
    }
    // [I, J] -> [I-1, J-1] -> [I-1, J) -> F(J) - F(I - 1)
    // [0, N)的
    int64 F(int64 n) {
        int64 whole = n / S.size();
        int64 fraction = n % S.size();
        int64 answer = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == 'B') answer += whole;
            if (S[i] == 'B' && i < fraction) ++answer;
        }
        return answer;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}