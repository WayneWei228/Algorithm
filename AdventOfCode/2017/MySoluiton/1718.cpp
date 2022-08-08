#include <cstdio>
#include <deque>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[80], Buffer1[80], Buffer2[80];
typedef long long int int64;

struct Instruction;

struct Program {
    vector<Instruction> P;
    int64 R[26]{};
    int64 fre;
    int no = 0;
    int64 Run1();
};

struct Programs {
    Program p[2];
    queue<int64> q[2];
    int64 Run2();
};

struct Target {
    virtual ~Target() = default;
    virtual int64 Get(const Program& p) const = 0;
    virtual void Set(Program& p, int64 v) const = 0;
    virtual unique_ptr<Target> Clone() const = 0;
};

struct Target0 : public Target {
    int64 value;
    int64 Get(const Program& p) const { return value; };
    void Set(Program& p, int64 v) const {};
    unique_ptr<Target> Clone() const {
        return make_unique<Target0>(*this);
    }
};

struct Target1 : public Target {
    char value;
    int64 Get(const Program& p) const { return p.R[value - 'a']; };
    void Set(Program& p, int64 v) const { p.R[value - 'a'] = v; }
    unique_ptr<Target> Clone() const {
        return make_unique<Target1>(*this);
    }
};

struct Instruction {
    enum Operation { Set, Add, Mul, Mod, Snd, Jgz, Rcv } Op;
    unique_ptr<Target> left, right;

    // 一个构造函数 接受const 自己& 则为复制构造函数
    // 复制构造函数被很多stl所使用
    // 系统函数：库里的函数 eg: emplace_back
    // vector 存东西时 需复制一份，则会调用复制构造函数
    // 会不会调用还不一定，但必须确保所写的复制构造函数正确

    // Instruction(const Instruction& input) {
    //     Op = input.Op;
    //     left = input.left->Clone();
    //     if (right) {
    //          right = input.right->Clone();
    //     }
    // }

    Instruction Clone() const {
        Instruction a;
        a.Op = Op;
        a.left = left->Clone();
        if (right) {
            a.right = right->Clone();  // 空指针不能解引用 意思为：
                                       // 前不能放* 后不能放->
        }
        return a;
    }

    Instruction() = default;

    void Run(Program& c) const {
        switch (Op) {
            case Snd:
                c.fre = left->Get(c);
                c.no++;
                break;
            case Set:
                left->Set(c, right->Get(c));
                c.no++;
                break;
            case Add:
                left->Set(c, right->Get(c) + left->Get(c));
                c.no++;
                break;
            case Mul:
                left->Set(c, right->Get(c) * left->Get(c));
                c.no++;
                break;
            case Mod:
                left->Set(c, left->Get(c) % right->Get(c));
                c.no++;
                break;
            case Rcv:
                if (left->Get(c) != 0) {
                    left->Set(c, c.fre);
                }
                c.no++;
                break;
            case Jgz:
                if (left->Get(c) > 0) {
                    c.no += right->Get(c);
                } else {
                    c.no++;
                }
                break;
            default:
                break;
        }
    }

    int64 Run_SND(Program& c) {
        c.no++;
        return left->Get(c);
    }

    void Run_Rcv(Program& c, int value) {
        left->Set(c, value);
        c.no++;
        return;
    }
};

int64 Program::Run1() {
    int64 ans1 = 0;
    while (0 <= no && no < P.size()) {
        if (P[no].Op == Instruction::Rcv) {
            ans1 = fre;
            break;
        }
        P[no].Run(*this);
    }
    return ans1;
}

int64 Programs::Run2() {
    int64 ans = 0;
    p[0].R['p' - 'a'] = 0;
    p[1].R['p' - 'a'] = 1;

    bool waiting0 = false, waiting1 = false;
    while ((!waiting0 || !waiting1) && 0 <= p[0].no &&
           p[0].no < p[0].P.size() && 0 <= p[1].no &&
           p[1].no < p[1].P.size()) {
        bool done0 = false, done1 = false;
        if (p[0].P[p[0].no].Op == Instruction::Snd) {
            int64 v = p[0].P[p[0].no].Run_SND(p[0]);
            q[1].emplace(v);
            waiting1 = false;
            done0 = true;
        }
        if (p[1].P[p[1].no].Op == Instruction::Snd) {
            ans++;
            int64 v = p[1].P[p[1].no].Run_SND(p[1]);
            q[0].emplace(v);
            waiting0 = false;
            done1 = true;
        }
        if (p[0].P[p[0].no].Op == Instruction::Rcv && !done0) {
            if (!q[0].empty()) {
                auto front = q[0].front();
                q[0].pop();
                p[0].P[p[0].no].Run_Rcv(p[0], front);
            } else {
                waiting0 = true;
            }
            done0 = true;
        }
        if (p[1].P[p[1].no].Op == Instruction::Rcv && !done1) {
            if (!q[1].empty()) {
                auto front = q[1].front();
                q[1].pop();
                p[1].P[p[1].no].Run_Rcv(p[1], front);
            } else {
                waiting1 = true;
            }
            done1 = true;
        }
        if (!done0) {
            p[0].P[p[0].no].Run(p[0]);
        }
        if (!done1) {
            p[1].P[p[1].no].Run(p[1]);
        }
    }
    return ans;
}

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

    unique_ptr<Target> Parsed(const char* input) {
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
        if (res > 1) ans.left = Parsed(Buffer1);
        printf("hello4");
        if (res > 2) ans.right = Parsed(Buffer2);
        return ans;
    }
};

struct Solution {
    Program p;
    Programs ps;

    void Solve() {
        InstructionParser read;
        while (scanf("%[^\n]\n", Buffer) == 1) {
            string s = Buffer;
            p.P.emplace_back(read.Read(s));
            // ps.p[0].P.emplace_back(read.Read(s));
            // ps.p[1].P.emplace_back(read.Read(s));
        }
        for (const auto& i : p.P) {
            ps.p[0].P.emplace_back(i.Clone());
            ps.p[1].P.emplace_back(i.Clone());
        }
        // for (auto i : p.P) {
        //     printf("%d ", i.Op);
        // }
        // printf("\n");
        // for (auto i : ps.p[0].P) {
        //     printf("%d ", i.Op);
        // }
        // printf("\n");

        // printf("%lld\n", p.Run1());
        printf("%lld\n", ps.Run2());
    }
};

int main() {
    Solution().Solve();
    return 0;
}