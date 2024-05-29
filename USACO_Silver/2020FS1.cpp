#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <iostream>
#define maxn 200000
using namespace std;

int a[maxn], b[maxn], c[maxn];
bool f[maxn]; //代表数是否已经访问过
int main()
{
	// freopen("swap.in", "r", stdin);
	// freopen("swap.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &l, &r);
		reverse(a + l, a + r + 1);
	}

	for (int i = 1; i <= n; i++) b[a[i]] = i;
    cout << 'b';
    for(int i = 1; i <= n; i++) {
        cout << b[i];
    }
	for (int i = 1; i <= n; i++) {
		if (f[i]) continue;
		int p = b[i];
		vector<int> v;  //储存循环节
		v.push_back(i);
		while (p != i) v.push_back(p), p = b[p];
        for(int i = 0; i < v.size(); i++) {
            cout << v[i];
        }
        cout << endl;
		int q = k % (v.size());
		int sz = v.size();
		for (int i = 0; i < sz; i++) {
			f[v[i]] = true;
			c[v[q]] = v[i]; // 重点！ v[i] 跑到 v[q] 的位置
			q++;
			if (q >= sz) q = 0;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d\n", c[i]);
    // fclose(stdin);
    // fclose(stdout);
}




// 待修改
// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <cstring>
// using namespace std;
// /*
// 7 2 2
// 2 5
// 3 7
// */

// int N, M, K;
// vector<int> pos;
// int lf[200001],rt[200001];
// int P[100001];
// bool vis[100001];

// queue<int> q;

// struct more {
//     int space;
//     int arr[10001];
// };
// vector<more> lst;

// void dfs(int node) {
//     vis[node] = true;
//     q.push(node);
//     if(!vis[P[node]]) {
//         dfs(P[node]);
//     }
// }


// int main() {
//     // freopen("swap.in", "r",stdin);
//     // freopen("swap.out","w",stdout);
//     lst.resize(100001);
//     cin >> N >> M >> K;
//     for(int i = 0; i < M; i++) {
//         cin >> lf[i] >> rt[i];
//     }
//     pos.resize(N + 1);
//     for(int i = 1; i <= N; i++) {
//         pos[i] = i;
//     }
//     for(int i = 0; i < M; i++) {
//         reverse(pos.begin() + lf[i], pos.begin() + rt[i] + 1);
//     }

//     for(int i = 1; i <= N; i++) {
//         cout << pos[i];
//     }
//     cout << endl;

//     for(int i = 1; i <= N; i++) {
//         P[pos[i]] = i;
//     }

//     // for(int i = 1; i <= N; i++) {
//     //     cout << P[i];
//     // }
//     // cout << endl;
//     int cycle = 0;

//     for (int i = 1; i <= N; i++)
//     {
//         dfs(i);
//         lst[i].space = q.size();
//         int j = 1;
//         while (!q.empty())
//         {
//             lst[i].arr[j++] = q.front();
//             q.pop();
//         }
//         memset(vis,0, N + 1);
//     }

//     for(int i = 1; i <= N; i++) {
//         int time = K % lst[i].space;
//         if(time == 0) {
//             cout << lst[i].arr[1] << endl;
//         } else
//         {
//             cout << lst[i].arr[time + 1] << endl;
//         }
        
//     }

//     // fclose(stdin);
//     // fclose(stdout);
//     return 0;
// }
