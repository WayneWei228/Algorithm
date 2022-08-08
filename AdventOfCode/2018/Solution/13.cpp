#include <algorithm>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Train {
    int X, Y, Direction, Turn;

    bool operator<(const Train& that) const {
        if (X != that.X) return X < that.X;
        return Y < that.Y;
    }
};

char Buffer[151];

struct Solution {
    set<Train> Trains;
    // 存放Train，自动排序
    vector<string> Board;
    Train FirstBadTrain;

    void Solve() {
        // windows 换行符 \r\n
        while (scanf("%[^\r\n]%*[\r\n]", Buffer) == 1) {
            Board.emplace_back(Buffer);
        }
        ScanTrains();
        FirstBadTrain.X = -1;
        while (GoOK()) void();  // 啥也没用，骗排版的
        printf("%d,%d\n", FirstBadTrain.Y, FirstBadTrain.X);
        printf("%d,%d\n", Trains.begin()->Y, Trains.begin()->X);
    }

    void ScanTrains() {
        for (int i = 0; i < Board.size(); ++i) {
            for (int j = 0; j < Board[i].size(); ++j) {
                switch (Board[i][j]) {
                    case '>':
                        Board[i][j] = '-';
                        Trains.emplace(Train{i, j, 0, 0});
                        break;
                    case '^':
                        Board[i][j] = '|';
                        Trains.emplace(Train{i, j, 1, 0});
                        break;
                    case '<':
                        Board[i][j] = '-';
                        Trains.emplace(Train{i, j, 2, 0});
                        break;
                    case 'v':
                        Board[i][j] = '|';
                        Trains.emplace(Train{i, j, 3, 0});
                        break;
                }
            }
        }
    }

    bool GoOK() {
        set<Train> newTrains;
        while (!Trains.empty()) {
            Train train = *Trains.begin();
            Trains.erase(Trains.begin());
            // 从右方向逆时针
            // 0是右方向
            // 移动
            switch (train.Direction % 4) {
                case 0:
                    ++train.Y;
                    break;
                case 1:
                    --train.X;
                    break;
                case 2:
                    --train.Y;
                    break;
                case 3:
                    ++train.X;
                    break;
            }
            switch (Board[train.X][train.Y]) {
                case '+':
                    switch (train.Turn++ % 3) {
                        case 0:  // 向左转
                            train.Direction += 1;
                            break;
                        case 2:  // 向右转
                            train.Direction += 3;
                            break;
                    }
                    break;
                case '/':
                    // 0 -> 1
                    // 1 -> 0
                    // 2 -> 3
                    // 3 -> 2
                    // 差值为1， 要想来回切换， ^ 1 即可 除 0 外
                    train.Direction ^= 1;
                    break;
                case '\\':
                    // 0 -> 3
                    // 3 -> 0
                    // 1 -> 2
                    // 2 -> 1
                    train.Direction ^= 3;
                    break;
            }
            if (Trains.count(train) ||  // 跟没移动的train发生碰撞
                !newTrains.emplace(train).second) {
                // 跟已移动的train发生碰撞
                if (FirstBadTrain.X == -1) FirstBadTrain = train;
                // 未移动的删去碰撞Train
                // 已移动的删去碰撞Train
                Trains.erase(train);
                newTrains.erase(train);
            }
        }
        Trains = move(newTrains);
        return 1 < Trains.size();
    }
};

int main() {
    Solution().Solve();
    return 0;
}
