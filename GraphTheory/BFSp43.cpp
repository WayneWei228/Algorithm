#include <cstdio>
#include <cstring>
#include <queue>
#define MAXMN 200
#define INF 1000000
using namespace std;

struct point
{
    int x,y;
    int step;
    int time;
};

queue<point> Q;
int N, M;
char map[MAXMN][MAXMN];

int mintime[MAXMN][MAXMN];
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int ax, ay;

int BFS(point s) {
    int i;
    Q.push(s);
    point hd;
    while(!Q.empty()) {
        hd = Q.front();
        Q.pop();
        for(i = 0; i < 4; i++) {
            int x = hd.x + dir[i][0];
            int y = hd.y + dir[i][1];
            if(x >= 0 && x <= N - 1 && y >= 0 && y <= M - 1 && map[x][y] != '#') {
                point t;
                t.x = x;
                t.y = y;
                t.step = hd.step + 1;
                t.time = hd.time + 1;
                if(map[x][y] == 'x') {
                    t.time += 1;
                }
                if(t.time < mintime[x][y]) {
                    mintime[x][y] = t.time;
                    Q.push(t);
                }
            }
        }
    }
    return mintime[ax][ay];
}

int main()
{
    int i, j;
    while (scanf("%d%d", &N, &M) != EOF)
    {
        memset(map, 0, sizeof(map));
        for (int i = 0; i < N; i++)
        {
            scanf("%s", map[i]);
        }
        int sx, sy;
        point start;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                mintime[i][j] = INF;
                if (map[i][j] == 'a')
                {
                    ax = i;
                    ay = j;
                }
                else if (map[i][j] == 'r')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        start.x = sx;
        start.y = sy;
        start.step = 0;
        start.time = 0;
        mintime[sx][sy] = 0;
        int mint = BFS(start);
        if (mint < INF)
        {
            printf("%d\n", mint);
        }
        else
        {
            printf("Poor ANGLE has to stay in the prison all his life.\n");
        }
    }
    return 0;
}
