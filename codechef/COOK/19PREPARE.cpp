#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
无限工人
两位厨师
求最短时间
最长时间 <= 工人最大时间

二分查找答案
工人完成时间小于t
给工人做
两个厨师只需做工人做不了的任务
两个变量，t1, t2, 表示厨师做这单之前的总时间
每次把任务分配给总时间小的那一个人

*/

struct Time {
    int worker;
    int chef;
};

struct  Solution {
    int N;
    vector<Time> T;
    int l = 0, r = 0;
    void Solve() {
        scanf("%d", &N);
        T.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &T[i].worker, &T[i].chef);
            if (T[i].worker > r) {
                r = T[i].worker;
            }
        }
        /*
        左边不行右边行
        向右靠近
        */
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (Can(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", l);
    }

    bool Can(int t) {
        vector<int> tt;
        for (int i = 0; i < T.size(); i++) {
            if (T[i].worker > t) {
                tt.emplace_back(T[i].chef);
                if (T[i].chef > t) {
                    return false;
                }
            }
        }
        int t1 = 0, t2 = 0;
        for (int i = 0; i < tt.size(); i++) {
            if (t1 >= t2) {
                t2 += tt[i];
            } else {
                t1 += tt[i];
            }
        }
        return max(t1, t2) <= t;
    }

};


int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}