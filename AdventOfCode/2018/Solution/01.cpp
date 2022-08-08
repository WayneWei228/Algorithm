#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

struct Solution {
    vector<int> Input;

    int Solve0() {
        int answer = 0;
        for (int i : Input) answer += i;
        return answer;
    }

    int Solve1() {
        unordered_set<int> visited;
        int current = 0;
        while (true) {
            for (int i : Input) {
                current += i;
                if (visited.count(current)) return current;
                visited.emplace(current);
            }
        }
    }

    void Solve() {
        while (true) {
            int x;
            if (scanf("%d", &x) < 1) break;
            Input.emplace_back(x);
        }
        printf("%d\n", Solve0());
        printf("%d\n", Solve1());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
