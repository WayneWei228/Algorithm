#include <cstdio>
using namespace std;

/*
M 条边
N 个点
N 个点中找大于等于 g 个点组成的独立集即为 possible
反之则 impossible
最大独立集等同于最小点覆盖
则问题转变成能否用 N - g 个点覆盖所有边

*/


struct Solution {

    void Solve() {

    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve();
    return 0;
}  