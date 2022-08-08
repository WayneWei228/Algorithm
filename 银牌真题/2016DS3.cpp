#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 205

int N;
int x[MAXN], y[MAXN], r[MAXN];
int graph[MAXN][MAXN] = {0};

void dfs(int r, bool check[], int &path)
{
    if (check[r])
        return;
    path += 1;
    check[r] = true;
    for (int j = 0; j < N; j++)
    {
        if (graph[r][j])
        {
            dfs(j, check, path);
        }
    }
    return;
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= (r[i] * r[i]))
            {
                graph[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        bool check[MAXN] = {0};
        int path = 0;
        dfs(i, check, path);
        ans = max(ans, path);
    }
    cout << ans << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}