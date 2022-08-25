#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int M = 1000000007;

typedef long long int64;

struct Parameters {
    int R, A, B;

    bool operator<(const Parameters& that) const { return R < that.R; }
};

int64 M5, M7;

vector<Parameters> P;

int64 ExGCD(int64 a, int64 b, int64* ax, int64* bx) {
    if (b == 0) return *ax = 1, *bx = 0, a;
    int64 answer = ExGCD(b, a % b, bx, ax);
    *bx -= a / b * (*ax);
    return answer;
}

bool Less(const string& a1, const string& a2) {
    if (a1.size() < a2.size()) return true;
    if (a2.size() < a1.size()) return false;
    return a1 < a2;
}

int F[8][4]{
    {1, 0, 0, 0}, {0, 1, 0, 0}, {2, 0, 0, 0}, {0, 0, 1, 0},
    {1, 1, 0, 0}, {0, 0, 0, 1}, {3, 0, 0, 0}, {0, 2, 0, 0},
};

struct Solution {
    int N;
    string Answer;

    void Solve() {
        scanf("%d", &N);
        switch (N) {
            case 0:
                printf("10\n");
                return;
            case 1:
                printf("1\n");
                return;
        }
        int64 vC = N;
        for (int iC = 0; iC < 700; ++iC) {
            int bound = 700 - iC;
            int vD = vC;
            for (int iD = 0; iD < bound; ++iD) {
                Visit(vD, iC, iD);
                vD = vD * M7 % M;
            }
            vC = vC * M5 % M;
        }
        printf("%s\n", Answer.c_str());
    }

    void Visit(int vD, int iC, int iD) {
        int index =
            lower_bound(P.begin(), P.end(), Parameters{vD}) - P.begin();
        if (P.size() <= index || P[index].R != vD) return;
        Found({P[index].A, P[index].B, iC, iD});
    }

    void Found(vector<int> a) {
        string answer;
        for (int i = 7; i >= 0; --i) {
            while (RemoveOK(a, i)) answer += '2' + i;
        }
        reverse(answer.begin(), answer.end());
        if (Answer.empty() || Less(answer, Answer)) Answer = answer;
    }

    bool RemoveOK(vector<int>& a, int k) {
        for (int i = 0; i < 4; ++i) {
            if (a[i] < F[k][i]) return false;
        }
        for (int i = 0; i < 4; ++i) a[i] -= F[k][i];
        return true;
    }
};

int main() {
    int64 vA = 1;
    for (int iA = 0; iA < 2100; ++iA) {
        int bound = (700 - iA / 3) * 2;
        int64 vB = vA;
        for (int iB = 0; iB < bound; ++iB) {
            P.emplace_back(Parameters{int(vB), iA, iB});
            vB = vB * 3 % M;
        }
        vA = vA * 2 % M;
    }
    sort(P.begin(), P.end());
    ExGCD(5, M, &M5, &vA);
    ExGCD(7, M, &M7, &vA);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) Solution().Solve();
    return 0;
}
