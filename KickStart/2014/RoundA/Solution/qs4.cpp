#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer0[11], Buffer1[11];

// 解题思路：一整块连通区域用一个variable表示所有variable
// 奇数边可解 偶数边不可解 -> x + b = x + c
// 奇数边，variable系数为异
// 偶数边，variable系数为同


struct Equation {
    int V0, V1, W; // V0 V1 两个点，类似apple banana, 和
};

struct Edge {
    int To, W; // 目的点，点和目的点的和
};

struct Expression {
    int A, X; // 一个变量的表示方法为 A * V[X] + C
    double C; // V[X] 
};

struct Solution {
    int N;
    vector<vector<Edge>> Out;
    vector<Expression> E; // 每个点的算式

    void Solve(int caseNo) {
        scanf("%d", &N);
        unordered_map<string, int> toNumber;
        auto mapToNumber = [&](const string &s) {
            return toNumber.emplace(s, toNumber.size()).first->second;
        };
        vector<Equation> input;
        for (int i = 0; i < N; ++i) {
            int w;
            scanf(" %[^+]+%[^=]=%d", Buffer0, Buffer1, &w);
            int v0 = mapToNumber(Buffer0);
            int v1 = mapToNumber(Buffer1);
            input.emplace_back(Equation{v0, v1, w});
        }
        Out.resize(toNumber.size());
        for (const Equation &i : input) {
            Out[i.V0].emplace_back(Edge{i.V1, i.W});
            Out[i.V1].emplace_back(Edge{i.V0, i.W});
        }
        input.clear();
        E.resize(Out.size(), Expression{1, -1, 0}); // 每个变量都有其值
        for (int i = 0; i < Out.size(); ++i) {
            if (E[i].X == -1) Visit(i, Expression{1, i, 0}); // a = a
        }
        printf("Case #%d:\n", caseNo);
        scanf("%d", &N);
        auto getValue = [this](int no) {
            // E[no] 如果是固定值，
            // 固定值有两种方式：1.本身已求出值 （就是根）
            // 2.引用已求出值 （当前为根的表达式，根算出来了）
            if (E[no].A == 0) return Expression{0, -1, E[no].C}; // 1.
            if (E[E[no].X].A != 0) return E[no]; // 
            double x = E[E[no].X].C;
            double c = E[no].C + E[no].A * x;
            // 约定：A为0的情况下，X都为-1
            return Expression{0, -1, c}; // 2.
        };
        for (int i = 0; i < N; ++i) {
            scanf(" %[^+]+%s", Buffer0, Buffer1);
            int v0 = mapToNumber(Buffer0);
            int v1 = mapToNumber(Buffer1);
            if (Out.size() <= v0 || Out.size() <= v1) continue; // 出现一个新的变量，跳过
            Expression e0 = getValue(v0), e1 = getValue(v1);
            if (e0.X != e1.X) continue; // x = -1 证明这个是个常数
            if (e0.A + e1.A != 0) continue; 
            printf("%s+%s=%.0lf\n", Buffer0, Buffer1, e0.C + e1.C);
        }
    }
    // 目标：number这个点，A X C 都填上
    // 同一个连通分支 v.X 都是一样
    void Visit(int no, const Expression &v) {
        // 这个数不参考v.X, 
        if (E[no].A == 0) return; // 81行造成
        if (E[no].X != -1) { // 访问过
            if (E[no].A != v.A) { 
                // a1 * x + c1 = a2 * x + c2
                // x = (c2 - c1) / (a1 - a2)
                double c = (v.C - E[no].C) / (E[no].A - v.A);
                E[v.X] = Expression{0, -1, c};
                // E 和 V 对应
            }
            /*
            a + 1 = a // 无解
            if (E[no].A == v.A) {
                if (E[no].C != v.C) {
                    return "contradiction";
                }
            }
            */
        } else {
            // normal
            E[no] = v;
            for (Edge &i : Out[no]) {
                // i.W - (v.A * V[v.X] + v.C)
                // 系数成为 -v.A
                // -v.A * V[v.X] + i.W - v.C
                Visit(i.To, Expression{-v.A, v.X, i.W - v.C});
                // 传的都是v.X
            }
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}