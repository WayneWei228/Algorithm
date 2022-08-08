//USACO 2020 January Contest, Silver Problem 2. Loan Repayment

/*
 
 Farmer John 欠了 Bessie N 加仑牛奶。他必须在 K 天内将牛奶给 Bessie。但是，他不想将牛奶太早拿出手。另一方面，他不得不在还债上有所进展，所以他必须每天给 Bessie 至少 M 加仑牛奶。
 以下是 Farmer John 决定偿还 Bessie 的方式。首先他选择一个正整数 X。然后他每天都重复以下过程：

 假设 Farmer John 已经给了 Bessie G 加仑，计算 (N−G)/X 向下取整。令这个数为 Y。
 如果 Y 小于 M，令 Y 等于 M。
 给 Bessie Y 加仑牛奶。
 求 X 的最大值，使得 Farmer John 按照上述过程能够在 K 天后给 Bessie 至少 N 加仑牛奶
 
 Binary search on X. For the first subtask, we can check whether the number of gallons of milk that FJ gives is at least N in O(K) time. However, this does not suffice for full points.

 How can we do better than Θ(K)? As the numbers in the statement are up to 10^12, not 10^18, this suggests that some sort of sqrt(N) is involved.
 
 Suppose that we fix X. Then Y decreases over time. It turns out that if we process all transitions that leave Y unchanged in O(1) time, then our solution runs quickly enough! If there are more than sqrt(2N) distinct values of Y then FJ definitely gives Bessie enough mlik because
     1+2+…+sqrt(2N)≥N.
     Thus, we can check whether X works in O(sqrt(N)) time.
     It follows that our solution runs in O(sqrt(N)logN) time.
 
 如果固定X,Y一直在减少；
 保持Y不变
 */
 #include <cstdio>
 #include <iostream>
 #include <cstdlib>
 #include <algorithm>
 #include <vector>
int valid(long long n, long long k, long long m, long long x)
{
  long long g = 0;
  while(k > 0 && g < n) {
    long long y = (n - g) / x;
    if(y < m) {
      long long leftover = (n-g + m-1) / m;
        //if((n-g)%m==0) leftover=(n-g)/m;
        //else leftover=(n-g)/m+1;
      return leftover <= k;
    }
    long long maxmatch = n - x*y;
    long long numdays = (maxmatch - g) / y + 1;
    if(numdays > k) numdays = k;
    g += y * numdays;
    k -= numdays;
  }
  return g >= n;
}
 
int main() {
  freopen("loan.in", "r", stdin);
  freopen("loan.out", "w", stdout);
  long long n, k, m;
  scanf("%lld %lld %lld", &n, &k, &m);
  long long lhs = 1;
  long long rhs = 1e12;
  while(lhs < rhs) {
    long long mid = (lhs + rhs + 1) / 2;
    if(valid(n, k, m, mid)) {
      lhs = mid;
    }
    else {
      rhs = mid - 1;
    }
  }
  printf("%lld\n", lhs);
  //fclo
}
