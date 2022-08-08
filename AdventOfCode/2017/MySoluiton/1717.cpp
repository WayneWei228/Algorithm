#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int steps;
    vector<int> v;
    int no = 0;

    void Solve() {
        scanf("%d", &steps);
        v.emplace_back(0);
        for (int i = 1; i < 2018; i++) {
            int size = int(v.size());
            no = (no + (steps % size)) % size + 1;
            v.insert(v.begin() + no, i);
            if (i == 2017) {
                printf("%d\n", v[no + 1]);
            }
        }
        int size = 1;
        int value;
        for (int i = 1; i < 50000001; i++) {
            no = (no + (steps % size)) % size + 1;
            size++;
            if (no == 1) {
                value = i;
            }
        }
        printf("%d\n", value);
    }
};

int main() {
    Solution().Solve();
    return 0;
}