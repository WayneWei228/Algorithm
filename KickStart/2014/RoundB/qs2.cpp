#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int64;

vector<int> Graph;

struct Solution {
    double total;
    int B, L, N;

    double Pour(int level, int num) {  // l n 给下面每一杯溢出去的酒量
        // 递归分支>=2个都不行，必须记忆化
        // （访问过的点存下来，不再访问）
        if (level < 1 || num < 1) return 0;
        if (level == 1 && num == 1) {
            if (total > 250.0) {
                return (total - 250.0) / 3.0;
            } else {
                return 0;
            }
        }
        // (1 + n) * n / 2
        // sqrt(x * 2)
        // O(sqrt(num)) 枚举
        
        double volume = 0.0;
        int left = num - level, right = num - level + 1;
        int prelevel = level - 1;
        if (left <= Graph[prelevel] && left != 0) {
            volume += Pour(prelevel, left);
        }
        if (right <= Graph[prelevel] && left != 0) {
            volume += Pour(prelevel, right);
        }
        if (num <= Graph[prelevel] && left != 0) {
            volume += Pour(prelevel, num);
        }
        if (volume <= 250.0) {
            return 0;
        } else {
            return (volume - 250.0) / 3.0;
        }
    }

    void Solve(int caseNo) {
        scanf("%d%d%d", &B, &L, &N);
        total = B * 750.0;
        printf("Case #%d: %lf\n", caseNo, Pour(L, N));
    }
};

int main() {
    Graph.resize(401);
    for (int i = 1; i < 402; i++) {
        Graph[i] = Graph[i - 1] + i;
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}