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
    virtual unique_ptr<Instruction> Change() const = 0;
};

struct Computer {
    vector<unique_ptr<Instruction>> Instructions;
    vector<int64> R;

    Computer(const Computer& input) {
        R = input.R;
        for (const auto& i : input.Instructions) {
            Instructions.emplace_back(i->Clone());
        }
    }

    Computer() = default;

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

struct InstructionINC : public Instruction {
    int Index;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionINC>(*this);
    }

    unique_ptr<Instruction> Change() const;

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

    unique_ptr<Instruction> Change() const;

    void Read() {
        scanf("%s", Buffer);
        Index = Buffer[0] - 'a';
    }

    void ExecuteAt(Computer& c) const {
        --c.R[Index];
        ++c.R[4];
    }
};

struct InstructionCPY : public Instruction {
    string first, second;
    bool isRegisterL = true, isRegisterR = true;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionCPY>(*this);
    }

    void Read() {
        scanf("%s %s", Buffer, Buffer1);
        first = Buffer, second = Buffer1;
        if (isdigit(first[0]) || first.length() != 1)
            isRegisterL = false;
        if (isdigit(second[0]) || second.length() != 1)
            isRegisterR = false;
    }

    void ExecuteAt(Computer& c) const {
        int leftValue, rightValue;
        if (!isRegisterR) {
            ++c.R[4];
            return;
        }

        if (isRegisterL) {
            leftValue = c.R[first[0] - 'a'];
        }
        if (!isRegisterL) {
            leftValue = stoll(first);
        }
        if (isRegisterR) {
            rightValue = second[0] - 'a';
        }

        c.R[rightValue] = leftValue;
        ++c.R[4];
        return;
    }

    unique_ptr<Instruction> Change() const;
};

struct InstructionJNZ : public Instruction {
    string first, second;
    bool isRegisterL = true, isRegisterR = true;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionJNZ>(*this);
    }

    void Read() {
        scanf("%s %s", Buffer, Buffer1);
        first = Buffer, second = Buffer1;
        if (isdigit(first[0]) || first.length() != 1)
            isRegisterL = false;
        if (isdigit(second[0]) || second.length() != 1)
            isRegisterR = false;
    }

    void ExecuteAt(Computer& c) const {
        int leftValue, rightValue;

        if (isRegisterL) {
            leftValue = c.R[first[0] - 'a'];
        }
        if (!isRegisterL) {
            leftValue = stoll(first);
        }
        if (isRegisterR) {
            rightValue = c.R[second[0] - 'a'];
        }
        if (!isRegisterR) {
            rightValue = stoll(second);
        }
        if (leftValue != 0) {
            c.R[4] += rightValue;
        } else {
            ++c.R[4];
        }
    }
    unique_ptr<Instruction> Change() const;
};

struct InstructionADD : public Instruction {
    string first, second;
    bool isRegisterL = true, isRegisterR = true;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionADD>(*this);
    }

    void Read() {
        scanf("%s %s", Buffer, Buffer1);
        first = Buffer, second = Buffer1;
        if (isdigit(first[0]) || first.length() != 1)
            isRegisterL = false;
        if (isdigit(second[0]) || second.length() != 1)
            isRegisterR = false;
    }

    void ExecuteAt(Computer& c) const {
        int leftValue, rightValue;
        if (!isRegisterR) {
            ++c.R[4];
            return;
        }

        if (isRegisterL) {
            leftValue = c.R[first[0] - 'a'];
        }
        if (!isRegisterL) {
            leftValue = stoll(first);
        }
        if (isRegisterR) {
            rightValue = second[0] - 'a';
        }

        c.R[rightValue] += leftValue;
        ++c.R[4];
        return;
    }

    unique_ptr<Instruction> Change() const { return nullptr; }
};

struct InstructionMUL : public Instruction {
    string first, second;
    bool isRegisterL = true, isRegisterR = true;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionMUL>(*this);
    }

    void Read() {
        scanf("%s %s", Buffer, Buffer1);
        first = Buffer, second = Buffer1;
        if (isdigit(first[0]) || first.length() != 1)
            isRegisterL = false;
        if (isdigit(second[0]) || second.length() != 1)
            isRegisterR = false;
    }

    void ExecuteAt(Computer& c) const {
        int leftValue, rightValue;
        if (!isRegisterR) {
            ++c.R[4];
            return;
        }

        if (isRegisterL) {
            leftValue = c.R[first[0] - 'a'];
        }
        if (!isRegisterL) {
            leftValue = stoll(first);
        }
        if (isRegisterR) {
            rightValue = second[0] - 'a';
        }

        c.R[rightValue] *= leftValue;
        ++c.R[4];
        return;
    }

    unique_ptr<Instruction> Change() const { return nullptr; }
};

struct InstructionTGL : public Instruction {
    int Index;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionTGL>(*this);
    }

    void Read() {
        scanf(" %s", Buffer);
        Index = Buffer[0] - 'a';
    }

    void ExecuteAt(Computer& c) const {
        int pos = c.R[4] + c.R[Index];
        // cout << "pos " << pos << endl;
        ++c.R[4];
        if (pos >= c.Instructions.size()) {
            return;
        }
        c.Instructions[pos] = c.Instructions[pos]->Change();
    }

    unique_ptr<Instruction> Change() const;
};

unique_ptr<Instruction> InstructionCPY::Change() const {
    auto a = make_unique<InstructionJNZ>();
    a->first = first;
    a->second = second;
    a->isRegisterL = isRegisterL;
    a->isRegisterR = isRegisterR;
    return a;
}

unique_ptr<Instruction> InstructionJNZ::Change() const {
    auto a = make_unique<InstructionCPY>();
    a->first = first;
    a->second = second;
    a->isRegisterL = isRegisterL;
    a->isRegisterR = isRegisterR;
    return a;
}

unique_ptr<Instruction> InstructionINC::Change() const {
    auto a = make_unique<InstructionDEC>();
    // 用auto，不能写死为父类类型，
    // 返回时才转化为父类
    a->Index = Index;
    return a;
}

unique_ptr<Instruction> InstructionDEC::Change() const {
    auto a = make_unique<InstructionINC>();
    a->Index = Index;
    return a;
}

unique_ptr<Instruction> InstructionTGL::Change() const {
    auto a = make_unique<InstructionINC>();
    a->Index = Index;
    return a;
}

struct ReadInstruction {
    unordered_map<string, unique_ptr<Instruction>> M;

    ReadInstruction() {
        M.emplace("cpy", make_unique<InstructionCPY>());
        M.emplace("inc", make_unique<InstructionINC>());
        M.emplace("dec", make_unique<InstructionDEC>());
        M.emplace("jnz", make_unique<InstructionJNZ>());
        M.emplace("tgl", make_unique<InstructionTGL>());
        M.emplace("add", make_unique<InstructionADD>());
        M.emplace("mul", make_unique<InstructionMUL>());
    }

    unique_ptr<Instruction> Read() {  // 返回父类
        if (scanf("%s ", Buffer) < 1) return nullptr;
        auto answer = M[Buffer]->Clone();
        answer->Read();
        return answer;
    }
};

struct Solution {
    void Solve() {
        Computer C1;

        ReadInstruction readInstruction;
        while (true) {
            auto instruction = readInstruction.Read();
            if (!instruction) break;
            C1.Instructions.emplace_back(move(instruction));
        }
        Computer C2(C1);
        printf("%lld\n", C1.Reset(7, 0, 0, 0).Run().R[0]);
        printf("%lld\n", C2.Reset(12, 0, 0, 0).Run().R[0]);
    }
};

int main() {
    Solution().Solve();
    return 0;
}