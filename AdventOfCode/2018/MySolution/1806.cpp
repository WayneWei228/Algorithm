#include <algorithm>
#include <cstdio>
#include <limits>
#include <unordered_set>
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

uint64 Hash(int x, int y) { return Fingerprint(x) + y; }

/*
355, 246
259, 215
166, 247
280, 341
54, 91
314, 209
*/

struct Coordinate {
    int x, y;

    bool operator==(const Coordinate& that) const {
        return that.x == x && that.y == y;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate& that) const {
        return Fingerprint(that.x) + that.y;
    }
};

typedef unordered_set<Coordinate, CoordinateHash> CoordinateSet;

struct Solution {
    vector<Coordinate> input;
    vector<vector<int>> map;
    CoordinateSet coSet;
    int min_x = numeric_limits<int>::max();
    int min_y = numeric_limits<int>::max();
    int max_x = numeric_limits<int>::min();
    int max_y = numeric_limits<int>::min();

    int Distance(int no, int x, int y) {
        return abs(input[no].x - x) + abs(input[no].y - y);
    }

    int id_Distance(int x, int y) {
        int id = -1;
        int minDistance = numeric_limits<int>::max();
        for (int i = 0; i < int(input.size()); i++) {
            int dis = Distance(i, x, y);
            if (dis < minDistance) {
                minDistance = dis;
                id = i;
            } else if (minDistance == dis) {
                id = -1;
            }
        }
        return id;
    }

    int sumDistance(int x, int y) {
        int sum = 0;
        for (int i = 0; i < int(input.size()); i++) {
            sum += Distance(i, x, y);
        }
        return sum;
    }

    void Visited(int x, int y) {
        if (sumDistance(x, y) >= 10000 || coSet.count(Coordinate{x, y}))
            return;
        coSet.emplace(Coordinate{x, y});
        Visited(x + 1, y);
        Visited(x - 1, y);
        Visited(x, y + 1);
        Visited(x, y - 1);
    }

    void Solve() {
        int left, right;
        while (scanf("%d, %d ", &right, &left) == 2) {
            if (left < min_x) min_x = left;
            if (left > max_x) max_x = left;
            if (right < min_y) min_y = right;
            if (right > max_y) max_y = right;
            input.emplace_back(Coordinate{left, right});
        }

        vector<int> areaSize(int(input.size()));

        for (int i = min_x; i <= max_x; i++) {
            for (int j = min_y; j <= max_y; j++) {
                int id = id_Distance(i, j);
                if (id == -1 || areaSize[id] == -1) continue;
                areaSize[id]++;
                if (i == min_x || i == max_x) areaSize[id] = -1;
                if (j == min_y || j == max_y) areaSize[id] = -1;
            }
        }
        int largest = *max_element(areaSize.begin(), areaSize.end());
        printf("%d\n", largest);

        for (int i = min_x; i <= max_x; i++) {
            for (int j = min_y; j <= max_y; j++) {
                Visited(i, j);
            }
        }
        printf("%d\n", int(coSet.size()));
    }
};

int main() {
    Solution().Solve();
    return 0;
}