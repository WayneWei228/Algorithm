#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N;
    vector<int> V;
    bool head = true;
    void Solve(int caseNo) {
        scanf("%d", &N);
        V.resize(100005);
        printf("Case #%d:", caseNo);
        for (int i = 0; i < N; i++) {
            int b;
            scanf("%d", &b);
            for (int j = 1; j <= b; j++) {
                V[j]++;
            }
            int H;
            for (int k = 1; k < V.size(); k++) {
                if (V[k] >= k) {
                    H = k;
                }
                if (!V[k]) break;
            }
            printf(" %d", H);
        }
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}