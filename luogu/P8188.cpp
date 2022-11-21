#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

struct Solution {
    int t, m, n, k;
    set<pair<int, int> > passed;
    set<pair<int, int> > i2ai, ai2i;
    int a[100020];
    int c[100020];
    int fp = 1, ap = 1;
    void Solve() {
        cin >> m >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ++c[a[i]];
        }
        while (true) {
            // 加到范围k
            while (i2ai.size() < k && (passed.size() > 0 || ap <= n)) {
                if (ap <= n) {
                    i2ai.insert(make_pair(ap, a[ap]));
                    ai2i.insert(make_pair(a[ap], ap));
                    ap++;
                } else {
                    auto it = *--passed.end();
                    i2ai.insert(it);
                    ai2i.insert(make_pair(it.second, it.first));
                    passed.erase(it);
                }
            }
            // 调整文件箱上界
            while (fp + k - 1 < m && !c[fp]) {
                fp++;
            }
            bool changed = false;
            while (true) {
                auto it = ai2i.lower_bound(make_pair(fp, 0));
                if (it != ai2i.end() && it->first <= fp + k - 1) {
                    --c[it->first];
                    i2ai.erase(make_pair(it->second, it->first));
                    ai2i.erase(it);
                    changed = true;
                } else {
                    break;
                }
            }
            if (!changed) {
                if (ap <= n) {
                    i2ai.insert(make_pair(ap, a[ap]));
                    ai2i.insert(make_pair(a[ap], ap));
                    ap++;
                    if (i2ai.size() > k) {
                        passed.insert(*i2ai.begin());
                        auto it = i2ai.begin();
                        i2ai.erase(it);
                        ai2i.erase(make_pair(it->second, it->first));
                    }
                } else {
                    break;
                }
            }
        }
        cout << ((ai2i.size() == 0) ? "YES" : "NO") << endl;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        Solution().Solve();
    }
    return 0;
}