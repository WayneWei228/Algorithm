#include <cstdio>
#include <set>
#include <vector>
using namespace std;

struct Solution {
    int n;
    vector<vector<int>> sudoku;
    set<int> biaozhun;
    bool JudgeLine(const vector<int>& part) {
        set<int> s;
        for (auto i : part) {
            s.emplace(i);
        }
        return s == biaozhun;
    }

    void Solve(int caseNo) {
        scanf("%d", &n);
        sudoku.resize(n * n);
        for (int i = 1; i <= n * n; i++) {
            biaozhun.emplace(i);
        }
        for (auto& i : sudoku) i.resize(n * n);
        for (int i = 0; i < n * n; i++) {
            for (int j = 0; j < n * n; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }
        bool Valid = true;
        for (int i = 0; i < n * n; i++) {
            if (!JudgeLine(sudoku[i])) {
                Valid = false;
            }
        }
        for (int j = 0; j < n * n; j++) {
            vector<int> v;
            for (int i = 0; i < n * n; i++) {
                v.emplace_back(sudoku[i][j]);
            }
            if (!JudgeLine(v)) {
                Valid = false;
            }
        }
        for (int i = 0; i < n * n; i += n) {
            for (int j = 0; j < n * n; j += n) {
                vector<int> v;
                for (int k = 0; k < n; k++) {
                    for (int z = 0; z < n; z++) {
                        v.emplace_back(sudoku[i + k][j + z]);
                    }
                }
                if (!JudgeLine(v)) {
                    Valid = false;
                }
            }
        }
        printf("Case #%d: %s\n", caseNo, Valid ? "Yes" : "No");
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}
