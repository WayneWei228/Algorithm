#include <cstdio>
#include <limits>
using namespace std;

// To continue, please consult the code grid in the manual.  Enter the code at row 2947, column 3029.

char Buffer[200];
typedef long long int64;

struct Solution {
    int64 grid[4000][4000];
    int64 calculate(int x, int y) {
        grid[1][1] = 20151125;
        int64 pre = 20151125;
        int64 mul = 252533;
        int64 div = 33554393;
        for (int64 sum = 3; sum < numeric_limits<int>::max(); sum++) {
            for (int64 i = sum - 1; i >= 1; i--) {
                grid[i][sum - i] = pre = ((pre % div) * (mul % div)) % div;
                if (i == 2947 && sum - i == 3029) {
                    return pre;
                }
            }
        }
        return 0;
    }

    void Solve() {
        int row, col;
        scanf("To continue, please consult the code grid in the manual.  Enter the code at row %d, column %d.", &row, &col);
        printf("%lld\n", calculate(row, col));
    }
};

int main() {
    Solution().Solve();
    return 0;
}