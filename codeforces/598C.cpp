#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://mathinsight.org/polar_coordinates
/*
y / x = (r * sin(a)) / (r * cos(a)) = tan(a)
a = atan(y / x)
*/

#define PI 3.14159265

long double getAngle(int X, int Y) { return atan2(Y, X) * 180 / PI; }
struct Coordinate {
    int X, Y, id;
    long double angle;
    bool operator<(const Coordinate& that) const {
        return this->angle > that.angle;
    }
};

struct Solution {
    int N;
    vector<Coordinate> nodes;
    double mindiff = numeric_limits<double>::max();
    pair<int, int> ans;

    void Solve() {
        cin >> N;
        nodes.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> nodes[i].X >> nodes[i].Y;
            nodes[i].id = i + 1;
            nodes[i].angle = getAngle(nodes[i].X, nodes[i].Y);
        }
        // cout << endl;
        sort(nodes.begin(), nodes.end());
        // for (auto i : nodes) {
        //     cout << i.X << " " << i.Y << " " << getAngle(i.X, i.Y)
        //          << " " << i.id << endl;
        // }
        for (int i = 0; i < nodes.size() - 1; i++) {
            long double diff = nodes[i].angle - nodes[i + 1].angle;
            if (diff < mindiff) {
                mindiff = diff;
                ans.first = nodes[i].id;
                ans.second = nodes[i + 1].id;
            }
        }
        long double diff = 360 - nodes[0].angle + nodes[N - 1].angle;
        if (diff < mindiff) {
            mindiff = diff;
            ans.first = nodes[0].id;
            ans.second = nodes[N - 1].id;
        }
        cout << ans.first << " " << ans.second << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}