#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int R, A, B;


double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

    void Solve() {

        vector<double> a;
        for (int i = 0; i < 25; i++) {
            if (i == 2 || i == 7 || i == 16) {
                a.emplace_back(3.14);
                continue;
            }
            a.emplace_back(fRand(0.0, 10.0));
        }
            printf("{ ");

        for (auto i : a) {
            printf("%.2f, ", i);

        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}