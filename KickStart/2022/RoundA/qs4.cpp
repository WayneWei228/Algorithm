#include <cstdio>
#include <string>
using namespace std;

typedef long long int64;

struct Solution {
    int64 A, B;
    int ans = 0;
    
    void Solve(int caseNo) {
        scanf("%lld%lld", &A, &B);
        for (int i = A; i <= B; i++) {
            if (Can(i)) {
                ans++;
            }
        } 
        printf("Case #%d: %d\n", caseNo, ans);
    }

    bool Can(int num) {
        string s = to_string(num);
        int64 product = 1;
        int64 sum = 0;
        for (int i = 0; i < s.size(); i++) {
            product *= s[i] - '0';
            sum += s[i] - '0';
        }
        if (product % sum == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
} 