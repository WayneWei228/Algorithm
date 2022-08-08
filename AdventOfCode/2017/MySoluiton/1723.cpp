#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int int64;

char Buffer[80], Buffer1[80], Buffer2[80];

struct Instruction;

struct Computer {
    vector<Instruction> V;
    int64 R[8]{};
    int no = 0;
    int64 Run();
    int64 Run2();
};

struct Target {
    virtual ~Target() = default;
    virtual int64 Get(const Computer& c) const = 0;
    virtual void Set(Computer& c, int64 value) const = 0;
};

struct Target0 : public Target {
    int value;
    int64 Get(const Computer& c) const { return value; }
    void Set(Computer& c, int64 v) const {};
};

struct Target1 : public Target {
    char value;
    int64 Get(const Computer& c) const { return c.R[value - 'a']; }
    void Set(Computer& c, int64 v) const {
        c.R[value - 'a'] = v;
    }
};

struct Instruction {
    enum Operation { Set, Sub, Mul, Jnz } Op;
    unique_ptr<Target> left, right;

    void Run(Computer& c) const {
        switch (Op) {
            case Set:
                left->Set(c, right->Get(c));
                c.no++;
                break;
            case Sub:
                left->Set(c, left->Get(c) - right->Get(c));
                c.no++;
                break;
            case Mul:
                left->Set(c, left->Get(c) * right->Get(c));
                c.no++;
                break;
            case Jnz:
                if (left->Get(c) != 0) {
                    c.no += right->Get(c);
                } else {
                    c.no++;
                }
                break;
            default:
                break;
        }
    }
};

struct ReadInstruction {
    unordered_map<string, Instruction::Operation> ToOp;

    ReadInstruction() {
        ToOp.emplace("set", Instruction::Set);
        ToOp.emplace("mul", Instruction::Mul);
        ToOp.emplace("jnz", Instruction::Jnz);
        ToOp.emplace("sub", Instruction::Sub);
    }

    unique_ptr<Target> Read(const char* input) {
        if (isalpha(input[0])) {
            auto ans = make_unique<Target1>();
            ans->value = input[0];
            return ans;
        }
        auto ans = make_unique<Target0>();
        ans->value = strtol(input, nullptr, 10);
        return ans;
    }

    Instruction Read(const string& input) {
        Instruction ans;
        int res =
            sscanf(input.c_str(), "%s%s%s", Buffer, Buffer1, Buffer2);
        ans.Op = ToOp[Buffer];
        if (res > 1) ans.left = Read(Buffer1);
        if (res > 2) ans.right = Read(Buffer2);
        return ans;
    }
};

int64 Computer::Run() {
    int64 ans1 = 0;
    printf("size %d\n", int(V.size()));
    while (0 <= no && no < int(V.size())) {
        // printf("%d\n", no);
        if (V[no].Op == Instruction::Mul) ans1++;
        V[no].Run(*this);
    }
    return ans1;
}

int64 Computer::Run2() {
    R[0] = 1;
    // printf("size %d\n", int(V.size()));
    while (0 <= no && no < int(V.size())) {
        // printf("%d\n", no);
        V[no].Run(*this);
    }
    return R['h' - 'a'];
}

struct Solution {
    Computer c;
    Computer c2;
    void Solve() {
        ReadInstruction r;
        while (scanf("%[^\n]\n", Buffer) == 1) {
            string s = Buffer;
            // printf("%s\n", s.c_str());
            c.V.emplace_back(r.Read(s));
            c2.V.emplace_back(r.Read(s));
        }
        printf("%lld\n", c.Run());
        printf("%lld\n", c2.Run2());
    }
};

int main() {
    Solution().Solve();
    return 0;
}