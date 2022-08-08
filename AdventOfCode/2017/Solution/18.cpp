#include <cctype>
#include <cstdio>
#include <memory>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

typedef long long int64;

struct Memory {
    int64 R[26]{};
    int Ir = 0;

    Memory(int id) { R['p' - 'a'] = id; }
};

struct Port {
    virtual ~Port() = default;
    virtual void Snd(int64 x) = 0;
    virtual void Rcv(int& ir, int64& x) = 0;
};

struct PortA : public Port {
    int64 Last;

    void Snd(int64 x) { Last = x; }
    // -1 终端程序
    void Rcv(int& ir, int64& x) { x == 0 ? ++ir : ir = -1; }
};

struct PortB : public Port {
    queue<int64>*In, *Out;
    int Sent = 0;
    bool NeedData = false;

    void Snd(int64 x) {
        Out->emplace(x);
        ++Sent;
    }

    void Rcv(int& ir, int64& x) {
        NeedData = In->empty();
        if (NeedData) return;
        x = In->front();
        In->pop();
        ++ir;
    }
};

struct Target {
    virtual ~Target() = default;
    virtual int64 Get(const Memory& m) const = 0;
    virtual int64& GetL(Memory& m) const = 0;
};

struct Target0 : public Target {
    int64 X;

    int64 Get(const Memory& m) const { return X; }

    int64& GetL(Memory& m) const {
        static int64 dummy;
        return dummy;
    }
};

struct Target1 : public Target {
    char X;

    int64 Get(const Memory& m) const { return m.R[X - 'a']; }

    int64& GetL(Memory& m) const { return m.R[X - 'a']; }
};

unique_ptr<Target> ParseTarget(const char* input) {
    if (isalpha(input[0])) {
        auto answer = make_unique<Target1>();
        answer->X = input[0];
        return answer;
    }
    auto answer = make_unique<Target0>();
    answer->X = strtol(input, nullptr, 10);
    return answer;
}

struct Instruction {
    enum Operation { Snd, Set, Add, Mul, Mod, Rcv, Jgz } Op;
    unique_ptr<Target> T0, T1;

    // 带 memory 和 题目
    void Run(Memory& m, Port& p) const {
        switch (Op) {
            case Snd:
                p.Snd(T0->Get(m));
                ++m.Ir;
                break;
            case Set:
                T0->GetL(m) = T1->Get(m);
                ++m.Ir;
                break;
            case Add:
                T0->GetL(m) += T1->Get(m);
                ++m.Ir;
                break;
            case Mul:
                T0->GetL(m) *= T1->Get(m);
                ++m.Ir;
                break;
            case Mod:
                T0->GetL(m) %= T1->Get(m);
                ++m.Ir;
                break;
            case Rcv:
                p.Rcv(m.Ir, T0->GetL(m));
                break;
            case Jgz:
                m.Ir += 0 < T0->Get(m) ? T1->Get(m) : 1;
                break;
        }
    }
};

char Buffer0[80], Buffer1[80], Buffer2[80];

struct InstructionParser {
    unordered_map<string, Instruction::Operation> ToOp;

    InstructionParser() {
        ToOp.emplace("snd", Instruction::Snd);
        ToOp.emplace("set", Instruction::Set);
        ToOp.emplace("add", Instruction::Add);
        ToOp.emplace("mul", Instruction::Mul);
        ToOp.emplace("mod", Instruction::Mod);
        ToOp.emplace("rcv", Instruction::Rcv);
        ToOp.emplace("jgz", Instruction::Jgz);
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

struct Program {
    vector<Instruction> Input;

    bool Halt(const Memory& m) const {
        return m.Ir < 0 || Input.size() <= m.Ir;
    }

    void Run(Memory&& m, Port& p) const {
        while (!Halt(m)) Input[m.Ir].Run(m, p);
    }
};

struct Solution {
    InstructionParser Parser;
    Program P;

    int Compute1() {
        PortA pA;
        P.Run(Memory(0), pA);
        return pA.Last;
    }

    int Compute2() {
        queue<int64> q[2];
        Memory m[2]{0, 1};
        PortB b[2];
        b[0].In = b[1].Out = &q[0];
        b[1].In = b[0].Out = &q[1];
        while (true) {
            bool deadLock = true;
            for (int i = 0; i < 2; ++i) {
                if (P.Halt(m[i])) continue;// 两个都中断，两个都跳过，结束
                P.Input[m[i].Ir].Run(m[i], b[i]);
                if (!b[i].NeedData) deadLock = false;
            }
            if (deadLock) break;
        }
        return b[1].Sent;
    }

    void Solve() {
        while (scanf("%[^\n]\n", Buffer0) == 1) {
            P.Input.emplace_back(Parser.Parse(Buffer0));
        }
        printf("%d\n", Compute1());
        printf("%d\n", Compute2());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
