#include <cstdio>
using namespace std;

struct Solution {
    int N;

// 0 1 2 3 
// k 0
// m 4 

// 0 1 2 3 4 

// 2 3 4 0
// ^
// |
// 0 1 2 3

// k = (k + 2) % m;

// k 2
// m 5

    int F(int m, int k) {
        // 递推
        // k 当前的答案
        // m 当前解决的问题是几个人的问题

        while (true) {
            // 如果当前解决的是N个人的问题，就把k return回去
            if (m++ == N) return k;
            
            k = (k + 2) % m;
        }
    }

    // k 当前的答案
    // m 当前解决的问题是几个人的问题

// 0 1 2 3 4 5 6 7 

// 0 1 2 3 4 5 6 7 8

// die 4
// 
// 1 2 3 /5 6 7 8 /0
// 0 1 2 /3 4 5 6 /7


    int G(int m, int k) {
        while (true) {
            if (m++ == N) return k;
            int die = m / 2;
            if (k < die - 1) {
                ++k;
            } else if (k < m - 2) {
                k += 2;
            } else {
                k = 0;
            }
        }
    }

    void Solve() {
        scanf("%d", &N);
        printf("%d\n", F(1, 0) + 1);
        printf("%d\n", G(1, 0) + 1);
    }
};

int main() {
    Solution().Solve();
    return 0;
}