#include <cstdio>
#include <vector>
using namespace std;

char a[1005][1005];
int b[1005][1005];
int s[100005];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
/*
5 6 3
******
*..*.*
******
*....*
******
2 2
2 5
4 3

*/
void DFS(int x, int y, int k) {
    if (a[x][y] == '*') {
        s[k]++;
        return;
    }
    b[x][y] = k;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (b[nx][ny] == 0) {
            DFS(nx, ny, k);
        }
    }
    return;
}

int main() {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= K; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (!b[x][y]) {
            DFS(x, y, i);
        }
        printf("%d\n", s[b[x][y]]);
    }
}