#include <cstdio>
#include <limits>
#include <string>
using namespace std;

char Buffer[50000];

struct Solution {
    char Map[26][2];
    int ans2 = numeric_limits<int>::max();

    int React(string&& s) {
        bool reduce = true;
        while (reduce) {
            reduce = false;
            for (int i = 0; i < int(s.size()) - 1; i++) {
                if (abs(s[i] - s[i + 1]) == 32) {
                    s.erase(i, 2);
                    reduce = true;
                }
            }
        }
        return int(s.size());
    }

    void Solve() {
        scanf("%s", Buffer);
        string s = Buffer;

        printf("%d\n", React(move(s)));

        int a = 'A', b = 'a';
        for (int i = 0; i < 26; i++) {
            Map[i][0] = a++;
            Map[i][1] = b++;
        }

        for (const auto& i : Map) {
            string s = Buffer;
            for (int j = 0; j < int(s.size()); j++) {
                if (s[j] == i[0] || s[j] == i[1]) {
                    s.erase(j, 1);
                    j--;
                }
            }
            int a = React(move(s));
            if (a < ans2) ans2 = a;
        }

        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}