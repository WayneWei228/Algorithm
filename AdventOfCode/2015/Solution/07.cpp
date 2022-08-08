#include <cctype>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

char Buffer0[80], Buffer1[80], Buffer2[80];

struct Expression {
    enum { Const, Var, Not, And, Or, Lshift, Rshift } Op;
    unsigned short A0;
    string A1, A2;
};

struct Expressions {
    unordered_map<string, Expression> E;

    int Evaluate(const string& s) {
        if (isdigit(s[0])) return stol(s);
        switch (E[s].Op) {
            case Expression::Const:
                return E[s].A0;
            case Expression::Var:
                E[s].A0 = Evaluate(E[s].A1);
                break;
            case Expression::Not:
                E[s].A0 = ~Evaluate(E[s].A1);
                break;
            case Expression::And:
                E[s].A0 = Evaluate(E[s].A1) & Evaluate(E[s].A2);
                break;
            case Expression::Or:
                E[s].A0 = Evaluate(E[s].A1) | Evaluate(E[s].A2);
                break;
            case Expression::Lshift:
                E[s].A0 = Evaluate(E[s].A1) << Evaluate(E[s].A2);
                break;
            case Expression::Rshift:
                E[s].A0 = Evaluate(E[s].A1) >> Evaluate(E[s].A2);
                break;
        }
        E[s].Op = Expression::Const;
        return E[s].A0;
    }

    void AddExpression(const string& input) {
        Expression e;
        if (sscanf(input.c_str(), "NOT %s -> %s",  //
                   Buffer0, Buffer1) == 2) {
            e.Op = Expression::Not;
            e.A1 = Buffer0;
            E.emplace(Buffer1, e);
            return;
        }
        if (sscanf(input.c_str(), "%s -> %s",  //
                   Buffer0, Buffer1) == 2) {
            e.Op = Expression::Var;
            e.A1 = Buffer0;
            E.emplace(Buffer1, e);
            return;
        }
        if (sscanf(input.c_str(), "%s AND %s -> %s",  //
                   Buffer0, Buffer1, Buffer2) == 3) {
            e.Op = Expression::And;
            e.A1 = Buffer0;
            e.A2 = Buffer1;
            E.emplace(Buffer2, e);
            return;
        }
        if (sscanf(input.c_str(), "%s OR %s -> %s",  //
                   Buffer0, Buffer1, Buffer2) == 3) {
            e.Op = Expression::Or;
            e.A1 = Buffer0;
            e.A2 = Buffer1;
            E.emplace(Buffer2, e);
            return;
        }
        if (sscanf(input.c_str(), "%s LSHIFT %s -> %s",  //
                   Buffer0, Buffer1, Buffer2) == 3) {
            e.Op = Expression::Lshift;
            e.A1 = Buffer0;
            e.A2 = Buffer1;
            E.emplace(Buffer2, e);
            return;
        }
        if (sscanf(input.c_str(), "%s RSHIFT %s -> %s",  //
                   Buffer0, Buffer1, Buffer2) == 3) {
            e.Op = Expression::Rshift;
            e.A1 = Buffer0;
            e.A2 = Buffer1;
            E.emplace(Buffer2, e);
            return;
        }
    }
};

struct Solution {
    void Solve() {
        Expressions e1;
        while (true) {
            if (scanf("%[^\n]\n", Buffer0) < 1) break;
            e1.AddExpression(Buffer0);
        }
        Expressions e2(e1);
        int answer1 = e1.Evaluate("a");
        printf("%d\n", answer1);
        e2.E["b"].Op = Expression::Const;
        e2.E["b"].A0 = answer1;
        int answer2 = e2.Evaluate("a");
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}