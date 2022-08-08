#include <cstdio>
#include <functional>
#include <limits>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;

struct Point {
    int X, Y, DX, DY;
};

struct Solution {
    vector<Point> Input;

    void ForInput(int time, function<void(const Point&)> visit) {
        for (Point i : Input) {
            i.X += i.DX * time;
            i.Y += i.DY * time;
            // 移动后的Point 回到visit方法中
            visit(i);
        }
    }

    int64 Range(int time, int& minX, int& maxX, int& minY, int& maxY) {
        minX = numeric_limits<int>::max();
        maxX = numeric_limits<int>::min();
        minY = numeric_limits<int>::max();
        maxY = numeric_limits<int>::min();
        // 框定范围
        ForInput(time, [&](const Point& p) {
            // 引用传递，修改范围
            if (p.X < minX) minX = p.X;
            if (maxX < p.X) maxX = p.X;
            if (p.Y < minY) minY = p.Y;
            if (maxY < p.Y) maxY = p.Y;
        });
        // 返回面积
        return (maxX - minX + 1) * (maxY - minY + 1);
    }

    void Show(int time) {
        int minX, maxX, minY, maxY;
        Range(time, minX, maxX, minY, maxY);
        // 初始化大小
        printf("%d, %d, %d, %d\n", minX, maxX, minY, maxY);
        vector<string> c(maxY - minY + 1);
        for (int i = 0; i < c.size(); ++i) {
            c[i].resize(maxX - minX + 1, '.');
        }
        // 输出
        ForInput(time, [&](const Point& p) {
            c[p.Y - minY][p.X - minX] = '#';
        });
        // for (const string& i : c) {
        //     printf("%s\n", i.c_str());
        // }
    }

    void Solve() {
        while (true) {
            Point p;
            if (scanf("position=<%d,%d> velocity=<%d,%d> ",  //
                      &p.X, &p.Y, &p.DX, &p.DY) < 4) {
                break;
            }
            Input.emplace_back(move(p));
        }
        int minX, maxX, minY, maxY;
        int64 initRange = Range(0, minX, maxX, minY, maxY);
        int64 minRange = numeric_limits<int64>::max();
        int arg = -1;
        // O(n * time);
        for (int i = 1;; ++i) {
            int range = Range(i, minX, maxX, minY, maxY);
            if (range < minRange) {
                minRange = range;
                arg = i;
            }
            // 如果最开始的范围比移动后范围还小，说明最开始则为最小
            // 或者说 运动后比最初状态还分散，则该停止运动
            if (initRange < range) break;
        }
        Show(arg);
        printf("%d\n", arg);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
