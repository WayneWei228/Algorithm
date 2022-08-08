#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Instruction;

char Buffer[50];

struct Computer {
    int R[6]{};
    int pv = 0;
    int pt;
    vector<Instruction> Instructions;
    void Run();
};

struct Instruction {
    enum OpCode {
        Addr,
        Addi,
        Mulr,
        Muli,
        Banr,
        Bani,
        Borr,
        Bori,
        Setr,
        Seti,
        Gtir,
        Gtri,
        Gtrr,
        Eqir,
        Eqri,
        Eqrr,
    } Op;
    int l, m, r;

    void Run(Computer& c) {
        c.R[c.pt] = c.pv; 
        switch (Op) {
            case Addr:
                c.R[r] = c.R[l] + c.R[m];
                break;
            case Addi:
                c.R[r] = c.R[l] + m;
                break;
            case Mulr:
                c.R[r] = c.R[l] * c.R[m];
                break;
            case Muli:
                c.R[r] = c.R[l] * m;
                break;
            case Banr: 
                c.R[r] = c.R[l] & c.R[m];
                break;
            case Bani:
                c.R[r] = c.R[l] & m;
                break;
            case Borr:
                c.R[r] = c.R[l] | c.R[m];
                break;
            case Bori:
                c.R[r] = c.R[l] | m;
                break;
            case Setr: 
                c.R[r] = c.R[l];
                break;
            case Seti: 
                c.R[r] = l;
                break;
            case Gtir:
                c.R[r] = l > c.R[m];
                break;
            case Gtri:
                c.R[r] = c.R[l] > m;
                break;
            case Gtrr:
                c.R[r] = c.R[l] > c.R[m];
                break;
            case Eqri:
                c.R[r] = c.R[l] == m;
                break;
            case Eqir:
                c.R[r] = l == c.R[m];
                break;
            case Eqrr:
                c.R[r] = c.R[l] == c.R[m];
                break;
        }
        c.pv = c.R[c.pt] + 1;
    }
};

void Computer::Run() {
    while (0 <= pv && pv < int(Instructions.size())) {
        Instructions[pv].Run(*this);
    }
}

struct ReadInstruction {
    Instruction Ins;
    unordered_map<string, Instruction::OpCode> ToOp;

    ReadInstruction() {
        ToOp.emplace("addr", Instruction::Addr);
        ToOp.emplace("addi", Instruction::Addi);
        ToOp.emplace("mulr", Instruction::Mulr);
        ToOp.emplace("muli", Instruction::Muli);
        ToOp.emplace("banr", Instruction::Banr);
        ToOp.emplace("bani", Instruction::Bani);
        ToOp.emplace("borr", Instruction::Borr);
        ToOp.emplace("bori", Instruction::Bori);
        ToOp.emplace("setr", Instruction::Setr);
        ToOp.emplace("seti", Instruction::Seti);
        ToOp.emplace("gtir", Instruction::Gtir);
        ToOp.emplace("gtri", Instruction::Gtri);
        ToOp.emplace("gtrr", Instruction::Gtrr);
        ToOp.emplace("eqir", Instruction::Eqir);
        ToOp.emplace("eqri", Instruction::Eqri);
        ToOp.emplace("eqrr", Instruction::Eqrr);
    }

    Instruction Read(const string& s) {
        Ins.Op = ToOp[s];
        scanf("%d %d %d", &Ins.l, &Ins.m, &Ins.r);
        printf("%s %d %d %d\n", s.c_str(), Ins.l, Ins.m, Ins.r);
        return Ins;
    }
};

struct Solution {
    Computer C;

    void Solve() {
        ReadInstruction r;
        scanf("#ip %d", &C.pt);
        while (true) {
            if (scanf("%s ", Buffer) < 1) break;
            string s = Buffer;
            C.Instructions.emplace_back(r.Read(s));
        }
        C.Run();
        printf("%d\n", C.R[0]);
    }
};

int main() {
    Solution().Solve();
    return 0;
}