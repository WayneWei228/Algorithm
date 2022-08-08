#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char Buffer[105];

struct Solution {
    void Solve(int caseNo) {
        int n;
        vector<string> V;
        scanf("%d ", &n);
        V.resize(n);
        for (int i = 0; i < n; i++) {
            // \r\n 都会读空白符 等同于 空格
            // scanf("%[^\r\n] ", Buffer);
            // scanf("%[^\r\n]\r\n", Buffer);

            // the best
            scanf("%*[\r\n]%[^\r\n]", Buffer);
            string s = Buffer;
            V[i] = s;
        }
        int cnt = 0;
        for (int i = 1; i < V.size(); i++) {
            bool flag = false;
            string key = V[i];
            int j = i - 1;
            while (j >= 0 && key < V[j]) {
                flag = true;
                V[j + 1] = V[j];
                j--;
            }
            V[j + 1] = key;
            if (flag) {
                cnt++;
            }
        }
        printf("Case #%d: %d\n", caseNo, cnt);
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}