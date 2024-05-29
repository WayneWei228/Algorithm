//USACO 2019 February Contest, Silver Problem 2. Painting the Barn
/*
 若想在点(x1,y1)到点(x2,y2)围成的矩形的每个位置增加1
 则需要进行以下操作:
 vis[x1 + 1][y1 + 1]++;
 vis[x2 + 1][y2 + 1]++;
 vis[x1 + 1][y2 + 1]--;
 vis[x2 + 1][y1 + 1]--;
 设vis[i][j]:原点到点(i,j)围成的矩形的总和
 */

//sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
//sum[i+1][j+1]=a[i+1][j+1]+sum[i][j+1]+sum[i+1][j]-sum[i][j]
/*#include <iostream>
#include <cstring>

using namespace std;

int n, k;
int vis[1005][1005];

int main() {
    cin >> n >> k;
    int x1, y1, x2, y2;
    for(int i = 1; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        vis[x1 + 1][y1 + 1]++;
        vis[x2 + 1][y2 + 1]++;
        vis[x1 + 1][y2 + 1]--;
        vis[x2 + 1][y1 + 1]--;
    }
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            vis[i][j] += vis[i - 1][j] + vis[i][j - 1] - vis[i - 1][j - 1];
            if(vis[i][j] == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}*/
/*
 If we have a two-dimension array g and then define f(i,j) to be the sum of all g(k,l) where k≤i and l≤j, then we can define f(i,j)=g(i,j)+f(i−1,j)+f(i,j−1)−f(i−1,j−1), and after computing the two-dimension prefix sums, we can iterate over all elements to compute the desired area.
 */
/*
 一维前缀和
 S[i] = a[1] + a[2] + ... a[i]
 a[l] + ... + a[r] = S[r] - S[l - 1]
 二维前缀和
 S[i, j] = 第i行j列格子左上部分所有元素的和
 以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：

 S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]
 一维差分
 给区间[l, r]中的每个数加上c：
 差分的思想很简单，我们要在一个区间[l,r]内都加上一个数a，那么像树状数组去区间更新一样，我们弄一个差分数组,在dif[l]处+a，在dif[r+1]处-a,这样像前缀和一样扫过l到r这个区间时，在l处开始有+a，+a对[l,r]区间产生影响，在r+1处-a变回原来的值，对r+1后面的区间没有了影响

 B[l] += c, B[r + 1] -= c
 二维差分
 给以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵中的所有元素加上c：

 S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c

 */
/*#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1001][1001];

int main() {
  freopen("paintbarn.in", "r", stdin);
  freopen("paintbarn.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  while(n--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    dp[a][b]++;
    dp[a][d]--;
    dp[c][b]--;
    dp[c][d]++;
  }
  int ret = 0;
  for(int i = 0; i < 1000; i++) {
    for(int j = 0; j < 1000; j++) {
      if(i) dp[i][j] += dp[i-1][j];
      if(j) dp[i][j] += dp[i][j-1];
      if(i && j) dp[i][j] -= dp[i-1][j-1];
      if(dp[i][j] == k) ret++;
    }
  }
  cout << ret << endl;
}*/

//
/*
 We can do better though - there's no reason that prefix sums only have to work in one dimension! If we have a two-dimension array g and then define f(i,j) to be the sum of all g(k,l) where k≤i and l≤j, then we can define f(i,j)=g(i,j)+f(i−1,j)+f(i,j−1)−f(i−1,j−1), and after computing the two-dimension prefix sums, we can iterate over all elements to compute the desired area.
 */


// #include <bits/stdc++.h>
// #include <iostream>
// #include <fstream>
// #include <set>
// #include <map>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int dp[1001][1001];

// int main() {
// //   freopen("paintbarn.in", "r", stdin);
// //   freopen("paintbarn.out", "w", stdout);
//   int n, k;
//   cin >> n >> k;
//   while(n--) {
//     int a, b, c, d;
//     cin >> a >> b >> c >> d;
//     dp[a][d]--;
//     dp[a][b]++;
//     dp[c][d]++;
//     dp[c][b]--;
//   }
//   for(int i = 0; i < 10; i++) {
//       for(int j = 0; j < 10; j++) {
//           cout << dp[i][j] << ' ';
//       }
//       cout << endl;
//   }
//   int ret = 0;
//   for(int i = 0; i < 1000; i++) {
//     for(int j = 0; j < 1000; j++) {
//       if(i) dp[i][j] += dp[i-1][j];
//       if(j) dp[i][j] += dp[i][j-1];
//       if(i && j) dp[i][j] -= dp[i-1][j-1];
//       if(dp[i][j] == k) ret++;
//     }
//   }
//   cout << ret << endl;
// }


/*
3 2
1 1 5 5
4 4 7 6
3 3 8 7
0 0 0 0 0 0 0 0 0 0 
0 0 -1 0 0 1 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 -1 0 0 1 0 0 
0 0 0 0 0 -1 1 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 1 0 0 -1 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 1 -1 0 0 0 
0 0 0 0 1 0 0 -1 0 0 
0
*/
#include <iostream>
#include <cstring>

using namespace std;

int n, k;
int vis[1005][1005];

int main() {
    cin >> n >> k;
    int x1, y1, x2, y2;
    for(int i = 1; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        vis[x1][y1]++;
        vis[x2][y2]++;
        vis[x1][y2]--;
        vis[x2][y1]--;
        // vis[x1 + 1][y1 + 1]++;
        // vis[x2 + 1][y2 + 1]++;
        // vis[x1 + 1][y2 + 1]--;
        // vis[x2 + 1][y1 + 1]--;
    }
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            vis[i][j] += vis[i - 1][j] + vis[i][j - 1] - vis[i - 1][j - 1];
            if(vis[i][j] == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}