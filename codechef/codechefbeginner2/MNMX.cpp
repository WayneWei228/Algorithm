#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int64;

struct Solution
{
    int N;
    vector<int> A;
    void Solve()
    {
        scanf("%d", &N);
        A.resize(N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        int64 ans = int64(*min_element(A.begin(), A.end())) * (N - 1);
        printf("%lld\n", ans);
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