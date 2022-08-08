#include <cstdio>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

char Buffer[20];

struct Solution {
    int N, dir;
    unordered_map<string, int> toDir;
    vector<vector<int>> M;

    vector<int> Move(const vector<int>& v) {
        vector<int> newV;
        queue<int> q;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != 0) {
                q.emplace(v[i]);
            }
            if (int(q.size()) > 1) {
                auto front = q.front();
                q.pop();
                if (front == q.front()) {
                    newV.emplace_back(front * 2);
                    q.pop();
                } else {
                    newV.emplace_back(front);
                }
            }
        }
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            newV.emplace_back(front);
        }
        return newV;
    }

    void Solve(int caseNo) {
        toDir["left"] = 0;
        toDir["right"] = 1;
        toDir["up"] = 2;
        toDir["down"] = 3;
        scanf("%d %s", &N, Buffer);
        dir = toDir[Buffer];
        M.resize(N);
        for (auto& i : M) {
            i.resize(N);
            for (auto& j : i) {
                scanf("%d", &j);
            }
        }
        switch (dir) {
            case 0: {
                for (int i = 0; i < N; i++) {
                    vector<int> temp = Move(M[i]);
                    M[i].clear();
                    M[i].resize(N, 0);
                    for (int j = 0; j < temp.size(); j++) {
                        M[i][j] = temp[j];
                    }
                }
                break;
            }
            case 1: {
                for (int i = 0; i < N; i++) {
                    reverse(M[i].begin(), M[i].end());
                    vector<int> temp = Move(M[i]);
                    M[i].clear();
                    M[i].resize(N, 0);
                    int idx = M[i].size() - 1;
                    for (int j = 0; j < temp.size(); j++) {
                        M[i][idx--] = temp[j];
                    }
                }
                break;
            }
            case 2: {
                for (int i = 0; i < N; i++) {
                    vector<int> input;
                    for (int j = 0; j < N; j++) {
                        input.emplace_back(M[j][i]);
                        M[j][i] = 0;
                    }
                    vector<int> temp = Move(input);
                    int idx = 0;
                    for (int j = 0; j < temp.size(); j++) {
                        M[idx++][i] = temp[j];
                    }
                }
                break;
            }
            case 3: {
                for (int i = 0; i < N; i++) {
                    vector<int> input;
                    for (int j = 0; j < N; j++) {
                        input.emplace_back(M[j][i]);
                        M[j][i] = 0;
                    }
                    reverse(input.begin(), input.end());
                    vector<int> temp = Move(input);
                    int idx = N - 1;
                    for (int j = 0; j < temp.size(); j++) {
                        M[idx--][i] = temp[j];
                    }
                }
                break;
            }
        }
        printf("Case #%d:\n", caseNo);
        for (auto i : M) {
            for (auto j : i) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}