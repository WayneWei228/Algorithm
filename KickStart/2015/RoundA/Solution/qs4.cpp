#include <cstdio>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int MaxTurns = 1300000;

struct Coordinate {
    int X, Y;

    bool operator==(const Coordinate& that) const {
        return X == that.X && Y == that.Y;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate& c) const {
        return c.X * size_t(9875321) + c.Y;
    }
};

int DX[4]{0, -1, 0, 1}, DY[4]{1, 0, -1, 0};

struct Board {
    unordered_map<Coordinate, char, CoordinateHash> Data;

    char& Get(const Coordinate& c) {
        char init = (c.X + c.Y) % 2 != 0 ? '*' : '_'; // * is odd, _ is even;
        return Data.emplace(c, init).first->second;
    }
};

struct Solution {
    int S, R, C, Direction;
    string Turn;
    queue<Coordinate> Snake;
    Coordinate Head;
    Board B;
    
    void Solve(int caseNo) {
        Turn.resize(MaxTurns, '_');
        scanf("%d%d%d", &S, &R, &C);
        for (int i = 0; i < S; i++) {
            int time;
            char turnTo;
            scanf("%d %c", &time, &turnTo);
            Turn[time] = turnTo;
        }
        printf("Case #%d: %d\n", caseNo, Simulate());
    }

    int Simulate() {
        Direction = 0;
        Head.X = 0;
        Head.Y = 0;
        B.Get(Head) = 'S';
        Snake.push(Head);
        for (int i = 1; i < MaxTurns; ++i) {
            Head.X = (Head.X + DX[Direction]) % R;
            Head.Y = (Head.Y + DY[Direction]) % C;
            switch (B.Get(Head)) {
                case 'S' : {
                    if (!(Head == Snake.front())) return Snake.size(); // Head 等于 Snake尾巴，继续
                    Snake.pop();
                    Snake.push(Head);
                    break;
                }
                case '*': {
                    B.Get(Head) = 'S';
                    Snake.push(Head);
                    break;
                }
                case '_': {
                    B.Get(Snake.front()) = '_';
                    B.Get(Head) = 'S';
                    Snake.pop();
                    Snake.push(Head);
                    break;
                }
            }
        }
    }
};