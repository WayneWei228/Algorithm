#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// x*x + 3*x + 2*x*y + y + y*y

typedef long long int int64;

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Coordinate {
    int x, y, distance;
    bool notWall;

    Coordinate& NotWall(int a, int b, int favorite) {
        x = a, y = b;
        int64 sum = x * x + 3 * x + 2 * x * y + y + y * y + favorite;
        int count = 0;
        while (sum > 0) {
            count = count + 1;
            sum = sum & (sum - 1);
        }
        if (count % 2 == 0)
            notWall = true;
        else
            notWall = false;
        return *this;
    }

    bool operator<(const Coordinate& that) const {
        return that.distance < distance;
    }

    bool Finish() {
        if (x == 31 && y == 39) return true;
        return false;
    }

    bool operator==(const Coordinate& that) const {
        return x == that.x && y == that.y;
    }

    vector<Coordinate> Children(int favourite) {
        vector<Coordinate> answer;
        answer.emplace_back(Coordinate{x + 1, y, distance + 1}.NotWall(
            x + 1, y, favourite));
        answer.emplace_back(Coordinate{x, y - 1, distance + 1}.NotWall(
            x, y - 1, favourite));
        answer.emplace_back(Coordinate{x - 1, y, distance + 1}.NotWall(
            x - 1, y, favourite));
        answer.emplace_back(Coordinate{x, y + 1, distance + 1}.NotWall(
            x, y + 1, favourite));
        return answer;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate& c) const {
        return Fingerprint(c.x) + c.y;
    }
};

typedef unordered_set<Coordinate, CoordinateHash> CoordinateSet;

struct Solution {
    priority_queue<Coordinate> queue;
    int favorite_num = 0;

    int Search1() {
        queue.emplace(Coordinate{1, 1, 0}.NotWall(1, 1, favorite_num));
        CoordinateSet hash;
        hash.emplace(Coordinate{1, 1, 0}.NotWall(1, 1, favorite_num));
        while (!queue.empty()) {
            auto top = queue.top();
            // cout << top.x << " " << top.y << " " << top.distance
            // << " " << endl;
            queue.pop();
            if (top.Finish()) return top.distance;
            for (auto& i : top.Children(favorite_num)) {
                if (i.x < 0 || i.y < 0) continue;
                if (i.notWall && hash.count(i) != 1) {
                    queue.emplace(i);
                    hash.emplace(i);
                }
            }
        }
        return 0;
    }
    int Search2() {
        while (!queue.empty()) {
            queue.pop();
        }
        queue.emplace(Coordinate{1, 1, 0}.NotWall(1, 1, favorite_num));
        CoordinateSet hash;
        hash.emplace(Coordinate{1, 1, 0}.NotWall(1, 1, favorite_num));
        while (!queue.empty()) {
            auto top = queue.top();
            queue.pop();
            for (auto& i : top.Children(favorite_num)) {
                if (i.x < 0 || i.y < 0) continue;
                if (i.notWall && hash.count(i) != 1 && i.distance <= 50) {
                    queue.emplace(i);
                    hash.emplace(i);
                }
            }
        }
        return int(hash.size());
    }
    void Solve() {
        scanf("%d", &favorite_num);
        printf("%d\n", Search1());
        printf("%d\n", Search2());
    }
};

int main() {
    Solution().Solve();
    return 0;
}