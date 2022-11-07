#include <cstdio>
#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

// 集合问题无需考虑顺序

char Buffer[100005];
const int M = 18;
string a[1 << M];
string b[1 << M];
char c[1 << M];

struct Solution {
    string s, t;
    int q;

    int Bin(int x, int y) {
        if (x > y) swap(x, y);
        return y * M + x;
    }
    /*
    aabcd
    caabd
    */
    void Solve() {
        cin >> s >> t;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < M; j++) {
                a[Bin(s[i] - 'a', j)] += s[i];
            }
        }

        for (int i = 0; i < t.size(); i++) {
            for (int j = 0; j < M; j++) {
                b[Bin(t[i] - 'a', j)] += t[i];
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                c[Bin(i, j)] = (a[Bin(i, j)] == b[Bin(i, j)]);
            }
        }
        cin >> q;
        for (int i = 0; i < q; i++) {
            string o;
            cin >> o;
            bool f = true;
            for (int j = 0; j < o.size(); j++) {
                for (int k = 0; k <= j; k++) {
                    if (!c[Bin(o[j] - 'a', o[k] - 'a')]) {
                        f = false;
                    }
                }
            }
            cout << (f ? 'Y' : 'N');
        }
        cout << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}