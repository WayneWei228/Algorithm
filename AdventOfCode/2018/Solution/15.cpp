#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <limits>
#include <string>
#include <vector>
using namespace std;

struct Block {
    char C; // 当前所在字符
    int HitPoint, RoundToMove; // 生命值 轮数
};

char Buffer[80];

int DX[4]{-1, 0, 0, 1}, DY[4]{0, -1, 1, 0};

const int MaxHitPoint = 200, AttackPowerG = 3;

struct Coordinate {
    int X, Y;

    bool operator<(const Coordinate& that) const {
        if (X != that.X) return X < that.X;
        return Y < that.Y;
    }
};

struct Battle {
    int AttackPowerE; // 攻击力
    vector<vector<Block>> Board; // 地图

    void Read() {
        while (scanf("%s", Buffer) == 1) {
            string s = Buffer;
            Board.emplace_back(s.size());
            // 加一行vector<Block> 长度为 s.size()
            for (int i = 0; i < s.size(); ++i) {
                // 最后一行的第i个元素初始化
                Board.back()[i] = Block{s[i], MaxHitPoint, 0};
            }
        }
    }

    int Solve() {
        int round = 0;
        while (GoOK(round)) ++round;
        printf("%d %d\n", round, SumOfHitPoints());
        return round * SumOfHitPoints();
    }

    bool GoOK(int round) {
        for (int i = 0; i < Board.size(); ++i) {
            for (int j = 0; j < Board[i].size(); ++j) {
                if (!Human(Board[i][j])) continue;
                if (Board[i][j].RoundToMove != round) continue;
                ++Board[i][j].RoundToMove;
                if (NoEnemy(Board[i][j].C)) return false;
                // 终止就不加round
                MoveAndAttack(Coordinate{i, j});
            }
        }
        return true;
    }

    void MoveAndAttack(Coordinate s) {
        Coordinate t;
        // 四周有人吗
        if (!FindTargetOK(Board[s.X][s.Y].C, s, t)) { // 没有
            Move(s); // 那走走看！
            // 还没人，算了😮‍💨
            if (!FindTargetOK(Board[s.X][s.Y].C, s, t)) return;
        }
        // 诶有人！
        // 打！
        Board[t.X][t.Y].HitPoint -=
            Board[s.X][s.Y].C == 'G' ? AttackPowerG : AttackPowerE;
        // 打死咯，拜拜👋
        if (Board[t.X][t.Y].HitPoint <= 0) Board[t.X][t.Y].C = '.';
    }

    // 给char，检测 s0 四周有没有敌人，有的话传血量最少，reading order 最早的传给 t
    bool FindTargetOK(char c0, const Coordinate& s0, Coordinate& t) {
        int minHitPoint = numeric_limits<int>::max();
        // 四周看看👀
        for (int i = 0; i < 4; ++i) {
            Coordinate s1{s0.X + DX[i], s0.Y + DY[i]};
            Block& b1 = Board[s1.X][s1.Y];
            if (c0 == 'G' && b1.C != 'E') continue;
            if (c0 == 'E' && b1.C != 'G') continue;
            // 发现血更少的敌人，目标暂定他！
            if (b1.HitPoint < minHitPoint) {
                minHitPoint = b1.HitPoint;
                t = move(s1);
            }
        }
        // 没敌人，锁定为空，返回false，有敌人，锁定为他，返回true
        return minHitPoint != numeric_limits<int>::max();
    }

    // 出发点，待更新的 t， 查找方法
    bool FindNearOK(const Coordinate& s, Coordinate& t,
                    function<bool(const Coordinate&)> finish) {
        vector<vector<bool>> visited(Board.size());
        for (int i = 0; i < visited.size(); ++i) {
            visited[i].resize(Board[i].size());
        }
        vector<Coordinate> nodes{s};
        while (!nodes.empty()) {
            // 每一层
            // nodesNew 里的所有node 都跟出发点有相同距离
            vector<Coordinate> nodesNew, finished;
            for (auto& node : nodes) {
                for (int i = 0; i < 4; ++i) {
                    int nextX = node.X + DX[i];
                    int nextY = node.Y + DY[i];
                    if (!visited[nextX][nextY] &&
                        Board[nextX][nextY].C == '.') {
                        visited[nextX][nextY] = true;
                        // 该node之后的可走路径
                        nodesNew.emplace_back(Coordinate{nextX, nextY});
                    }
                }
                // 如果该node符合finish条件，完成，加入完成列表
                if (finish(node)) finished.emplace_back(move(node));
            }
            // BFS碰到就是最近，移动再取Reading Order最小，返回true
            if (!finished.empty()) {
                // t 就是目的元素
                t = *min_element(finished.begin(), finished.end());
                return true;
            }
            nodes = move(nodesNew);
        }
        return false;
    }

    // 有敌人是 false
    bool NoEnemy(char c) {
        for (int i = 0; i < Board.size(); ++i) {
            for (int j = 0; j < Board[i].size(); ++j) {
                if (Board[i][j].C == 'G' && c == 'E') return false;
                if (Board[i][j].C == 'E' && c == 'G') return false;
            }
        }
        return true;
    }

    void Move(Coordinate& s) {
        // 取当前位置 Block
        Block& b = Board[s.X][s.Y];
        Coordinate t;
        // 出发点，待更新的 t， 查找方法
        bool ok = FindNearOK(s, t, [&](const Coordinate& s0) {
            Coordinate t0;
            // 返回是否找到，找到的话 t 还被更新为目的点
            return FindTargetOK(b.C, s0, t0);
        });
        if (!ok) return;
        // t 传入， t 被进行修改，finish为 s 周围的点
        FindNearOK(t, t, [&](const Coordinate& s0) {
            // 返回在原点 s 四周找到点
            return abs(s0.X - s.X) + abs(s0.Y - s.Y) == 1;
        });
        // t 现在成为移动后的位置
        Board[t.X][t.Y] = Board[s.X][s.Y];
        b.C = '.';
        s = t;
        // 更新到 s 
    }

    int SumOfHitPoints() {
        int answer = 0;
        for (int i = 0; i < Board.size(); ++i) {
            for (int j = 0; j < Board[i].size(); ++j) {
                if (Human(Board[i][j])) answer += Board[i][j].HitPoint;
            }
        }
        return answer;
    }

    // 判断是不是 Human
    bool Human(const Block& b) { return b.C == 'G' || b.C == 'E'; }

    int CountE() {
        int answer = 0;
        for (int i = 0; i < Board.size(); ++i) {
            for (int j = 0; j < Board[i].size(); ++j) {
                if (Board[i][j].C == 'E') ++answer;
            }
        }
        return answer;
    }
};

struct Solution {
    Battle B{3};
    // 攻击力为3
    int CountE;

    void Solve() {
        B.Read();
        CountE = B.CountE();
        int attack = 4, outcome;
        while (!PerfectWin(attack, outcome)) ++attack;
        printf("%d\n", attack);
        printf("%d\n", B.Solve());
        printf("%d\n", outcome);
    }

    bool PerfectWin(int attack, int& outcome) {
        Battle b(B);
        b.AttackPowerE = attack;
        outcome = b.Solve();
        for (int i = 0; i < b.Board.size(); i++) {
            for (int j = 0; j < b.Board[i].size(); j++) {
                printf("%c", b.Board[i][j].C);
            }
            printf("\n");
        } 
        return b.CountE() == CountE;
    }
};

int main() {
    Solution().Solve();
    return 0;
}
