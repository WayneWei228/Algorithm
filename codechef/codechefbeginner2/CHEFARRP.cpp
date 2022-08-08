#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Solution
{
    int N;
    vector<int> A;
    void Solve()
    {
        int cnt = 0;
        scanf("%d", &N);
        A.resize(N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; i++)
        {
            int sum = 0, product = 1;
            for (int j = i; j < N; j++)
            {
                sum += A[j];
                product *= A[j];
                if (sum == product)
                    cnt++;
            }
        }
        printf("%d\n", cnt);
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