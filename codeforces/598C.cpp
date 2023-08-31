#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// https://mathinsight.org/polar_coordinates
/*
y / x = (r * sin(a)) / (r * cos(a)) = tan(a)
a = atan(y / x)
*/

struct Solution {
    int N;
    vector<pair<long double, int>> nodes;
    pair<int, int> ans;
    long double mxangle = numeric_limits<double>::max(); // long double important

    void Solve() {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            nodes.push_back(make_pair(atan2(b, a), i + 1));
        }
        sort(nodes.begin(), nodes.end());
        nodes.push_back(nodes[0]);
        for (int i = 0; i < nodes.size() - 1; i++) {
            long double diff = nodes[i + 1].first - nodes[i].first;
            if (diff < 0) diff += 2 * acos(-1);
            if (diff < mxangle) {
                mxangle = diff;
                ans.first = nodes[i].second;
                ans.second = nodes[i + 1].second;
            }
        }
        cout << ans.first << " " << ans.second << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}