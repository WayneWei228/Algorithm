#include <cstdio>
#include <vector>
using namespace std;

struct Layer {
    int depth, range, period;

};

struct Solution {
    vector<Layer> Input;
    int severity = 0;

    bool Pass(int i) {
        for (auto j : Input) {
            if ((j.depth + i) % j.period == 0) return false;
        }
        return true;
    }

    void Solve() {
        int a, b;
        while (true) {
            Layer l;
            if (scanf("%d: %d", &l.depth, &l.range) < 2) break;
            l.period = (l.range - 1) * 2;
            Input.emplace_back(move(l));
        }
        for (auto i : Input) {
            if (i.depth % i.period == 0) {
                severity += i.depth * i.range;
            }
        }
        int i;
        for (i = 1;;i++) {
            if (Pass(i)) break;
        }
        printf("%d\n", severity);
        printf("%d\n",  i);
    }
};

int main() {
    Solution().Solve();
    return 0;
}