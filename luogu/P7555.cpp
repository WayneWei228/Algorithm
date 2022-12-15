#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

struct Solution {
    int N;
    char board[25][25][3];
    int bi, bj;
    bool v[25][25][200020];
    int pow3[11];
    set<int> answer;
    bool test_win(int b) {
        int cells[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cells[i][j] = b % 3;
                b /= 3;
            }
        }
        for (int r = 0; r < 3; r++) {
            if (cells[r][0] == 1 && cells[r][1] == 2 &&
                cells[r][2] == 2)
                return true;
            if (cells[r][0] == 2 && cells[r][1] == 2 &&
                cells[r][2] == 1)
                return true;
        }
        for (int c = 0; c < 3; c++) {
            if (cells[0][c] == 1 && cells[1][c] == 2 &&
                cells[2][c] == 2)
                return true;
            if (cells[0][c] == 2 && cells[1][c] == 2 &&
                cells[2][c] == 1)
                return true;
        }
        if (cells[0][0] == 1 && cells[1][1] == 2 && cells[2][2] == 2)
            return true;
        if (cells[0][0] == 2 && cells[1][1] == 2 && cells[2][2] == 1)
            return true;
        if (cells[2][0] == 1 && cells[1][1] == 2 && cells[0][2] == 2)
            return true;
        if (cells[2][0] == 2 && cells[1][1] == 2 && cells[0][2] == 1)
            return true;
        return false;
    }

    void DFS(int x, int y, int state) {
        if (v[x][y][state]) return;
        v[x][y][state] = true;
        if (board[x][y][0] == 'M' || board[x][y][0] == 'O') {
            int r = board[x][y][1] - '1';
            int c = board[x][y][2] - '1';
            int idx = r * 3 + c;
            int curr_char = (state / pow3[idx]) % 3;
            if (curr_char == 0) {
                int new_char = board[x][y][0] == 'M' ? 1 : 2;
                state += new_char * pow3[idx];
                if (!v[x][y][state] && test_win(state)) {
                    answer.insert(state);
                    return;
                }
            }
        }
        if (board[x + 1][y][0] != '#') DFS(x + 1, y, state);
        if (board[x - 1][y][0] != '#') DFS(x - 1, y, state);
        if (board[x][y + 1][0] != '#') DFS(x, y + 1, state);
        if (board[x][y - 1][0] != '#') DFS(x, y - 1, state);
    }

    void Solve() {
        pow3[0] = 1;
        for (int i = 1; i < 11; i++) {
            pow3[i] = pow3[i - 1] * 3;
        }
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf(" %c%c%c", &board[i][j][0], &board[i][j][1],
                      &board[i][j][2]);
                if (board[i][j][0] == 'B') {
                    bi = i;
                    bj = j;
                }
            }
        }
        DFS(bi, bj, 0);
        cout << answer.size() << endl;
    }
};

int main() {
    auto a = new Solution();
    a->Solve();
    delete a;
    return 0;
}