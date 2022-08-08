#include <cstdio>
#include <queue>
#include <string>
#include <vector>
using namespace std;

char Buffer[100];

int Next[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
/*
7#567
6#4##
5#32#
4##1#
3210#
上左右下这个顺序找到的第一个可能还并不一定是reading order最小的
找到后再进行比较才是最稳妥的
*/

struct Coordinate {
    int x, y;
    char letter;
    int Hp = 200;
    int r = 0;
    bool operator<(const Coordinate& that) const {
        if (x != that.x) return x < that.x;
        return y < that.y;
    }
};

struct Solution {
    vector<string> input;
    vector<Coordinate> origin;
    vector<string> map;
    vector<Coordinate> V;
    int round = 0;
    int power = 3;

    void Attack(Coordinate& c) {
        bool canAttack = false;
        char target = c.letter ^ 2;
        // 检测四周有没有敌人
        for (int i = 0; i < 4; i++) {
            int nex = c.x + Next[i][0];
            if (nex < 0 || nex >= map.size()) continue;
            int ney = c.y + Next[i][1];
            if (ney < 0 || ney >= map[0].size()) continue;
            if (map[nex][ney] == target) {
                canAttack = true;
            }
        }
        // 没有返回
        if (!canAttack) return;
        // 有的话在V中找到加入enemies
        vector<Coordinate> enemies;
        for (int i = 0; i < 4; i++) {
            int nex = c.x + Next[i][0];
            if (nex < 0 || nex >= map.size()) continue;
            int ney = c.y + Next[i][1];
            if (ney < 0 || ney >= map[0].size()) continue;
            if (map[nex][ney] == target) {
                for (int j = 0; j < V.size(); j++) {
                    if (V[j].x == nex && V[j].y == ney && V[j].Hp > 0 &&
                        V[j].letter == target && V[j].r != -1) {
                        enemies.emplace_back(V[j]);
                    }
                }
            }
        }
        // 排序
        sort(enemies.begin(), enemies.end(),
             [](const Coordinate& a, const Coordinate& b) {
                 if (a.Hp != b.Hp) return a.Hp < b.Hp;
                 if (a.x != b.x) return a.x < b.x;
                 return a.y < b.y;
             });

        for (int i = 0; i < enemies.size(); i++) {
            printf("%d %d %d %c\n", enemies[i].Hp, enemies[i].x,
                   enemies[i].y, enemies[i].letter);
        }


        Coordinate enemy;
        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i].r != -1) {
                enemy = enemies[i];
                break;
            }
        }
        if (enemy.letter == 'G') {
            enemy.Hp -= power;
        } else {
            enemy.Hp -= 3;
        }
        for (int i = 0; i < int(V.size()); i++) {
            if (V[i].x == enemy.x && V[i].y == enemy.y &&
                V[i].r != -1) {
                V[i] = move(enemy);
                if (V[i].Hp <= 0) {
                    map[V[i].x][V[i].y] = '.';
                    V[i].r = -1;
                    return;
                }
            }
        }
        return;
    }

    Coordinate Back(const Coordinate& c,
                    const vector<vector<int>>& visited) {
        if (visited[c.x][c.y] == 1) {
            return Coordinate{c.x, c.y, c.letter, c.Hp, c.r};
        }
        for (int i = 0; i < 4; i++) {
            int nex = c.x + Next[i][0];
            if (nex < 0 || nex >= visited.size()) continue;
            int ney = c.y + Next[i][1];
            if (ney < 0 || ney >= visited[0].size()) continue;
            if (visited[nex][ney] == visited[c.x][c.y] - 1) {
                return Back(Coordinate{nex, ney, c.letter, c.Hp, c.r},
                            visited);
            }
        }
        return Coordinate();
    }

    void Move(Coordinate& c) {
        vector<vector<int>> visited;
        char target = c.letter ^ 2;
        for (int i = 0; i < 4; i++) {
            int nex = c.x + Next[i][0];
            if (nex < 0 || nex >= map.size()) continue;
            int ney = c.y + Next[i][1];
            if (ney < 0 || ney >= map[i].size()) continue;
            if (map[nex][ney] == target) {
                return;
            }
        }

        Coordinate desnination = {-1, -1, c.letter, c.Hp, c.r};

        visited.resize(int(map.size()));
        for (auto& i : visited) {
            i.resize(int(map[0].size()), -1);
        }

        queue<Coordinate> q;
        q.emplace(c);
        visited[c.x][c.y] = 0;
        int dis = numeric_limits<int>::max();
        vector<Coordinate> ready;
        while (!q.empty()) {
            auto front = q.front();
            if (visited[front.x][front.y] > dis) {
                break;
            }
            q.pop();
            if (front.letter == target &&
                visited[front.x][front.y] <= dis) {
                dis = visited[front.x][front.y];
                ready.emplace_back(front);
            }
            for (int i = 0; i < 4; i++) {
                int nex = front.x + Next[i][0];
                if (nex < 0 || nex >= visited.size()) continue;
                int ney = front.y + Next[i][1];
                if (ney < 0 || ney >= visited[0].size()) continue;
                if (visited[nex][ney] == -1 &&
                    (map[nex][ney] == '.' || map[nex][ney] == target)) {
                    q.emplace(
                        Coordinate{nex, ney, map[nex][ney], c.Hp, c.r});
                    visited[nex][ney] = visited[front.x][front.y] + 1;
                }
            }
        }
        if (!ready.empty()) {
            desnination = *min_element(ready.begin(), ready.end());
        }
        if (desnination.x == -1) return;
        desnination.letter = c.letter;
        desnination.r = c.r;

        map[c.x][c.y] = '.';
        c = Back(desnination, visited);
        map[c.x][c.y] = c.letter;

        return;
    }

    bool NoEnemy(char c) {
        for (const auto& i : V) {
            if (i.letter == (c ^ 2) && i.r != -1) return false;
        }
        return true;
    }

    bool Action(int r) {
        for (int i = 0; i < int(V.size()); i++) {
            if (V[i].r != r) continue;
            ++V[i].r;
            if (NoEnemy(V[i].letter)) return false;
            Move(V[i]);
            Attack(V[i]);
            // if (V[i].r <= 0 && V[i].letter == 'E') return false;
        }
        sort(V.begin(), V.end());
        return true;
    }

    void Solve() {
        while (true) {
            if (scanf("%s", Buffer) < 1) break;
            string s = Buffer;
            input.emplace_back(move(s));
        }
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].size(); j++) {
                if (input[i][j] != '.' && input[i][j] != '#') {
                    origin.emplace_back(
                        Coordinate{i, j, input[i][j], 200, 0});
                }
            }
        }

        map = input;
        V = origin;
        while (Action(round)) round++;
        int total = 0;
        for (const auto& i : V) {
            if (i.r > 0) {
                total += i.Hp;
            }
        }

        printf("%d %d\n", total, round);
        printf("%d\n", total * round);
        bool flag = false;
        while (!flag) {
            power++;
            flag = true;
            map = input;
            V = origin;
            round = 0;
            while (Action(round)) {
                round++;
            }
            for (int i = 0; i < V.size(); i++) {
                if (V[i].letter == 'E' && V[i].r <= 0) {
                    flag = false;
                    break;
                }
            }
        }
        total = 0;
        for (const auto& i : V) {
            if (i.r > 0) {
                total += i.Hp;
            }
        }
        printf("%d\n", power);
        printf("%d %d\n", total, round);
        printf("%d\n", total * round);
    }
};

int main() {
    Solution().Solve();
    return 0;
}