#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

int DX[4] {-1, 0, 1, 0}, DY[4] {0, 1, 0, -1};

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) { 
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Coordinate {

    int x, y;

    bool operator==(const Coordinate& that) const {
        return x == that.x && y == that.y;
    }
};

struct CoordinateHash {

    size_t operator()(const Coordinate& c) const { 
        return Fingerprint(c.x) + c.y;
    }
};

typedef unordered_set<Coordinate, CoordinateHash> CoordinateSet;


struct Snake {
    int dir;
    Coordinate Head;
    queue<Coordinate> body;
    CoordinateSet S;
};

struct Solution {
    int S, R, C;
    vector<vector<bool>> Board;
    unordered_map<int, int> Change;
    CoordinateSet HaveEat;
    Snake snake;
    void Solve(int caseNo) {
        scanf("%d%d%d", &S, &R, &C);
        snake.Head = Coordinate{0, 0};
        snake.dir = 1;
        for (int i = 0; i < S; i++) {
            int t;
            char d;
            int dir;
            scanf("%d %c", &t, &d);
            dir = (d == 'L') ? -1 : 1;
            Change.emplace(t, dir);
        }
        for (int i = 1; i <= 1300000; i++) {
            if (!Move()) break;
            ChangeDir(i);
        }
        printf("Case #%d: %d\n", caseNo, int(snake.body.size() + 1));
    }

    bool Move() {
        Coordinate newHead = Coordinate{snake.Head.x + DX[snake.dir], snake.Head.y + DY[snake.dir]};
        if (newHead.x < 0) newHead.x = R - 1;
        if (newHead.x >= R) newHead.x = 0;
        if (newHead.y < 0) newHead.y = C - 1;
        if (newHead.y >= C) newHead.y = 0;
        if (snake.S.count(newHead)) {
            snake.body.emplace(snake.Head);
            snake.body.pop();
            snake.Head = newHead;
            return false;
        }
        snake.body.emplace(snake.Head);
        snake.S.emplace(snake.Head);
        snake.Head = newHead;
        if ((newHead.x + newHead.y) % 2 == 0 || HaveEat.count(newHead)) {
            auto tail = snake.body.front();
            snake.body.pop();
            snake.S.erase(tail);
        } else {
            HaveEat.emplace(newHead);
        }
        return true;
    }

    void ChangeDir(int t) {
        if (!Change.count(t)) return;
        snake.dir += Change[t];
        if (snake.dir > 3) snake.dir = 0;
        if (snake.dir < 0) snake.dir = 3;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}