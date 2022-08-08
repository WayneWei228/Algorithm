#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer0[100], Buffer1[100], Buffer2[100];
typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Coordinate {
    int x, y;

    bool operator==(const Coordinate& that) const {
        return x == that.x && y == that.y;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate& c) const {
        return Fingerprint(c.x) + c.y;
    }
};

typedef unordered_map<Coordinate, bool, CoordinateHash> CoordinateMap;

struct Solution {
    int X, Y, G;
    unordered_map<string, int> ToNumber;
    CoordinateMap M;
    vector<vector<int>> Agree;
    vector<vector<int>> Disagree;
    int answer = 0;

    int MaptoNumber(const string& input) {
        auto res = ToNumber.emplace(input, ToNumber.size());
        return res.first->second;
    }

    void JudgeAgree(int n, const unordered_set<int>& S) {
        if (n >= Agree.size()) return;
        for (auto i : Agree[n]) {
            if (!S.count(i)) {
                M[Coordinate{i, n}] = false;
                M[Coordinate{n, i}] = false;
            }
        }
    }

    void JudgeDis(int n, const unordered_set<int>& S) {
        if (n >= Disagree.size()) return;
        for (auto i : Disagree[n]) {
            if (S.count(i)) {
                M[Coordinate{i, n}] = false;
                M[Coordinate{n, i}] = false;
            }
        }
    }

    void Solve() {
        scanf("%d", &X);
        for (int i = 0; i < X; i++) {
            scanf("%s%s", Buffer0, Buffer1);
            int l = MaptoNumber(Buffer0);
            int r = MaptoNumber(Buffer1);
            int max_v = max(l, r);
            if (max_v >= Agree.size()) Agree.resize(max_v + 1);
            Agree[l].emplace_back(r);
            Agree[r].emplace_back(l);
            M[Coordinate{l, r}] = true;
            M[Coordinate{r, l}] = true;
        }
        scanf("%d", &Y);
        for (int i = 0; i < Y; i++) {
            scanf("%s%s", Buffer0, Buffer1);
            int l = MaptoNumber(Buffer0);
            int r = MaptoNumber(Buffer1);
            int max_v = max(l, r);
            if (max_v >= Disagree.size()) Disagree.resize(max_v + 1);
            Disagree[l].emplace_back(r);
            Disagree[r].emplace_back(l);
            M[Coordinate{l, r}] = true;
            M[Coordinate{r, l}] = true;
        }
        scanf("%d", &G);
        for (int i = 0; i < G; i++) {
            vector<int> V(3);
            scanf("%s%s%s", Buffer0, Buffer1, Buffer2);
            unordered_set<int> S;
            V[0] = MaptoNumber(Buffer0);
            V[1] = MaptoNumber(Buffer1);
            V[2] = MaptoNumber(Buffer2);
            S.emplace(V[0]);
            S.emplace(V[1]);
            S.emplace(V[2]);
            for (int i = 0; i < 3; i++) {
                JudgeAgree(V[i], S);
                JudgeDis(V[i], S);
            }
        }
        for (auto i : M) {
            if (!i.second) {
                answer++;
            }
        }
        answer /= 2;
        printf("%d\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}