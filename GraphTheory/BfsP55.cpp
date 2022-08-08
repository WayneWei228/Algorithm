#include <cstdio>
#include <cstring>
#define NMAX 20
#define SLMAX 200

struct SnakeAndLadder
{
    int from, to;
};

int main() {
    int D;
    int N, S, L;
    int grid[NMAX * NMAX + 1];
    int gridbak[NMAX * NMAX + 1];
    SnakeAndLadder obstacle[2 * SLMAX];
    int i, j, k, m;
    int step;
    int deal;

    scanf("%d", &D);
    for(i = 0; i < D; i++) {
        scanf("%d%d%d", &N, &S, &L);
        for(j = 0; j < S + L; j++) {
            scanf("%d%d", &obstacle[j].from, &obstacle[j].to);
        }
        memset(grid, 0, sizeof(grid));
        grid[1] = 1;
        step = 0;
        while (grid[N * N] == 0) {
            memcpy(gridbak,grid,sizeof(grid));
            memset(grid, 0, sizeof(grid));
            for(j = 1; j <= N * N - 1; j++) {
                if(gridbak[j] == 0) continue;
                for(k = 1; k <= 6; k++) {
                    deal = 0;
                    if(j + k > N * N) break;
                    for(m = 0; m < S + L; m++) {
                        if(obstacle[m].from == j + k) {
                            grid[obstacle[m].to] = 1;
                            deal = 1;
                            break;
                        }
                    }
                    if(deal == 0 && grid[j + k] == 0) grid[j + k] = 1;
                }
            }
            step++;
        }
        printf("%d\n", step);
    }
    return 0;
}



