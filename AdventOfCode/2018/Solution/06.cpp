#include <cstdio>
#include <cstdlib>
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

struct Solution {
    vector<Coordinate> Input;
    unordered_set<Coordinate, CoordinateHash> U; // 坐标集合

    int Distance(int no, int x, int y) {
        // 给定 id 和 坐标，找曼哈顿距离
        return abs(Input[no].X - x) + abs(Input[no].Y - y);
    }

    vector<int> Distances(int x, int y) {
        // 给定坐标找该坐标到所有点的距离，返回vector<int>
        vector<int> answer(Input.size());
        for (int i = 0; i < Input.size(); ++i) {
            answer[i] = Distance(i, x, y);
        }
        return answer;
    }

    int ArgminDistance(int x, int y) {  // 找到最小距离的 id
        vector<int> distances = Distances(x, y);
        int minDistance = numeric_limits<int>::max();
        int argmin = -1;
        for (int i = 0; i < distances.size(); ++i) {
            if (distances[i] < minDistance) {
                // 如果有更小的距离，则刷新， id也刷新
                minDistance = distances[i];
                argmin = i;
            } else if (distances[i] == minDistance) {
                // 如果出现两个相同的最短距离，id变 -1
                // 如果有更短的还会刷新，故不用担心
                argmin = -1;
            }
        }
        return argmin;
    }

    int SumDistance(int x, int y) { // 距离和
        vector<int> distances = Distances(x, y);
        int answer = 0;
        for (int i : distances) answer += i;
        return answer;
    }

    void Visit(const Coordinate& c) {
        // 不符要求 或 访问过，返回
        if (10000 <= SumDistance(c.X, c.Y) || U.count(c)) return;
        // 此外，加入U
        U.insert(c);
        // 遍历
        Visit(Coordinate{c.X + 1, c.Y});
        Visit(Coordinate{c.X, c.Y + 1});
        Visit(Coordinate{c.X - 1, c.Y});
        Visit(Coordinate{c.X, c.Y - 1});
    }

    void Solve() {
        while (true) {
            Coordinate c;
            if (scanf("%d,%d", &c.X, &c.Y) < 2) break;
            Input.emplace_back(move(c));
        }
        int minX = numeric_limits<int>::max();
        int maxX = numeric_limits<int>::min();
        int minY = numeric_limits<int>::max();
        int maxY = numeric_limits<int>::min();
        // 框住范围
        for (const Coordinate& i : Input) {
            if (i.X < minX) minX = i.X;
            if (maxX < i.X) maxX = i.X;
            if (i.Y < minY) minY = i.Y;
            if (maxY < i.Y) maxY = i.Y;
        }
        vector<int> areaSize(Input.size());
        for (int i = minX; i <= maxX; ++i) {
            for (int j = minY; j <= maxY; ++j) {
                int arg = ArgminDistance(i, j);
                // 如果该点到两点距离相等或者该点对映id为无限面积，跳过
                if (arg == -1 || areaSize[arg] == -1) continue;
                ++areaSize[arg];
                // 最外层方框所对映的id则表示该点为无穷面积，所以设置 areaSize为-1
                if (i == minX || i == maxX) areaSize[arg] = -1;
                if (j == minY || j == maxY) areaSize[arg] = -1;
            }
        }
        printf("%d\n", *max_element(areaSize.begin(), areaSize.end()));
        for (int i = minX; i <= maxX; ++i) {
            for (int j = minY; j <= maxY; ++j) Visit(Coordinate{i, j});
        }
        printf("%d\n", int(U.size()));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
