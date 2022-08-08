#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[80];

struct Solution {
    vector<string> B, NewB, V;
    unordered_map<string, int> Visited;
    int Start = 0, Loop = 0;

    void Solve() {
        while (scanf("%s", Buffer) == 1) B.emplace_back(Buffer);
        for (int i = 0;; ++i) {
            auto result = Visited.emplace(Concat(), i);
            if (!result.second) {
                Start = result.first->second;
                Loop = i - Start;
                break;
            }
            Transform();
        }
        V.resize(Visited.size());
        for (const auto& i : Visited) V[i.second] = i.first;
        printf("%d\n", CountProduct(After(10)));
        printf("%d\n", CountProduct(After(1000000000)));
    }

    void Transform() {
        NewB = B;
        for (int i = 0; i < B.size(); ++i) {
            for (int j = 0; j < B[i].size(); ++j) Transform(i, j);
        }
        swap(B, NewB);
    }

    void Transform(int x, int y) {
        switch (B[x][y]) {
            case '.':
                return Transform0(x, y);
            case '|':
                return Transform1(x, y);
            case '#':
                return Transform2(x, y);
        }
    }

    void Transform0(int x, int y) {
        if (Near(x, y, '|') < 3) return;
        NewB[x][y] = '|';
    }

    void Transform1(int x, int y) {
        if (Near(x, y, '#') < 3) return;
        NewB[x][y] = '#';
    }

    void Transform2(int x, int y) {
        // 本身自己就是 '#', 所以要大于1
        if (1 < Near(x, y, '#') && 0 < Near(x, y, '|')) return;
        NewB[x][y] = '.';
    }

    int Near(int x, int y, char c) {
        int answer = 0;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if (i < 0 || B.size() <= i) continue;
                if (j < 0 || B[i].size() <= j) continue;
                if (B[i][j] == c) ++answer;
            }
        }
        return answer;
    }
    // convert vector<string> to string
    string Concat() {
        string answer;
        for (const auto& i : B) answer += i;
        return answer;
    }

    string After(int time) {
        if (time < Start) return V[time];
        return V[Start + (time - Start) % Loop];
    }

    int CountProduct(const string& s) {
        return Count(s, '|') * Count(s, '#');
    }

    int Count(const string& s, char c) {
        int answer = 0;
        for (char i : s) {
            if (i == c) ++answer;
        }
        return answer;
    }
};

int main() {
    Solution().Solve();
    return 0;
}
