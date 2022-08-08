#include <cstdio>
#include <functional>
#include <limits>
#include <vector>
using namespace std;

typedef long long int64;

/*
1 2 3 4

4个 prefix sum vector
1 3 6 10
2 5 9
3 7
4
N * (N + 1) / 2 个数

global Range() -> global prefix sum  -> global Rank() -> local Rank() -> local Select()
                                  BSearch             Sum             BSearch

global pr
efix sum -> local prefix sum

given global index
global Select(index)
l = 3 r = 6
3 -> 5 global Select(3) to get 5

6 -> 9 
F(6) - F(3)

sum of f(6) - f(3) 
6 -> 4 (value map to index)
3 -> 1 

g(4) - g(1) (1 4 10 16)



put together and find the kth smallest number

Select: find the kth largest number in an ordered vector
Rank: given a number and find the rank of the number in the vector
从小到大以0起始
Select and Rank are inverse operation

Select -> Rank:
given N as the number we want to search
we will use lower_bound to find the rank of N (find the position of
first number which is not less that N)

Rank -> Select:
the result of Select must be int64
use int64 as our scale
k : index (下标为k)
Select(k) = x;
find the smallest x which makes Rank(x) >= k; (caution )
1 3 5 7
Select(2) = 5

Rank(3) = 1
Rank(4) = 2
Rank(5) = 2
Rank(6) = 3

1 3 5 5 7
Select(2) = 5
Select(3) = 5

Rank(3) = 1
Rank(4) = 2
Rank(5) = 2
Rank(6) = 4
Rank(7) = 4

method: find the largest x to make Rank(x) <= k 
Select(Rank(x)) <= Select(k)
x <= Select(k)

有效仅限于x出现在数组中
Rank(x) = x的下标
Select(x) = x的下标的数 也就是 x


method: find the largest x to make x <= Select(k)
-> find x = Select(k)

Prove:
(Rank(x) <= k) == (x <= Select(k))

在左成立情况下假设右不成立： 如果 x 大于 Select(k)
矛盾 ： line 59 invalid because there are k + 1 [0 ~ k] number smaller than x
所以推出右边

在右成立情况下假设左不成立： (k + 1) number < x
x > Select(k) 
所以推出左边

*/

int64 BSearch(int64 lower, int64 upper, function<bool(int64)> f) {
    while (lower < upper) {
        int64 mid = lower + (upper - lower) / 2;
        f(mid) ? upper = mid : lower = mid + 1;
    }
    return lower;
}

struct Solution {
    int N, Q;
    int64 L, R;
    vector<int> A; // prefix sum
    vector<int64> S; // prefix sum of prefix sum

    void Solve(int caseNo) {
        scanf("%d%d", &N, &Q);
        A.resize(N + 1);
        S.resize(N + 2);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &A[i]);
            A[i] += A[i - 1];
            S[i + 1] = S[i] + A[i];
        }
        printf("Case #%d:\n", caseNo);
        for (int i = 0; i < Q; ++i) {
            scanf("%lld%lld", &L, &R);
            printf("%lld\n", Query(R) - Query(L - 1));
        }
    }
    // 0 ~ r 的 prefixsum
    int64 Query(int64 r) {
        int64 b = // r 号 元素的值 最长的那数组W[r]
            -1 + BSearch(1, numeric_limits<int64>::max(),
                         [&](int64 x) { return r <= TotalLess(x); });
        return (r - TotalLess(b)) * b + TotalSum(b);
    }

    // 每一行中 小于x的数的个数的总和
    int64 TotalLess(int64 x) {
        int64 answer = 0;
        for (int i = 1; i <= N; ++i) answer += LessIndex(x, i) - i;
        return answer;
    }

    // 每一行中 小于x的数的总和的总和
    int64 TotalSum(int64 x) {
        int64 answer = 0;
        for (int i = 1; i <= N; ++i) {
            answer += S[LessIndex(x, i)] - S[i];
            answer -= (int64)A[i - 1] * (LessIndex(x, i) - i);
        }
        return answer;
    }

    // 下标为i的数开始的prefixsum数组
    // 在第i行中求Rank(x)
    int64 LessIndex(int64 x, int64 i) {
        return BSearch(i, N + 1, [&](int64 index) {
            return x <= A[index] - A[i - 1];
        });
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}