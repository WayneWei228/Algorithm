#include <cstdio>
using namespace std;

struct Solution {
    int X;
    double Y;

    void Solve() {
        scanf("%d%lf", &X, &Y);
        if (X + 0.5 <= Y && X % 5 == 0) {
            printf("%.2lf\n", Y - X - 0.5);
        } else {
            printf("%.2lf\n", Y);
        } 
    }
};


int main(){
    Solution().Solve();
    return 0;
}