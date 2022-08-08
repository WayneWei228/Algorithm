#include <cstdio>
using namespace std;

typedef long long int64;

const int Mod = 1000000007;

// 容斥原理
// 求 (a ^ b) % c 的快速算法 快速幂
// 底数一平方，指数变一半
// 底数乘底数，指数减一
int64 Power(int64 a, int64 b) {
    int64 answer = 1;
    while (b != 0) { // b & 1
        if (b % 2 != 0) answer = answer * a % Mod;
        b /= 2; // b >> 1
        a = a * a % Mod;
    }
    return answer;
}

// 5 ^ 5 - (4^5) * C(5, 4) + (3^5) * C(5, 3) - (2^5) * C(5, 2) + (1^5) * C(5, 1)
// motivation: 
// b * b-1 

/*
    a! / b!(a - b)!
  = a * (a - 1) * (a - 2) * ... * (a - b) * ... / b! * (a - b) * (a - b - 1) * (a - b - 2) * ...
  = a * (a - 1) * ... (a - b + 1) (一共 b 个) / b!
  = a * (a - 1) * ... (a + 1 - b) (一共 b 个) / b!
  = (a + 1 - 1) * (a + 1 - 2) * (a + 1 - 3) * ... * (a + 1 - b) / b!
  = (a + 1 - n) (n = (1, b)) / b!
*/

// {a * (a - 1) * (a - 2) * ... (一共 b 个)} / b!
// / b! = * (b!)-1 (b!数论倒数)
// 两个数互质，并不代表这两个数是质数

/*
a * a ^ (p - 2) = a^(p - 1) = 1 (mod p)
数 a ，mod p (且p为质数)，他的数论倒数为 a ^ (p - 2)
找a1 数论倒数
a = 14 p = 7 a = 0
0 没有数论倒数
*/
int64 Choose(int64 a, int64 b) {
    int64 a0 = 1, a1 = 1; // a0 分子， a1 分母
    for (int i = 1; i <= b; ++i) {
        a0 = a0 * (a + 1 - i) % Mod;
        a1 = a1 * i % Mod;
    }
    return a0 * Power(a1, Mod - 2) % Mod;
}

struct Solution {
    int M, N;

    void Solve(int caseNo) {
        scanf("%d%d", &M, &N);
        int64 answer = 0, d = 1;
        for (int i = M; i > 0; --i) {
            int64 delta = Power(i, N) * Choose(M, i);
            answer = (answer + d * delta) % Mod;
            d = -d;
        }
        printf("Case #%d: %lld\n", caseNo, (answer + Mod) % Mod); // 防止负数
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}