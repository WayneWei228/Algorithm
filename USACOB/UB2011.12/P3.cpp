#include <cstdio>
#include <vector>
using namespace std;

// done
// 想加没有进位

int DigitSum(int x) {
    int answer = 0;
    while (x != 0) {
        answer += x % 10;
        x /= 10;
    }
    return answer;
}

// 1 + 9 = 10
// 10 ！= 1
// 每一次进位都会导致减少
// 如果没有进位的话，两数的DigitSum之和就等于两数之和的DigitSum

bool Carry(int a, int b) {
    return DigitSum(a) + DigitSum(b) != DigitSum(a + b); // 不相等 就是 有carry
}

struct Solution {
    int N, Answer = 0;
    vector<int> A;

    void Solve() {
        scanf("%d", &N);
        A.resize(N);
        for (int& i : A) scanf("%d", &i);
        Search(0, 0, 0);
        printf("%d\n", Answer);
    }

    void Search(int no, int size, int sum) {
        if (Answer < size) Answer = size;
        if (no == N) return;
        Search(no + 1, size, sum); // 不选
        // 只有选的时候要判断有没有carry
        if (!Carry(sum, A[no])) Search(no + 1, size + 1, sum + A[no]); // 选
    }
};

int main() {
    Solution().Solve();
    return 0;
}
