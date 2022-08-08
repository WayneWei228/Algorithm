#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

char Buffer0[80], Buffer1[80];

struct Box {
    vector<string> S;

    bool operator==(const Box& that) const { return S == that.S; }

    Box(int d = 0) : S(d) {
        for (int i = 0; i < d; ++i) S[i].resize(d);
    }

    Box(const string& input) {
        int position = 0;
        while (true) {
            int nchars = 0;
            sscanf(input.c_str() + position,  //
                   "%[^/]/%n", Buffer0, &nchars);
            S.emplace_back(Buffer0);
            if (nchars == 0) break;
            position += nchars;
        }
    }
};

struct BoxHash {
    size_t operator()(const Box& b) const {
        uint64 answer = 0;
        for (const auto& i : b.S) {
            for (const auto& j : i) answer = Fingerprint(answer + j);
        }
        return answer;
    }
};

struct Solution {
    unordered_map<Box, Box, BoxHash> M;
    vector<string> Seed{".#.", "..#", "###"};

    void CopyTo(const vector<string>& input, vector<string>& output,
                int s0, int s1, int t0, int t1, int size) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                output[t0 + i][t1 + j] = input[s0 + i][s1 + j];
            }
        }
    }

    void EnhanceTo(const Box& p, const Box*& to) {
        auto result = M.find(p);
        if (result != M.end()) to = &result->second;  // 先尖头再&
        // to 指的是更改后Box在map中的地址
    }

    Box& Rotate90(Box& p) {  // 顺时针90度
        Box answer(p.S.size());
        for (int i = 0; i < p.S.size(); ++i) {
            for (int j = 0; j < p.S.size(); ++j) {
                answer.S[j][p.S.size() - 1 - i] = p.S[i][j];
            }
        }
        return p = move(answer);
    }

    Box& Transpose(Box& p) {
        Box answer(p.S.size());
        for (int i = 0; i < p.S.size(); ++i) {
            for (int j = 0; j < p.S.size(); ++j) {
                answer.S[j][i] = p.S[i][j];
            }
        }
        return p = move(answer);
    }

    const Box& EnhanceBlock(Box& p) {
        const Box* answer = nullptr;
        // Box内容不可以改变
        // 指向A不能改A
        // 指向B不能改B
        EnhanceTo(Rotate90(p), answer);
        EnhanceTo(Rotate90(p), answer);
        EnhanceTo(Rotate90(p), answer);
        EnhanceTo(Rotate90(p), answer);
        EnhanceTo(Transpose(p), answer);
        EnhanceTo(Rotate90(p), answer);
        EnhanceTo(Rotate90(p), answer);
        EnhanceTo(Rotate90(p), answer);
        return *answer;
        // *answer 指的是M里面的Box
        // 返回值中Box内容也不能修改， 跟answer统一
    }

    void Enhance() {
        int b = Seed.size() % 2 == 0 ? 2 : 3;  // 2 or 3
        int b1 = b + 1;                        // 变化之后
        int blocks = Seed.size() / b;
        Box Seed1(blocks * b1);  // 变化之后总图
        for (int i = 0; i < blocks; ++i) {
            for (int j = 0; j < blocks; ++j) {
                auto p = Box(b);
                CopyTo(Seed, p.S, i * b, j * b, 0, 0, b);
                auto q = EnhanceBlock(p);// 不能修改
                CopyTo(q.S, Seed1.S, 0, 0, i * b1, j * b1, b1);
            }
        }
        Seed = move(Seed1.S);
    }

    int Count() {
        int answer = 0;
        for (const auto& i : Seed) {
            for (const auto& j : i) {
                if (j == '#') ++answer;
            }
        }
        return answer;
    }

    void Solve() {
        while (scanf("%s => %s", Buffer0, Buffer1) == 2) {
            string s0 = Buffer0, s1 = Buffer1;
            M.emplace(s0, s1);
        }
        for (int i = 0; i < 5; ++i) Enhance();
        printf("%d\n", Count());
        for (int i = 5; i < 18; ++i) Enhance();
        printf("%d\n", Count());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
