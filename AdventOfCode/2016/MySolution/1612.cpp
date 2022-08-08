#include <cctype>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int64;

struct Computer;

struct Instruction {
    virtual ~Instruction() = default;
    virtual unique_ptr<Instruction> Clone() const = 0;
    virtual void Read() = 0;
    virtual void ExecuteAt(Computer& c) const = 0;
};

struct Computer {
    vector<unique_ptr<Instruction>> Instructions;
    vector<int64> R;
    Computer& Reset(int64 a, int64 b, int64 c, int64 d) {
        R.resize(5);
        R[0] = a;
        R[1] = b;
        R[2] = c;
        R[3] = d;
        R[4] = 0;
        return *this;
    }

    Computer& Run() {
        while (0 <= R[4] && R[4] < Instructions.size()) {
            Instructions[R[4]]->ExecuteAt(*this);
            // printf("%lld\n", R[4]);
            // if (R[1] > -1) {
            //     cout << R[0] << " " << R[1] << " " << R[2] << " "
            //          << R[3] << " " << R[4] << endl;
            // }
        }
        return *this;
    }
};

char Buffer[80], Buffer1[80];

// cpy 41 a
struct InstructionCPY : public Instruction {
    int Index;
    string s;
    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionCPY>(*this);
    }

    void Read() {
        scanf("%s %s", Buffer, Buffer1);
        Index = Buffer1[0] - 'a';
        s = Buffer;
    }

    void ExecuteAt(Computer& c) const {
        if (isdigit(s[0])) {
            c.R[Index] = stoll(s);
        } else {
            c.R[Index] = c.R[s[0] - 'a'];
        }
        ++c.R[4];
    }
};

struct InstructionINC : public Instruction {
    int Index;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionINC>(*this);
    }

    void Read() {
        scanf("%s", Buffer);
        Index = Buffer[0] - 'a';
    }

    void ExecuteAt(Computer& c) const {
        ++c.R[Index];
        ++c.R[4];
    }
};

struct InstructionDEC : public Instruction {
    int Index;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionDEC>(*this);
    }

    void Read() {
        scanf("%s", Buffer);
        Index = Buffer[0] - 'a';
    }

    void ExecuteAt(Computer& c) const {
        --c.R[Index];
        ++c.R[4];
    }
};

struct InstructionJNZ : public Instruction {
    int Offset;
    int Index;
    bool isregister;
    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionJNZ>(*this);
    }

    void Read() {
        scanf("%s %d", Buffer, &Offset);
        string s = Buffer;
        if (isdigit(Buffer[0])) {
            Index = stoll(s);
            isregister = false;
        } else {
            Index = Buffer[0] - 'a';
            isregister = true;
        }
    }

    void ExecuteAt(Computer& c) const {
        if (isregister && c.R[Index] != 0 ||
            !isregister && Index != 0) {
            c.R[4] += Offset;
        } else {
            ++c.R[4];
        }
    }
};

struct ReadInstruction {
    unordered_map<string, unique_ptr<Instruction>> M;

    ReadInstruction() {
        M.emplace("cpy", make_unique<InstructionCPY>());
        M.emplace("inc", make_unique<InstructionINC>());
        M.emplace("dec", make_unique<InstructionDEC>());
        M.emplace("jnz", make_unique<InstructionJNZ>());
    }

    unique_ptr<Instruction> Read() {
        if (scanf("%s ", Buffer) < 1) return nullptr;
        auto answer = M[Buffer]->Clone();
        answer->Read();
        return answer;
    }
};

struct Solution {
    Computer C;

    void Solve() {
        ReadInstruction readInstruction;
        while (true) {
            auto instruction = readInstruction.Read();
            if (!instruction) break;
            C.Instructions.emplace_back(move(instruction));
        }
        printf("%lld\n", C.Reset(0, 0, 0, 0).Run().R[0]);
        printf("%lld\n", C.Reset(0, 0, 1, 0).Run().R[0]);
    }
};

int main() {
    Solution().Solve();
    return 0;
}