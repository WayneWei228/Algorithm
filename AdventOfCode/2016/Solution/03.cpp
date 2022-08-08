#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    vector<int> A;

    bool IsTriangle(int a0, int a1, int a2) {
        return a0 < a1 + a2 && a1 < a2 + a0 && a2 < a0 + a1;
    }

    void Solve() {
        while (true) {
            int a[3];
            if (scanf("%d%d%d", &a[0], &a[1], &a[2]) < 3) break;
            A.insert(A.end(), &a[0], &a[3]); //  往末尾插入三个, 从a[0] 到 a[3] 不能写a.end()
        }
        int answer1 = 0, answer2 = 0;
        for (int i = 0; i < A.size(); i += 3) {
            if (IsTriangle(A[i], A[i + 1], A[i + 2])) ++answer1;
        }
        printf("%d\n", answer1);
        for (int i = 0; i < A.size(); i += 9) {
            if (IsTriangle(A[i], A[i + 3], A[i + 6])) ++answer2;
            if (IsTriangle(A[i + 1], A[i + 4], A[i + 7])) ++answer2;
            if (IsTriangle(A[i + 2], A[i + 5], A[i + 8])) ++answer2;
        }
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
