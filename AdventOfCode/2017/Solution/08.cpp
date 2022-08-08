#include <cstdio>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer0[80], Buffer1[80], Buffer2[80], Buffer3[80];

struct Instruction {
    enum Operator { L, LE, G, GE, E, NE } Op;
    string Register, Condition;
    int Delta, ConditionValue;

    static unordered_map<string, Operator> ToOp() {
        unordered_map<string, Operator> answer;
        answer.emplace("<", L);
        answer.emplace("<=", LE);
        answer.emplace(">", G);
        answer.emplace(">=", GE);
        answer.emplace("==", E);
        answer.emplace("!=", NE);
        return answer;
    }

    Instruction& Parse(const string& input) {
        sscanf(input.c_str(), "%s %s %d if %s %s %d",  //
               Buffer0, Buffer1, &Delta,               //
               Buffer2, Buffer3, &ConditionValue);
        Register = Buffer0;
        if (string(Buffer1) == "dec") Delta = -Delta;
        Condition = Buffer2;
        static unordered_map<string, Operator> toOp = ToOp();
        Op = toOp[Buffer3];
        return *this;
    }

    bool Pass(int x) const {
        switch (Op) {
            case L:
                return x < ConditionValue;
            case LE:
                return x <= ConditionValue;
            case G:
                return x > ConditionValue;
            case GE:
                return x >= ConditionValue;
            case E:
                return x == ConditionValue;
            case NE:
                return x != ConditionValue;
        }
        return false;
    }
};

struct CPU {
    unordered_map<string, int> Memory;
    vector<Instruction> Instructions;

    int Run() {
        int answer = 0;
        for (const auto& i : Instructions) {
            if (i.Pass(Memory[i.Condition])) {
                int x = Memory[i.Register] += i.Delta;
                if (answer < x) answer = x;
            }
        }
        return answer;
    }
};

struct Solution {
    CPU c;

    void Solve() {
        while (scanf("%[^\n]\n", Buffer0) == 1) {
            c.Instructions.emplace_back(Instruction().Parse(Buffer0));
        }
        int answer2 = c.Run();
        int answer1 = numeric_limits<int>::min();
        for (const auto& i : c.Memory) {
            if (answer1 < i.second) answer1 = i.second;
        }
        printf("%d\n%d\n", answer1, answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}