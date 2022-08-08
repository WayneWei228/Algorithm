#include <cstdio>
#include <limits>
#include <string>
#include <vector>
using namespace std;

struct Point {
    int x, y, dx, dy;
};

struct Solution {
    vector<Point> input;

    void ForInput(int time, function<void(const Point&)> f) {
        for (Point i : input) {
            i.x += i.dx * time;
            i.y += i.dy * time;
            f(i);
        }
    }

    int Range(int time, int& minX, int& maxX, int& minY, int& maxY) {
        minX = numeric_limits<int>::max();
        maxX = numeric_limits<int>::min();
        minY = numeric_limits<int>::max();
        maxY = numeric_limits<int>::min();
        ForInput(time, [&](const Point& p) {
            if (p.x < minX) minX = p.x;
            if (p.y < minY) minY = p.y;
            if (p.x > maxX) maxX = p.x;
            if (p.y > maxY) maxY = p.y;
        });
        return (maxX - minX + 1) + (maxY - minY + 1);
    }

    void Show(int time) {
        int minX, maxX, minY, maxY;
        Range(time, minX, maxX, minY, maxY);
        printf("%d, %d, %d, %d\n", minX, maxX, minY, maxY);
        vector<string> m(maxY - minY + 1);
        for (int i = 0; i < m.size(); ++i) {
            m[i].resize(maxX - minX + 1, '.');
        }
        ForInput(time, [&](const Point& p) {
            m[p.y - minY][p.x - minX] = '#';
        });
        for (const auto& i : m) {
            printf("%s\n", i.c_str());
        }
    }

    void Solve() {
        while (true) {
            Point p;
            if (scanf("position=<%d,%d> velocity=<%d,%d> ", &p.x, &p.y,
                      &p.dx, &p.dy) < 4)
                break;
            input.emplace_back(move(p));
        }
        int minX, maxX, minY, maxY;
        int initial = Range(0, minX, maxX, minY, maxY);
        int minRange = numeric_limits<int>::max();
        int arg = -1;
        for (int i = 1;; i++) {
            int range = Range(i, minX, maxX, minY, maxY);
            if (range < minRange) {
                minRange = range;
                arg = i;
            }
            if (initial < range) break;
        }
        Show(arg);
        printf("%d\n", arg);
    }
};

int main() {
    Solution().Solve();
    return 0;
}