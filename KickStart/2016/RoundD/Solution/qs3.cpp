#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[4001];

typedef long long int64;

const int M = 1000000007;

struct Solution {
    int V, S;
    vector<string> A; 

    void Solve(int caseNo) {
        scanf("%d%d", &V, &S);
        A.resize(V);
        for (string& i : A) {
            scanf("%s", Buffer);
            i = Buffer;
            sort(i.begin(), i.end());
        }
        printf("Case #%d:", caseNo);
        for (int i = 0; i < S; i++) {
            scanf("%s", Buffer);
            string s = Buffer;
            printf(" %d", Compute(s));
        }
        printf("\n");
    }

    int Compute(const string& s) {
        vector<int> f(s.size() + 1); // f[k] 表示 下标从 [0, k - 1] 的串有多少种原序列
        // f[k] 表示 长度为k的前缀      
        // 包含 0 ～ size 的所有状态， 故size + 1
        // k = 0 是空串
        // why add 1
        f[0] = 1; // 空串对应的原串就是空串
        for (int i = 0; i < s.size(); i++) {
            for (const string& j : A) {
                string a0 = s.substr(i, j.size());
                sort(a0.begin(), a0.end());
                if (a0 != j) continue;
                f[i + j.size()] += f[i]; // 你行的我都行，别人行的我也行，我是你加别人
                f[i + j.size()] %= M;
            }
        }
        return f.back();
    } 
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}