#include <cstdio>
#include <vector>
#include <string>
using namespace std;


struct Solution
{
    int N;
    vector<int> A,B;

    void Solve()
    {
        int ans = 0;
        scanf("%d", &N);
        A.resize(N);
        B.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d",&A[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d",&B[i]);
        }
        for (int i = N-1; i >= 0; i--) {
            A[i] -= A[i-1];
            if (A[i]>=B[i]) ans++;
        }
        printf("%d\n", ans);
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        Solution().Solve();
    return 0;
}