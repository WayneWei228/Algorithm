#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
const int MAXN = 2505;
int n, c[MAXN], t[MAXN], ans;
vector<int> adj[MAXN];

void dfs(int u, int f)
{
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (v == f)
            continue;
        cout << "u " << u << " v " << v << " f " << f << endl;
        //先递归孩子，把孩子调到0

        dfs(v, u);
        //当前点和孩子的差不变，求出当前点的值
        t[u] = (t[u] + 12 - t[v]) % 12;
        //  t[u] = abs(t[u] - t[v]);
    }
}

int main()
{
    // freopen("clocktree.in", "r", stdin);
    // freopen("clocktree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &c[i]);
        c[i] %= 12;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i)
    {
        //先把c数组拷贝到t数组里面，去操作t数组。免得c被改掉了下次循环数不对了。
        memcpy(t, c, sizeof(t));
        printf("*****************\n");
        dfs(i, 0);
        for (int j = 1; j <= n; ++j)
        {
            printf("t[%d]=%d\n", j, t[j]);
        }
        //最后根上剩下0或者1就是可以的
        if (t[i] == 0 || t[i] == 1)
        {

            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}



/*
u 1 v 2 f 0
u 2 v 3 f 1
u 2 v 4 f 1
t[1]=11
t[2]=0
t[3]=11
t[4]=11

void dfs(int u, int f)
{
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (v == f)
            continue;
        cout << "u " << u << " v " << v << " f " << f << endl;
        //先递归孩子，把孩子调到0

        dfs(v, u);
        //当前点和孩子的差不变，求出当前点的值
        t[u] = (t[u] + 12 - t[v]) % 12;
        //  t[u] = abs(t[u] - t[v]);
    }
}
4
11 10 11 11
1 2
2 3
2 4

2 
1 3 4 
2 
2 

1 -> 2 -> 3
     |
     > 4

dfs(1,0)
v = 2
dfs(2,1)                                dfs(2,1)
                                        i = 0 v = 1
                                        
                                        1 == 1
                                        i = 1 v = 3                         
                                        dfs(3, 2)                        dfs(3,2)   
                                        t[2] = (t[2] + 12-t[3]) % 12     v = 2
                                                                         f = 2
                                                                         v == f
                                                                         continue
                                        
                                        
                                        i = 2 v = 4
                                        dfs(4, 2)
                                        t[2] = (t[2] + 12 - t[4]) % 12


t[1] = (t[1] + 12 - t[2]) % 12


*/


