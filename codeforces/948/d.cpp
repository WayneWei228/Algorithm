/**
 *    author:  tourist
 *    created: 26.05.2024 10:46:16
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    mt19937_64 rng((unsigned int)chrono::steady_clock::now()
                       .time_since_epoch()
                       .count());
    int tt;
    // cin >> tt;
    // while (tt--) {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    vector<uint64_t> coeff(h);
    for (int i = 0; i < h; i++) {
        coeff[i] = rng();
    }

    // for (auto i : coeff) {
    //     cout << i << " ";
    // }
    // cout << endl;

    vector<pair<uint64_t, int>> all;
    all.reserve(h * w);
    for (int j = 0; j < w; j++) {
        uint64_t v = 0;
        for (int i = 0; i < h; i++) {
            if (s[i][j] == '1') {
                v ^= coeff[i];
            }
        }
        for (int i = 0; i < h; i++) {
            all.emplace_back(v ^ coeff[i], i * w + j);
        }
    }

    sort(all.begin(), all.end());
    for (auto i : all) {
        cout << i.first << " " << i.second << endl;
    }
    int mx = 0;
    int at = -1;
    int beg = 0;
    while (beg < h * w) {
        int end = beg;
        while (end + 1 < h * w &&
               all[end + 1].first == all[end].first) {
            end += 1;
        }
        int cnt = end - beg + 1;
        if (cnt > mx) {
            mx = cnt;
            at = all[beg].second;
        }
        beg = end + 1;
    }
    cout << mx << '\n';
    int row = at / w;
    int col = at % w;
    s[row][col] ^= 1;
    for (int i = 0; i < h; i++) {
        cout << s[i][col];
    }
    cout << '\n';
    // }
    return 0;
}