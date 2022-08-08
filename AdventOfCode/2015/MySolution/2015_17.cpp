#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

/*
33
14
18
20
45
35
16
35
*/

struct Solution {
    vector<int> Container;
    vector<bool> use;
    int Answer1 = 0, Answer2 = 0;
    int maxNum = 150;
    void fill(int now) {
        if(now == Container.size()) {
            int total = 0;
            for(int i = 0; i < use.size(); i++) {
                if(use[i]) {
                    total += Container[i];
                }
            }
            if(total == 150) {
                Answer1++;
            }
            return;
        }

        use[now] = true;
        fill(now + 1);
        use[now] = false;
        fill(now + 1);
    }

    void fill2(int now) {
        if(now == Container.size()) {
            int total = 0;
            int conNum = 0;
            for(int i = 0; i < use.size(); i++) {
                if(use[i]) {
                    total += Container[i];
                    conNum++;
                }
            }
            if(total == 150 && conNum < maxNum) {
                maxNum = conNum;
                Answer2 = 0;
            }
            if(total == 150 && conNum == maxNum) {
                Answer2++;
            }
            return;
        }

        use[now] = true;
        fill2(now + 1);
        use[now] = false;
        fill2(now + 1);
    }

    void Solve() {
        while (true) {
            int d;
            if(scanf("%d", &d) < 1) break;
            Container.push_back(d);
        }      

        use.resize(Container.size());

        fill(0);
        printf("%d\n", Answer1);

        fill2(0);
        printf("%d\n", Answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}