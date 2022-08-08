#include <cstdio>
#include <vector>
#include <limits>
#include <iostream>
using namespace std;




struct Solution {
    vector<int> V;
    int minSize = numeric_limits<int>::max();
    int entanglement = numeric_limits<int>::max();
                        
    void Separate(int no, int a, int b, int c, int lenA, int mulA) {

        if (a - V[no] < 0 && b - V[no] < 0 && c - V[no] < 0) return;
        
        if (lenA > minSize) return;
        if (no == V.size()) {
            if (a == 0 && b == 0 && c == 0) {
                if (lenA < minSize) {
                    entanglement = mulA;
                } else if (lenA == minSize && mulA < entanglement) {
                    entanglement = mulA;
                }
            } 
            return;
        } 

        if (a - V[no] >= 0) {
            Separate(no + 1, a - V[no], b, c, ++lenA, mulA * V[no]);
        }
        if (b - V[no] >= 0) {
            Separate(no + 1, a, b - V[no], c, lenA, mulA);
        }
        if (c - V[no] >= 0) {
            Separate(no + 1, a, b, c - V[no], lenA, mulA);
        }
        return;
    }

    void Solve() {
        int sum = 0;
        while (true) {
           int d;
           if (scanf("%d\n", &d) < 1) break;
            V.emplace_back(d);
            sum += d;
        }
        int average = sum / 3;
        cout << average << endl;
        Separate(0, average, average, average, 0, 1);

        printf("%d\n", entanglement);
    }
};

int main() {
    Solution().Solve();
    return 0;
}