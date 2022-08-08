#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

struct Soluiton {
    vector<int> V;
    int64 ans1 = 0;

    int64 Dfs(int no) {
        int c = V[no];
        int m = V[no + 1];
        int64 dis = 2;
        for (int i = 0; i < c; i++) {
            dis += Dfs(no + dis);
        }
        for (int i = 0; i < m; i++) {
            ans1 += V[no + dis + i];
        }
        dis += m;
        return dis;
    }

    int64 Dfs2(int no, int64& len) {
        int c = V[no];
        int m = V[no + 1];
        int64 dis = 2;
        vector<int64> v;
        int64 sum = 0;
        for (int i = 0; i < c; i++) {
            int64 a = Dfs2(no + dis, dis);
            v.emplace_back(move(a));
        }
        if (c == 0) {
            for (int i = 0; i < m; i++) {
                sum += V[no + dis + i];
            }
        } else {
            for (int i = 0; i < m; i++) {
                int idx = V[no + dis + i] - 1;
                if (idx >= v.size() || idx < 0) continue;
                sum += v[idx];
            }
        }
        dis += m;
        len += dis;
        return sum;
    }

    void Solve() {
        int d;
        while (scanf("%d ", &d) == 1) {
            V.emplace_back(d);
        }
        int no = 0;
        int64 len = 0;
        while (no < int(V.size())) {
            no += Dfs(no);
        }
        printf("%lld\n", ans1);
        printf("%lld\n", Dfs2(0, len));
    }
};

int main() {
    Soluiton().Solve();
    return 0;
}