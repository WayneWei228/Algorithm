#include <cstdio>
#include <functional>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;

int abv = 100;
struct Memory {
    int64 R[8]{};
    int IR = 0, MulCounter = 0;
};
// 把输入string的方法转移到输入memory, 返回int64的方法
auto LValue(const string& s) -> function<int64&(Memory&)> {
    int index = s[0] - 'a';
    return [index](Memory& m) -> int64& { return m.R[index]; };
}
// 返回 function<int64(const Memory&)>
auto RValue(const string& s) -> function<int64(const Memory&)> {
    if (!isalpha(s[0])) {
        int value = stol(s);
        return [value](const Memory&) { return value; };
    }
    int index = s[0] - 'a';
    return [index](const Memory& m) { return m.R[index]; };
}

char Buffer0[80], Buffer1[80];
// 返回 function<void(Memory&)> 类型
auto ParseInstruction(const string& s) -> function<void(Memory&)> {
    if (sscanf(s.c_str(), "set %s %s", Buffer0, Buffer1) == 2) {
        auto p1 = LValue(Buffer0);
        auto p2 = RValue(Buffer1);
        // 统一输入，导致输入一个 Memory就可以做所有事
        return [=](Memory& m) { p1(m) = p2(m), ++m.IR; };
    }
    if (sscanf(s.c_str(), "sub %s %s", Buffer0, Buffer1) == 2) {
        auto p1 = LValue(Buffer0);
        auto p2 = RValue(Buffer1);
        // 想用p1 p2 复制一份
        return [=](Memory& m) { p1(m) -= p2(m), ++m.IR; };
    }
    if (sscanf(s.c_str(), "jnz %s %s", Buffer0, Buffer1) == 2) {
        auto p1 = RValue(Buffer0);
        auto p2 = RValue(Buffer1);
        return [=](Memory& m) { p1(m) ? m.IR += p2(m) : ++m.IR; };
    }
    if (sscanf(s.c_str(), "mul %s %s", Buffer0, Buffer1) == 2) {
        auto p1 = LValue(Buffer0);
        auto p2 = RValue(Buffer1);
        return [=](Memory& m) {
            p1(m) *= p2(m);
            ++m.IR;
            ++m.MulCounter;
        };
    }
    return nullptr;
}

struct Solution {
    vector<function<void(Memory&)>> Input;

    void Solve() {
        while (scanf("%[^\n]\n", Buffer0) == 1) {
            Input.emplace_back(ParseInstruction(Buffer0));
        }
        Memory m;
        while (0 <= m.IR && m.IR < Input.size()) Input[m.IR](m);
        printf("%d\n", m.MulCounter);
        int answer = 0;
        for (int k = 106500; k <= 123500; k += 17) {
            bool isPrime = true;
            for (int i = 2; i != k; ++i) {
                if (k % i == 0) isPrime = false;
            }
            if (!isPrime) ++answer;
        }
        printf("%d\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
