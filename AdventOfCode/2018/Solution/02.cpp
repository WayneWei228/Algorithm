#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer[80];

struct Solution {
    vector<string> Input;

    int Solve0() {
        int count2 = 0, count3 = 0;
        for (const string& i : Input) {
            int count[26]{};
            for (char j : i) ++count[j - 'a'];
            bool has2 = false, has3 = false;
            for (int j : count) {
                if (j == 2) has2 = true;
                if (j == 3) has3 = true;
            }
            if (has2) ++count2;
            if (has3) ++count3;
        }
        return count2 * count3;
    }

    string Solve1() {
        for (int i = 0; i < Input[0].size(); ++i) {
            unordered_set<string> visited;
            // 把每个字符串删去一个字符的状态存到unordered_set 里面，如果出现重复则返回
            for (string j : Input) {
                j.erase(i, 1);
                if (visited.count(j)) return j;
                visited.emplace(j);
            }
        }
        return {};
    }

    void Solve() {
        while (scanf("%s", Buffer) == 1) {
            Input.emplace_back(Buffer);
        }
        printf("%d\n", Solve0());
        printf("%s\n", Solve1().c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
