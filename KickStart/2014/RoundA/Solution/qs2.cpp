#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

// 二进制得用字符串
const int D[10] = {
    0176, 0060, 0155, 0171, 0063, 0133, 0137, 0160, 0177, 0173,
}; 
// 0177 LED显示8 01111111 
// 0x1 十六进制 1


char Buffer[80];

struct Solution {
    int N;
    vector<int> A;

    void Solve(int caseNo) {
        scanf("%d", &N);
        A.resize(N);
        for (int i = 0; i < N; ++i) {
            scanf("%s", Buffer);
            for (int j = 0; j < 7; ++j) {
                A[i] += (Buffer[j] - '0') << (6 - j);
            }
        }
        printf("Case #%d: ", caseNo);
        ComputePrint();
    }

    void ComputePrint() {
        int orTotal = 0; // 亮过的灯就是好的
        for (int i : A) orTotal |= i; // or 用二进制算
        unordered_set<int> nextState;
        for (int good = 0; good < 128; ++good) { // 2 ^ 7
            if (orTotal & ~good) continue; // 又在ortotal 和 bad里情况不可能
            for (int start = 0; start < 10; ++start) {
                vector<int> B(N);
                int k = start;
                for (int& i : B) {
                    i = D[k--] & good; // 递减循环顺序
                    if (k == -1) k = 9;
                }
                if (A == B) nextState.emplace(D[k] & good);
            }
        }
        if (nextState.size() == 1) {
            int only = *nextState.begin();
            // 0 -> 6   only >> (6 - i)
            for (int i = 6; i >= 0; --i) printf("%d", (only >> i) & 1); // & 1 只取一位
        } else {
            printf("ERROR!");
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}