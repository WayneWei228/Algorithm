#include <cstdio>
#include <cstdlib>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Particle {
    int P[3], V[3], A[3];
    int AbsP, AbsV, AbsA;

    bool Read() {
        return scanf("p=<%d,%d,%d>, v=<%d,%d,%d>, a=<%d,%d,%d> ",  //
                     &P[0], &P[1], &P[2],                          //
                     &V[0], &V[1], &V[2],                          //
                     &A[0], &A[1], &A[2]) == 9;
    }

    Particle& ComputeAbs() {
        AbsP = abs(P[0]) + abs(P[1]) + abs(P[2]);
        AbsV = abs(V[0]) + abs(V[1]) + abs(V[2]);
        AbsA = abs(A[0]) + abs(A[1]) + abs(A[2]);
        return *this;
    }

    bool operator<(const Particle& that) const {
        if (AbsA != that.AbsA) return AbsA < that.AbsA;
        if (AbsV != that.AbsV) return AbsV < that.AbsV;
        return AbsP < that.AbsP;
    }

    uint64 Hash() const {
        return Fingerprint(Fingerprint(P[0]) + P[1]) + P[2];
    }

    Particle& Tick() {
        for (int i = 0; i < 3; ++i) V[i] += A[i];
        for (int i = 0; i < 3; ++i) P[i] += V[i];
        return *this;
    }
};

struct Solution {
    vector<Particle> P;

    void Solve() {
        while (true) {
            Particle p;
            if (!p.Read()) break;
            P.emplace_back(move(p.ComputeAbs()));
        }
        int answer1 = min_element(P.begin(), P.end()) - P.begin();
        printf("%d\n", answer1);
        for (int i = 0; i < 100; ++i) {
            unordered_map<uint64, Particle> u;
            for (auto& i : P) {
                uint64 h = i.Hash();
                auto result = u.emplace(h, move(i));
                if (!result.second) {
                    result.first->second.AbsP =
                        numeric_limits<int>::min();
                }
            }
            P.clear();
            for (auto& i : u) {
                if (i.second.AbsP != numeric_limits<int>::min()) {
                    P.emplace_back(move(i.second.Tick())); 
                }
            }
        }
        int answer2 = P.size();
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}