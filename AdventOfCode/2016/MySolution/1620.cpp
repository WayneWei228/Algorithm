#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

// 0 0 0 0 0  0
// 0 1 0 0 0 -1
// 0 1 1 1 1  0
// 1 - 4

typedef long long int64;

struct Range {
    int64 left, right;

    Range(int64 l, int64 r) : left(l), right(r){};

    bool operator<(const Range& that) const {
        return left < that.left || left == that.left && right > that.right;
    }
};

struct Solution {
    int64 left, right;
    vector<Range> ranges;

    int64 Compute1() {
        int64 no = 0;
        for (int i = 0; i < ranges.size(); ++i) {
            if (ranges[i].left <= no && ranges[i].right > no) {
                no = ranges[i].right + 1;
            }
        }
        return no;
    }

    int64 Compute2() {
        int64 no = 0;
        int64 cnt = 0;
        for (int i = 0; i < ranges.size(); ++i) {
            if (ranges[i].left <= no && ranges[i].right >= no) {
                no = ranges[i].right + 1;
                continue;
            } 
            if (ranges[i].left > no) {
                cnt += ranges[i].left - no;
                no = ranges[i].right + 1;
            }
        }
        cnt += 4294967296 - no;
        return cnt;
    }

    void Solve() {
        while (scanf("%lld-%lld", &left, &right) == 2) {
            ranges.emplace_back(left, right);
        }
        sort(ranges.begin(), ranges.end());
        printf("%lld\n", Compute1());
        printf("%lld\n", Compute2());
    }
};

int main() {
    Solution().Solve();
    return 0;
}