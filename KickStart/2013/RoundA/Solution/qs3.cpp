#include <cstdio>
using namespace std;

typedef unsigned long long uint64;
struct Solution {
    void Solve(int caseNo) {
        int type;
        uint64 n, p, q;

        scanf("%d", &type);
        switch (type) {
            case 1:
                scanf("%llu", &n);
                Select(n, p, q);
                printf("Case #%d: %llu %llu\n", caseNo, p, q);
                break;
            case 2:
                scanf("%llu%llu", &p, &q);
                Rank(n, p, q);
                printf("Case #%d: %llu\n", caseNo, n);
                break;
        }
    }
    void Select(uint64 n, uint64& p, uint64& q) {
        if (n == 1) {
            p = q = 1;
            return;
        }
        // 找到父亲的 p q
        Select(n / 2, p, q);
        // 如果该节点在左侧
        if (n % 2 == 0) {
            // 右边加等于左边
            q += p;
        } else {
            // 在右侧, 左边加等于右边
            p += q;
        }
    }
    void Rank(uint64& n, uint64 p, uint64 q) {
        if (p == q) {
            n = 1;
            return;
        }
        // 如果是左节点
        if (p < q) {
            // 找父节点 n
            Rank(n, p, q - p);
            // 子节点 n
            n = n + n;
        } else {
            // 如果是右节点
            Rank(n, p - q, q);
            n = n + n + 1;
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}


