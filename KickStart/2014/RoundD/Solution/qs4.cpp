#include <cstdio>
#include <vector>
using namespace std;

int DX[16]{
    1, 1, 0,  -1, -1, -1, 0, 1,  // 前8正常八联通
    2, 1, -1, -2, -2, -1, 1, 2,  // 后8跳马
};

int DY[16]{
    0, 1, 1, 1, 0,  -1, -1, -1,  //
    1, 2, 2, 1, -1, -2, -2, -1,
};
// 0100 0001
// 2800x0
// 0x82
struct Solution {
    int N, Answer = 0;
    vector<vector<char>> K;

    void Solve(int caseNo) {
        K.resize(8);
        for (auto& i : K) i.resize(8, '_');
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            char x, y, kind;
            scanf(" %c%c-%c", &x, &y, &kind);
            K[x - 'A'][y - '1'] = kind; // K[字母维][数字维]
        }
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                switch (K[i][j]) {
                    case 'K':
                        Attack(i, j, 1, 0xff); // 0x 十六进制 ff 8个1
                        // 从最低位开始的 8 个 1
                        break;
                    case 'Q':
                        Attack(i, j, 8, 0xff);
                        break;
                    case 'R':
                        Attack(i, j, 8, 0x55); // 01010101
                        break;
                    case 'B':
                        Attack(i, j, 8, 0xaa);
                        // a = 10
                        // a = 10101010
                        break;
                    case 'N':
                        Attack(i, j, 1, 0xff00);
                        // 前 8 个 1， 后 8 个 0
                        // 用的时候表示 DX中前8不用， 用后8
                        break;
                    case 'P':
                        Attack(i, j, 1, 0x82);
                        // 字母增，数字加减1
                        break;
                }
            }
        }
        printf("Case #%d: %d\n", caseNo, Answer);
    }

    void Attack(int x, int y, int most, int mask) {
        // x, y, 最多走几步, 哪些方向他能走
        for (int i = 0; i < 16; ++i) {
            if ((mask >> i) & 1) Answer += Go(x, y, i, most);
        }
    }

    int Go(int x, int y, int d, int most) {
        for (int i = 0; i < most; ++i) {
            x += DX[d];
            if (x < 0 || 8 <= x) return 0;
            y += DY[d];
            if (y < 0 || 8 <= y) return 0;
            if (K[x][y] != '_') return 1;
        }
        return 0;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}