#include <cstdio>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer0[80], Buffer1[80], Buffer2[80], Buffer3[80];

struct Instruction;

struct Computer {
    vector<Instruction> Instructions;
    unordered_map<string, int> C{};
    int R;
    int Ans2 = numeric_limits<int>::min();
    Computer& Run();
};

struct Instruction {
    enum Operation { Inc, Dec } Op;
    enum Condition {
        Dayu,
        Dayudengyu,
        Xiaoyu,
        Xiaoyudengyu,
        Dengyu,
        Budengyu
    } Cd;
    string regis, con_regis;
    int value, con_value;

    void Do(Computer& c) {
        if (Op == Inc) {
            c.C[regis] += value;
        } else {
            c.C[regis] -= value;
        }
    }

    void WhetherDo(Computer& c) {
        switch (Cd) {
            case Dayu:
                if (c.C[con_regis] > con_value) Do(c);
                c.R++;
                break;
            case Dayudengyu:
                if (c.C[con_regis] >= con_value) Do(c);
                c.R++;
                break;
            case Xiaoyu:
                if (c.C[con_regis] < con_value) Do(c);
                c.R++;
                break;
            case Xiaoyudengyu:
                if (c.C[con_regis] <= con_value) Do(c);
                c.R++;
                break;
            case Dengyu:
                if (c.C[con_regis] == con_value) Do(c);
                c.R++;
                break;
            case Budengyu:
                if (c.C[con_regis] != con_value) Do(c);
                c.R++;
                break;
            default:
                break;
        }
    }
};

Computer& Computer::Run() {
    R = 0;
    while (R >= 0 && R < Instructions.size()) {
        Instructions[R].WhetherDo(*this);
        for (const auto& i : C) {
            if (i.second > Ans2) {
                Ans2 = i.second;
            }
        }
    }
    return *this;
}

struct ReadInstruction {
    unordered_map<string, Instruction::Condition> ToCd;
    unordered_map<string, Instruction::Operation> ToOp;

    ReadInstruction() {
        ToCd.emplace(">", Instruction::Dayu);
        ToCd.emplace(">=", Instruction::Dayudengyu);
        ToCd.emplace("<", Instruction::Xiaoyu);
        ToCd.emplace("<=", Instruction::Xiaoyudengyu);
        ToCd.emplace("!=", Instruction::Budengyu);
        ToCd.emplace("==", Instruction::Dengyu);
        ToOp.emplace("inc", Instruction::Inc);
        ToOp.emplace("dec", Instruction::Dec);
    }

    Instruction Parser(const string& input) {
        Instruction a;
        sscanf(input.c_str(), "%s %s %d if %s %s %d", Buffer0, Buffer1,
               &a.value, Buffer2, Buffer3, &a.con_value);
        a.regis = Buffer0;
        a.Op = ToOp[Buffer1];
        a.con_regis = Buffer2;
        a.Cd = ToCd[Buffer3];
        return move(a);
    }
};

struct Solution {
    Computer C1;
    int Ans1 = numeric_limits<int>::min();
    void Solve() {
        ReadInstruction read;
        while (scanf("%[^\n]\n", Buffer0) == 1) {
            C1.Instructions.emplace_back(read.Parser(Buffer0));
        }
        C1.Run();
        for (const auto& i : C1.C) {
            if (i.second > Ans1) {
                Ans1 = i.second;
            }
        }
        printf("%d\n", Ans1);
        printf("%d\n", C1.Ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}