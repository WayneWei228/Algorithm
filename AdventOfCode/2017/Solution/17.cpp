#include <cstdio>
#include <vector>
using namespace std;

struct SpinLockA {
    int Delta, Position = 0;
    vector<int> Data{0};

    void Add(int n) {
        Position = (Position + Delta + 1) % Data.size();
        Data.emplace(Data.begin() + Position, n);
    }

    int After(int n) {
        int index = 0;
        while (Data[index] != n) ++index;
        return Data[(index + 1) % Data.size()];
    }
};

struct SpinLockB {
    int Delta, Position = 0, Head = 0, Size = 1;

    void Add(int n) {
        Position = (Position + Delta + 1) % Size++;
        if (Position == 0) Head = n;
    }
};

struct Solution {
    void Solve() {
        int delta;
        scanf("%d", &delta);
        SpinLockA spinA{delta};
        for (int i = 1; i <= 2017; ++i) spinA.Add(i);
        printf("%d\n", spinA.After(2017));
        SpinLockB spinB{delta};
        for (int i = 1; i <= 50000000; ++i) spinB.Add(i);
        printf("%d\n", spinB.Head);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
