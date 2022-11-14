#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

using P = pair<long long, long long>;
P operator+(P a, P b) {
    return {a.first + b.first, a.second + b.second};
}
P operator-(P a, P b) {
    return {a.first - b.first, a.second - b.second};
}

vector<pair<P, int>> all_subsets(const vector<P> &dirs) {
    vector<pair<P, int>> v{{}};
    for (const P &d : dirs) {
        v.resize(v.size() * 2);
        for (int i = 0; i < v.size() / 2; i++) {
            v[i + v.size() / 2] = {v[i].first + d, v[i].second + 1};
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main() {
    int N;
    cin >> N;
    P goal;
    cin >> goal.first >> goal.second;
    vector<P> dirs(N);
    for (auto &d : dirs) {
        cin >> d.first >> d.second;
    }
    vector<pair<P, int>> a =
        all_subsets(vector<P>(begin(dirs), begin(dirs) + N / 2));
    vector<pair<P, int>> b =
        all_subsets(vector<P>(begin(dirs) + N / 2, end(dirs)));
    reverse(b.begin(), b.end());
    vector<long long> ans(N + 1);
    vector<int> with_num;  // 用b 里 k 条指令
    P rest_prev{1e18, 1e18};
    int ib = 0;
    for (const auto &[offset, num] : a) {
        auto need = goal - offset;
        if (need != rest_prev) {
            rest_prev = need;
            with_num = vector<int>(N - N / 2 + 1); // 一半的指令
            for (; ib < b.size() && b[ib].first > need; ib++)
                ;
            for (; ib < b.size() && b[ib].first == need; ib++) {
                ++with_num[b[ib].second];
            }
        } 
        for (int i = 0; i < with_num.size(); i++) {
            ans[i + num] += with_num[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}