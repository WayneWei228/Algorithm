#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int64;

struct Computer; // 后面补充


struct Instruction {  // 有四个方法，没有实现
    // 有很多子类，但实现起来不一样
    virtual ~Instruction() = default;
    // 析构：销毁这个类的时候可以做事情，
    // default：什么都不做
    // //带有虚函数的基类必须有虚的析构函数
    virtual unique_ptr<Instruction> Clone() const = 0; 
    // 地址不同，原本属性也不改
    // 不改变自身， =0 是不实现
    // Clone() 复制
    // 返回Instruction的智能指针
    // const 不能调用非const
    virtual void Read() = 0; // 不实现的话 =0 即可，否则需加花括号
    virtual void ExecuteAt(Computer& c) const = 0;
    // this 是Instruction* 类型
    // 带上 const this 就是 const Instruction* 类型
    // a 为 Instruction 中的任意属性
    // a = this->a 的简称
    // 所以 a 也不能改，只读不改
};

struct Computer {
    vector<unique_ptr<Instruction>> Instructions; // 不同子类的Instructions
    vector<int64> R; // 储存状态

    Computer& Reset(int64 a, int64 b) { // 返回自己好用，可一气呵成，可多次调用
        R.resize(3);
        R[0] = a; // 初始化 为 0
        R[1] = b; // 初始化 为 0
        R[2] = 0; // 当前执行到第几条
        return *this;
    }

    Computer& Run() {
        while (0 <= R[2] && R[2] < Instructions.size()) {
            Instructions[R[2]]->ExecuteAt(*this); // 进行操作 核心 
        }
        return *this;
    }
};

char Buffer[80];

struct InstructionHLF : public Instruction {
    int Index;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionHLF>(*this); // 用对象自己制造
        // 用它自己构造自己就为复制
        // 默认有复制构造函数
        // unique_ptr 拥有这个指针
        // 析构时会delete掉
    }

    void Read() { // 读变量 a or b
        scanf("%s", Buffer);
        Index = Buffer[0] - 'a'; // Index 在这初始化 0 or 1
    }

    void ExecuteAt(Computer& c) const { // 34 ～ 52内的数组得到更改
        c.R[Index] /= 2; // 
        ++c.R[2]; // 
    }
};

struct InstructionTPL : public Instruction {
    int Index;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionTPL>(*this);
    }

    void Read() {
        scanf("%s", Buffer);
        Index = Buffer[0] - 'a';
    }

    void ExecuteAt(Computer& c) const {
        c.R[Index] *= 3;
        ++c.R[2];
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
        ++c.R[2];
    }
};

struct InstructionJMP : public Instruction {
    int Offset;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionJMP>(*this);
    }

    void Read() { scanf("%d", &Offset); }
    void ExecuteAt(Computer& c) const { c.R[2] += Offset; }
};

struct InstructionJIE : public Instruction {
    int Index, Offset;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionJIE>(*this);
    }

    void Read() {
        scanf("%[^,], %d", Buffer, &Offset);
        Index = Buffer[0] - 'a';
    }

    void ExecuteAt(Computer& c) const {
        if (c.R[Index] % 2 == 0) {
            c.R[2] += Offset;
        } else {
            ++c.R[2];
        }
    }
};

struct InstructionJIO : public Instruction {
    int Index, Offset;

    unique_ptr<Instruction> Clone() const {
        return make_unique<InstructionJIO>(*this);
    }

    void Read() {
        scanf("%[^,], %d", Buffer, &Offset);
        Index = Buffer[0] - 'a';
    }

    void ExecuteAt(Computer& c) const {
        if (c.R[Index] == 1) {
            c.R[2] += Offset;
        } else {
            ++c.R[2];
        }
    }
};

struct ReadInstruction {
    unordered_map<string, unique_ptr<Instruction>> M; // 把每个指令map到对应样板

    ReadInstruction() {
        M.emplace("hlf", make_unique<InstructionHLF>());
        M.emplace("tpl", make_unique<InstructionTPL>());
        M.emplace("inc", make_unique<InstructionINC>());
        M.emplace("jmp", make_unique<InstructionJMP>());
        M.emplace("jie", make_unique<InstructionJIE>());
        M.emplace("jio", make_unique<InstructionJIO>());
    }

    unique_ptr<Instruction> Read() {
        if (scanf("%s ", Buffer) < 1) return nullptr;
        auto answer = M[Buffer]->Clone();
        answer->Read(); // 多态：运行的时候才知道，编译的时候不知道
        return answer;
    }
};

// void do (const string& input) {
//     string a(input);
// }

struct Solution {
    Computer C;

    void Solve() {
        ReadInstruction readInstruction;
        while (true) {
            auto instruction = readInstruction.Read();
            if (!instruction) break;
            C.Instructions.emplace_back(move(instruction));
        }
        printf("%lld\n", C.Reset(0, 0).Run().R[1]);
        printf("%lld\n", C.Reset(1, 0).Run().R[1]);
    }
};

int main() {
    Solution().Solve();
    return 0;
}