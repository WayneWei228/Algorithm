#include <cstdio>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

struct Coordinate {
    int x, y;

    bool operator<(const Coordinate& that) const {
        if (x != that.x) return x < that.x;
        return y < that.y;
    }
};

struct Solution {
    int n;
    vector<Coordinate> input;
    unordered_map<int, int> density_row, density_col;
    void Solve(int caseNo) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int lx, ly, rx, ry;
            scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
            for (int j = lx; j <= rx; j++) {
                for (int k = ly; k <= ry; k++) {
                    input.emplace_back(Coordinate{j, k});
                    density_row[k] += 1;
                    density_col[j] += 1;
                }
            }
        }

        printf("Case #%d:\n", caseNo);
        for (auto i : density_row) {
            printf("%d %d\n", i.first, i.second);
        }
        printf("seperate\n");
        for (auto i : density_col) {
            printf("%d %d\n", i.first, i.second);
        }

        double average_row, average_col;
        int rowfenzi = 0, rowfenmu = 0;
        int colfenzi = 0, colfenmu = 0;
        for (const auto& i : density_row) {
            rowfenzi += i.first * i.second;
            rowfenmu += i.second;
        }
        average_row = rowfenzi / rowfenmu;
        printf("pingjun row %f\n", average_row);

        for (const auto& i : density_col) {
            colfenzi += i.first * i.second;
            colfenmu += i.second;
        }
        average_col = colfenzi / colfenmu;
        printf("pingjun col %f\n", average_col);

        int dis = numeric_limits<int>::max();
        vector<Coordinate> store;
        int MinX, MinY;
        sort(input.begin(), input.end());
        for (int i = 0; i < input.size(); i++) {
            if (abs(input[i].x - average_col) +
                    abs(input[i].y - average_row) <
                dis) {
                dis = abs(input[i].x - average_col) +
                      abs(input[i].y - average_row);
                MinX = input[i].x;
                MinY = input[i].y;
                // store.clear();
                // store.emplace_back(Coordinate{MinX, MinY});
            }
        }
        printf("%d %d\n", MinX, MinY);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}