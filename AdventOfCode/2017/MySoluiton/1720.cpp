#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// p=<1500,413,-535>, v=<-119,22,36>, a=<-5,-12,3>
typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Particle {
    int p[3], v[3], a[3];
    int absP, absV, absA;

    bool Read() {
        int res = scanf("p=<%d,%d,%d>, v=<%d,%d,%d>, a=<%d,%d,%d>\n",
                        &p[0], &p[1], &p[2], &v[0], &v[1], &v[2], &a[0],
                        &a[1], &a[2]);
        if (res != 9) return false;
        return true;
    }

    void ComputeABS() {
        absA = abs(a[0]) + abs(a[1]) + abs(a[2]);
        absP = abs(p[0]) + abs(p[1]) + abs(p[2]);
        absV = abs(v[0]) + abs(v[1]) + abs(v[2]);
    }

    bool operator<(const Particle& that) const {
        if (absA != that.absA) return absA < that.absA;
        if (absV != that.absV) return absV < that.absV;
        return absP < that.absP;
    }

    Particle& Next() {
        for (int i = 0; i < 3; i++) {
            v[i] += a[i];
        }
        for (int i = 0; i < 3; i++) {
            p[i] += v[i];
        }
        return *this;
    }

    uint64 Hash() {
       return Fingerprint(Fingerprint(p[0]) + p[1]) + p[2];
    }
};

// typedef unordered_set<Particle, ParticleHash> ParticleSet;
// 三个碰撞 都得毁， 用set会留一个

// unordered_map 如果放不进去，就意味重复，absA设置为-1
// 如果absA 为-1 则不添加
struct Soltuion {
    vector<Particle> P;

    void Solve() {
        while (true) {
            Particle a;
            if (!a.Read()) break;
            a.ComputeABS();
            P.emplace_back(a);
        }
        int ans1 = min_element(P.begin(), P.end()) - P.begin();
        printf("%d\n", ans1);
        for (int i = 0; i < 100; i++) {
            unordered_map<uint64, Particle> m;
            for (auto& i : P) {
                uint64 h = i.Hash();
                auto r = m.emplace(h, move(i));
                if (!r.second) {
                    r.first->second.absA = -1;
                }
            }
            P.clear();
            for (auto j : m) {
                if (j.second.absA != -1) {
                    P.emplace_back(j.second.Next());
                }
            }
        }
        printf("%d\n", int(P.size()));
    }
};

int main() {
    Soltuion().Solve();
    return 0;
}