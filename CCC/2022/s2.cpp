#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int X, Y, G;
    vector<pair<string, string>> in, out;
    set<pair<string, string>> p;

    int ans = 0;
    cin >> X;
    for (int i = 0; i < X; i++) {
        pair<string, string> a;
        cin >> a.first >> a.second;
        if (a.first > a.second) {
            swap(a.first, a.second);
        } 
        in.emplace_back(a);
    }
    cin >> Y;
    for (int i = 0; i < Y; i++) {
        pair<string, string> a;
        cin >> a.first >> a.second;
        if (a.first > a.second) {
            swap(a.first, a.second);
        }
        out.emplace_back(a);
    }
    cin >> G;
    for (int i = 0; i < G; i++) {
        vector<string> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        p.emplace(make_pair(a[0], a[1]));
        p.emplace(make_pair(a[1], a[2]));
        p.emplace(make_pair(a[0], a[2]));
    }

    for (const auto& no : in) {
        if (p.count(no) == 0) {
            ans++;
        }
    }
    for (const auto& no : out) {
        if (p.count(no)) {
            ans++;
        }
    }
    cout << ans << endl;
}