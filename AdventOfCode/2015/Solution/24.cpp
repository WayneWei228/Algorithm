#include <cstdio>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

struct Solution {
    vector<int> Input;
    int Sum = 0, MinLength, Each;
    double MinEntanglement;

    void Put(int k, int no, int s1, int s2, int s3, int s4, int length,
             double e) {
        int lengthBound = // 最优性剪枝， 已知一个最优解，当前节点下属的所有点都不及此解，故不用搜
            no == -1 ? length // 最好的length
                     : length + (Each - s1 + Input[no] - 1) / Input[no]; // 假如都放最大的：Input[no], 还要那么长 || 上取整（Input[no] - 1) / Input[no]
        if (MinLength < lengthBound ||
            MinLength == lengthBound && MinEntanglement <= e) {
            return;
        }
        if (no == -1) {
            MinLength = length;
            MinEntanglement = e;
            return;
        }
        if (s1 + Input[no] <= Each) {
            Put(k, no - 1, s1 + Input[no], s2, s3, s4, length + 1,
                e * Input[no]);
        }
        if (s2 + Input[no] <= Each) {
            Put(k, no - 1, s1, s2 + Input[no], s3, s4, length, e);
        }
        if (s3 + Input[no] <= Each && s2) { // s2 空先放 s2 题目中s2, s3, s4 保证对称性
            Put(k, no - 1, s1, s2, s3 + Input[no], s4, length, e);
        }
        if (s4 + Input[no] <= Each && s2 && s3 && k == 4) {
            Put(k, no - 1, s1, s2, s3, s4 + Input[no], length, e);
        }
    }

    double Compute(int k) {
        MinLength = numeric_limits<int>::max();
        MinEntanglement = 1.0 / 0.0;
        Each = Sum / k;
        Put(k, Input.size() - 1, 0, 0, 0, 0, 0, 1.0);
        return MinEntanglement;
    }

    void Solve() {
        while (true) {
            int x;
            if (scanf("%d", &x) < 1) break;
            Sum += x;
            Input.emplace_back(x);
        }
        printf("%.0lf\n", Compute(3));
        printf("%.0lf\n", Compute(4));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
