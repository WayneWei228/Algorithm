#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    vector<int> A;
    A.resize(10e6 + 5, 0);
    for (int i = 1; i <= 5; i++) {
        A[i] = 1;
    }
    for (int i = 6; i < A.size(); i++) {
        int remainder = i % 5;
        int num = i / 5;
        A[i] = num + ((remainder == 0) ? 0 : 1);
    }
    for (int i = 1; i <= t; i++) {
        int N;
        scanf("%d", &N);
        printf("Case #%d: %d\n", i, A[N]);
    }
    return 0;
}