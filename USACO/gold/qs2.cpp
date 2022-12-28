#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Solution {
    int N, Q;
    vector<int> height;

    long long answer = 0;
    vector<set<int>> seeLeft, seeRight;

    bool canSee(int a, int b, int c) {
        return height[b] <= (height[a] * (c - b) + height[c] * (b - a));
    }

    void CheckLeft(int x) {
        answer -= seeLeft[x].size();
        seeLeft[x].clear();
        for (int i = x - 1; i > 0; i--) {
            if (seeLeft[x].size() == 0 ||
                canSee(i, *seeLeft[x].begin(), x)) {
                seeLeft[x].insert(i);
            }
        }
        answer += seeLeft[x].size();
    }

    void Solve() {
        scanf("%d", &N);
        height.resize(N + 1);
        seeLeft.resize(N + 1);
        seeRight.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &height[i]);
        }
        for (int i = 1; i <= N; i++) {
            CheckLeft(i);
        }

        scanf("%d", &Q);

        for (int t = 0; t < Q; t++) {
            int position, increment;
            scanf("%d%d", &position, &increment);
            answer -= seeLeft[position].size();
            seeLeft[position].clear();

            height[position] += increment;
            for (int i = position - 1; i > 0; i--) {
                if (seeLeft[position].size() == 0 ||
                    canSee(i, *seeLeft[i].rbegin(), position)) {
                    seeLeft[i].emplace(position);
                }
            }
            answer += seeLeft.size();
            for (int i = position + 1; i <= N; i++) {
                if (seeRight[i].size() == 0 ||
                    canSee(position, *seeRight[i].rbegin(), i)) {
                    seeRight[i].emplace(i);
                    auto u = seeLeft[i].insert(position);
                    if (u.second) {
                        answer++;
                    }
                    auto it = u.first;
                    while (true) {
                        auto ti = it;
                        if (ti == seeLeft[i].begin()) {
                            break;
                        }
                        ti--;
                        if (!canSee(*ti, position, i)) {
                            seeLeft[i].erase(ti);
                            answer--;
                        } else {
                            break;
                        }
                    }
                }
            }
            printf("%lld\n", answer);
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}