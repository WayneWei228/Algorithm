#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
/*
6 3
0000000000
0000000300
0054000300
1054502230
2211122220
1111111223
*/

int N, K;
char arr[105][11];
bool vis[105][11];
int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
bool flag;

void dfs(int i, int j, int &path, char value) {
    if(vis[i][j]) return;
    vis[i][j] = true;
    for(int x = 0; x < 4; x++) {
        int r = i + dir[x][0];
        int c = j + dir[x][1];
        if(r >= 0 && r <= N && j >= 0 && j <= 10 && !vis[r][c] && arr[r][c] == value) {
            path++;
            dfs(r, c, path, value);
        }
    }
    return;
}

void fall() {
    for(int j = 1; j <= 10; j++) {
        int i = N;
        for(int r = N; r >= 1; r--) {
            if(arr[r][j] != '0') {
                arr[i][j] = arr[r][j];
                i--;
            }
        }
        while (i != 0) {
            arr[i][j] = '0';
            i--;
        }
    }
}
int main() {
    freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 10; j++) {
            cin >> arr[i][j];
            // cout << arr[i][j];
        }
        // cout << endl;
    }
    flag = false;
    do {
    flag = false;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 10; j++) {
            if(arr[i][j] != '0') {
                int path = 1;
                memset(vis, 0, sizeof(vis));
                dfs(i, j, path, arr[i][j]);
                // cout << path << endl;
                if(path >= K) {
                flag = true;
                    for(int a = 1; a <= N; a++) {
                        for(int b = 1; b <= 10; b++) {
                            if(vis[a][b]) {
                                arr[a][b] = '0';
                            }
                        }
                    }
                }
            }
        }
    }
    fall();
    } while (flag);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j<= 10; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}




