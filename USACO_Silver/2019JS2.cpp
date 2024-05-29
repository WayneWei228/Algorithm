#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
char grid[1005][1005];
bool vis[1005][1005];
int dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};

void dfs(int x, int y, int &area, int &perimeter) {
    if(vis[x][y]) return;
    vis[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int r = x + dir[i][0];
        int c = y + dir[i][1];
        if(grid[r][c] == '.') {
            perimeter += 1;
        }
        if(r >= 1 && r <= N && c >= 1 && c <= N && grid[r][c] == '#' && !vis[r][c]) {
            area += 1;
            dfs(r, c, area, perimeter);
        }
    }
    return;
}



int main() {
    freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
    cin >> N;
    memset(grid, '.', sizeof(grid));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> grid[i][j];
            // cout << grid[i][j];
        }
        // cout << endl;
    }
    int maxarea = 0;
    int maxperimeter = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(grid[i][j] == '#' && !vis[i][j]) {
                int area = 1;
                int perimeter = 0;
                dfs(i, j, area, perimeter);
                // cout << perimeter << endl;
                if(maxarea < area) {
                    maxarea = area;
                    maxperimeter = perimeter;
                } 
                else if (maxarea == area) {
                    maxperimeter = min(maxperimeter, perimeter);
                }
            }
        }
    }
    cout << maxarea << ' ' << maxperimeter << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

