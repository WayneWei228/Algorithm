#include <cctype>
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Instruction;

struct Computer {
    vector<Instruction> Instructions;
    int R[26]{}, C = 0;

    int Run(int a);
};

struct Target {
    virtual ~Target() = default;
    virtual int Get(const Computer& c) const = 0;
    virtual void Set(Computer& c, int value) const = 0;
};

struct Target0 : public Target {
    int X;
    int Get(const Computer& c) const { return X; }
    void Set(Computer& c, int value) const {}
};

struct Target1 : public Target {
    char X;
    int Get(const Computer& c) const { return c.R[X - 'a']; }
    void Set(Computer& c, int value) const { c.R[X - 'a'] = value; }
};

struct Instruction {
    enum Operation { Cpy, Inc, Dec, Jnz, Tgl, Mul } Op;
    unique_ptr<Target> T0, T1;

    void Toggle() {
        switch (Op) {
            case Cpy:
                Op = Jnz;
                break;
            case Jnz:
                Op = Cpy;
                break;
            case Inc:
                Op = Dec;
                break;
            case Dec:
            case Tgl:
                Op = Inc;
                break;
            default:
                break;
        }
    }

    void Run(Computer& c) const {
        switch (Op) {
            case Cpy:
                T1->Set(c, T0->Get(c));
                ++c.C;
                break;
            case Inc:
                T0->Set(c, T0->Get(c) + 1);
                ++c.C;
                break;
            case Dec:
                T0->Set(c, T0->Get(c) - 1);
                ++c.C;
                break;
            case Jnz:
                if (T0->Get(c) == 0) {
                    ++c.C;
                } else {
                    c.C += T1->Get(c);
                }
                break;
            case Tgl:
                c.Instructions[c.C + T0->Get(c)].Toggle();
                ++c.C;
                break;
            case Mul:
                T1->Set(c, T0->Get(c) * T1->Get(c));
                ++c.C;
                break;
        }
    }
};

int Computer::Run(int a) {
    R[0] = a;
    while (0 <= C && C < Instructions.size()) {
        Instructions[C].Run(*this);
    }
    return R[0];
}

char Buffer0[80], Buffer1[80], Buffer2[80];

struct InstructionParser {
    unordered_map<string, Instruction::Operation> ToOp;

    InstructionParser() {
        ToOp.emplace("cpy", Instruction::Cpy);
        ToOp.emplace("inc", Instruction::Inc);
        ToOp.emplace("dec", Instruction::Dec);
        ToOp.emplace("jnz", Instruction::Jnz);
        ToOp.emplace("tgl", Instruction::Tgl);
        ToOp.emplace("mul", Instruction::Mul);
    }

    unique_ptr<Target> ParseTarget(const char* input) const {
        if (isalpha(input[0])) {
            // 不能 unique_ptr<Target1> answer;
            // answer 为空指针
            auto answer = make_unique<Target1>();
            answer->X = input[0];
            return answer;
        }
        auto answer = make_unique<Target0>();
        answer->X = strtol(input, nullptr, 10);
        return answer;
    }

    Instruction Parse(const string& input) const {
        int result =
            sscanf(input.c_str(), "%s%s%s", Buffer0, Buffer1, Buffer2);
        Instruction answer;
        answer.Op = ToOp.at(Buffer0);
        if (1 < result) answer.T0 = ParseTarget(Buffer1);
        if (2 < result) answer.T1 = ParseTarget(Buffer2);
        return answer;
    }
};

struct Solution {
    Computer C1, C2;
    InstructionParser Parser;

    void Solve() {
        while (scanf("%[^\n]\n", Buffer0) == 1) {
            string s = Buffer0;
            C1.Instructions.emplace_back(Parser.Parse(s));
            C2.Instructions.emplace_back(Parser.Parse(s));
        }
        printf("%d\n", C1.Run(7));
        printf("%d\n", C2.Run(12));
    }
};

int main() {
    Solution().Solve();
    return 0;
}