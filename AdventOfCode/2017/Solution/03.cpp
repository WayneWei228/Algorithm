#include <cstdio>
#include <cstdlib>
#include <unordered_map>
using namespace std;

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Coordinate {
    int X, Y;

    bool operator==(const Coordinate& that) const {
        return X == that.X && Y == that.Y;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate& c) const {
        return Fingerprint(c.X) + c.Y;
    }
};

typedef unordered_map<Coordinate, int, CoordinateHash> CoordinateInts;

struct Spiral {
    CoordinateInts C;

    virtual int Get(int x, int y) = 0;

    void Go(int& x, int& y, int direction) {
        switch (direction) {
            case 0:
                ++x;
                break;
            case 1:
                ++y;
                break;
            case 2:
                --x;
                break;
            case 3:
                --y;
                break;
        }
    }

    void Visit(int bound, int& x, int& y, int& z) {
        x = 0;
        y = 0;
        int direction = 0;
        while (true) {
            z = C[Coordinate{x, y}] = Get(x, y);
            if (bound < z) break;
            Go(x, y, direction);
            int xNext = x, yNext = y, dNext = (direction + 1) % 4;
            Go(xNext, yNext, dNext);
            if (C.count(Coordinate{xNext, yNext}) == 0) {
                direction = dNext;
            }
        }
    }
};

struct Spiral1 : public Spiral {
    int No = 1;

    int Get(int x, int y) { return No++; }
};

struct Spiral2 : public Spiral {
    int Get(int x, int y) {
        if (x == 0 && y == 0) return 1;
        int answer = 0;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                auto it = C.find(Coordinate{i, j});
                if (it != C.end()) answer += it->second;
            }
        }
        return answer;
    }
};

struct Solution {
    int N;

    void Solve() {
        scanf("%d", &N);
        int x, y, z;
        Spiral1().Visit(N - 1, x, y, z);
        printf("%d\n", abs(x) + abs(y));
        Spiral2().Visit(N, x, y, z);
        printf("%d\n", z);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
