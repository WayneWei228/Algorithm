#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[103];
// x 行 y 列
// 最左上角 (1, 1)
// 最开始向右，逆时针
int DX[4]{0, -1, 0, 1}, DY[4]{1, 0, -1, 0};

struct Coordinate {
    int X, Y;

    bool operator==(const Coordinate& that) const {
        return X == that.X && Y == that.Y;
    }
};

struct Solution {
    int N;
    Coordinate Start, End;
    vector<string> S;

    void Solve(int caseNo) {
        scanf("%d", &N);
        S.resize(N + 2);
        S[0].resize(N + 2, '#');
        for (int i = 1; i <= N; i++) {
            // 从 Buffer[1] 开始读
            scanf("%s", &Buffer[1]);
            Buffer[0] = '#';
            S[i] = Buffer;
            S[i] += '#';
        }
        S.back().resize(N + 2, '#');
        scanf("%d%d%d%d", &Start.X, &Start.Y, &End.X, &End.Y);
        string route;
        int direction;
        // 左上往下看，右上往左看
        if (Start.X == 1) {
            direction = Start.Y == 1 ? 3 : 2;
        } else {
        // 左下往右看，右下往上看
            direction = Start.Y == 1 ? 0 : 1;
        }
        for (int i = 0; i <= 10000; i++) {
            if (Start == End) {
                printf("Case #%d: %d\n%s\n", caseNo, i, route.c_str());
                return;
            }
            for (int j = 0; j < 4; j++) {
                // 从左边看起
                int newD = (direction + 5 - j) % 4;
                Coordinate next{Start.X + DX[newD], Start.Y + DY[newD]};
                if (S[next.X][next.Y] != '#') {
                    Start = next;
                    direction = newD;
                    route += "ENWS"[newD];
                    break;
                }
            }
        }
        printf("Case #%d: Edison ran out of energy.\n", caseNo);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}