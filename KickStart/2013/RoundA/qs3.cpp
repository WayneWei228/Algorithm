#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T;
vector<pair<int, int>> V;
queue<pair<int, int>> q;

void Start() {
    q.emplace(1, 1);
    for (int i = 0; i < 100000; i++) {
        auto front = q.front();
        q.pop();
        q.emplace(front.first, front.first + front.second);
        q.emplace(front.first + front.second, front.second);
        V.emplace_back(move(front));
    }
}
struct Solution {
    int id;

    void Read() {
        scanf(" %d ", &id);
        if (id == 1) {
            Solve1();
        } else {
            Solve2();
        }
    }
    void Solve1() {
        int a;
        scanf(" %d ", &a);
        cout << " " << V[a - 1].first << " " << V[a - 1].second;
    }

    void Solve2() {
        int a, b;
        scanf(" %d %d ", &a, &b);
        auto c = make_pair(a, b);
        for (int i = 0; i < V.size(); i++) {
            if (V[i] == c) {
                cout << " " << i + 1;
                return;
            }
        }
    }
};

int main() {
    cin >> T;
    Start();
    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ":";
        Solution().Read();
        cout << endl;
    }
    return 0;
}