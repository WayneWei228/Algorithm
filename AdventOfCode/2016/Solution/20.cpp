#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int64;

struct Interval {
    int64 Begin, End;

    bool operator<(const Interval& that) const {
        return Begin < that.Begin;
    }
};

struct Solution {
    vector<Interval> Input;

    void Solve() {
        while (true) {
            int64 begin, end;
            if (scanf("%lld-%lld", &begin, &end) < 2) break;
            Input.emplace_back(Interval{begin, end + 1});
        }
        sort(Input.begin(), Input.end());
        int newSize = 1;
        for (int i = 1; i < Input.size(); ++i) {
            if (Input[i].Begin <= Input[newSize - 1].End) {
                Input[newSize - 1].End =
                    max(Input[newSize - 1].End, Input[i].End);
            } else {
                Input[newSize++] = move(Input[i]);
            }
        }
        Input.resize(newSize);
        printf("%lld\n", Input[0].Begin == 0 ? Input[0].End : 0);
        int64 ban = 0;
        for (const auto& i : Input) ban += i.End - i.Begin;
        printf("%lld\n", 4294967296 - ban);
    }
};

int main() {
    Solution().Solve();
    return 0;
}