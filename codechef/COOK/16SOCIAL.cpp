#include <cstdio>
#include <vector>
using namespace std;

/*
错位排序 D(N)
N个人排列，每个人不能在自己的位置的排列方式总个数
D(N) = (N - 1)D(N - 1) + (N - 1)D(N - 2)

*证明*
定一人在位置1
另一人在位置k

k 与 1 互换位置
k 有 N - 1 种可能性
剩下的为 D(N - 2)
所以排列数为 (N - 1)D(N - 2)

k 不与 1 互换位置
k 有 N - 1 种可能性
剩下的为 D(N - 1) // 把 1 排除掉

*R回合后回到位置的概率*
环长度 R1 能整除 R 即可

环长度为 R1 的错位排序数量

(N - 1)! / (N - R1)! * D(N - R1)
R1个元素构成一个环, 所以剩余错位排列数为D(N - R1)
环中必有 1 

*/


const int M = 50;

vector<double> F{1, 1}, D{1, 0};

struct  Solution {
    int N, R;
    void Solve() {
        scanf("%d%d", &N, &R);
        double answer = 0.0;
        for (int i = 2; i <= N; i++) {
            if (R % i == 0) answer += F[N - 1] / F[N - i] * D[N - i];
        }
        printf("%.5lf\n", answer / D[N] * N);
    }
};


int main() {
    for (int i = 2; i <= M; i++) {
        F.emplace_back(F[i - 1] * i);
        D.emplace_back((D[i - 1] + D[i - 2]) * (i - 1));
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}