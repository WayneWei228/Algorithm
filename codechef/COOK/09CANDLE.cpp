#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*
找出最小个数的数, 再加一个这个数则拼不出来
如果0的和非0的数同为最少, 优先级是非0数
0数最少前面+1
*/
struct Solution {
    vector<int> A;

    void Solve() {
        A.resize(10);
        for (int i = 0; i < 10; i++) {
            scanf("%d", &A[i]);
        }
        int j = min_element(A.begin() + 1, A.end()) - A.begin();
        if (A[0] < A[j]) {
            printf("1");
            j = 0;
        }
        for (int i = 0; i <= A[j]; i++) printf("%d", j);
        printf("\n");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
} 