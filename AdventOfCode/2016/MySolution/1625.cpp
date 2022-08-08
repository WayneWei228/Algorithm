#include <cstdio>
using namespace std;

struct Solution {
    void Solve() {
        // int a;
        // scanf("%d", &a);
        // int d = a + 2572;

        int c = 2;
        while (c <= 2572) c = 4 * c + 2;
        printf("%d\n", c - 2572);

        // while (true) {
        //     // 四进制表示全是2
        //     // 11 ～ 13 表示 d的二进制从低位到高位
        //     // 从高位到低位则为 101010..
        //     for (int i = d; i != 0; i /= 2) {
        //         printf("%d\n", i % 2);
        //     }
        // }
    }
};

int main() {
    Solution().Solve();
    return 0;
}