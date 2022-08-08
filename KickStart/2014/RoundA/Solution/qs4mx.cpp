#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[11], Buffer1[11];

struct Equation {
    int v0, v1, W;
};

struct Edge {
    int To, W;
};

struct Expression {
    int A, X;
    double c;
};

struct Solution {
    unordered_map<string, int> ToNumber;
    vector<Equation> Input;
    vector<vector<Edge>> Out;
    vector<Expression> E;

    void Solve(int caseNo) {
        int N;
        scanf("%d", &N);
        auto getNumber = [&](const string& input) {
            return ToNumber.emplace(input, ToNumber.size())
                .first->second;
        };
        for (int i = 0; i < N; i++) {
            int w;
            scanf(" %[^+]+%[^=]=%d", Buffer, Buffer1, &w);
            Input.emplace_back(
                Equation{getNumber(Buffer), getNumber(Buffer1), w});
        }
        Out.resize(ToNumber.size());
        for (auto i : Input) {
            Out[i.v0].emplace_back(Edge{i.v1, i.W});
            Out[i.v1].emplace_back(Edge{i.v0, i.W});
        }
        Input.clear();
        E.resize(Out.size(), Expression{0, -1, 0});
        for (int i = 0; i < E.size(); i++) {
            if (E[i].X == -1) Visit(i, Expression{1, i, 0});
        }
        auto GetValue = [&](int no) {
            if (E[no].A == 0) return Expression{0, -1, E[no].c};
            if (E[E[no].X].A != 0) return E[no];
            double c = E[E[no].X].c;
            double ans = E[no].A * c + E[no].c;
            return Expression{0, -1, c}; 
        };
        printf("Case #%d:\n", caseNo);
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf(" %[^+]+%s", Buffer, Buffer1);
            int v0 = getNumber(Buffer);
            int v1 = getNumber(Buffer1);
            if (v0 >= Out.size() || v1 >= Out.size()) continue;
            Expression e0 = GetValue(v0), e1 = GetValue(v1);
            if (e0.X != e1.X) continue;
            if (e0.A + e1.A != 0) continue;
            printf("%s+%s=%.0lf\n", Buffer, Buffer1, e0.c + e1.c);
        }
    }

    void Visit(int no, const Expression& v) {
        if (E[no].A == 0) return; 
        if (E[no].X != -1) {
            if (E[no].A != v.A) {
                // a1x + c1 = a2x + c2
                double c = (v.c - E[no].c) / (E[no].A - v.A);
                E[no] = Expression{0, -1, c};
            }
        } else {
            E[no] = v;
            for (auto i : Out[no]) {
                Visit(i.To, Expression{-v.A, v.X, i.W - v.c});
            }
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}