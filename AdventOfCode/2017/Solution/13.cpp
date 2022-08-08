#include <cstdio>
#include <vector>
using namespace std;

struct Scanner {
    int Depth, Range;
};

struct Solution {
    vector<Scanner> Input;

    bool Success(int delay) {
        for (const auto& i : Input) {
            if ((i.Depth + delay) % ((i.Range - 1) * 2) == 0) {
                return false;
            }
        }
        return true;
    }

    void Solve() {
        while (true) {
            Scanner c;
            if (scanf("%d: %d", &c.Depth, &c.Range) < 2) break;
            Input.emplace_back(move(c));
        }
        int answer1 = 0, answer2 = 0;
        for (const auto& i : Input) {
            if (i.Depth % ((i.Range - 1) * 2) == 0) {
                answer1 += i.Depth * i.Range;
            }
        }
        while (!Success(answer2)) ++answer2;
        printf("%d\n%d\n", answer1, answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}