#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
确定可选成员

展示某人已经跟谁走过路

随机生成匹配对象
*/
struct Solution {
    int N;
    vector<string> Names;
    vector<vector<bool>> V;

    void Solve() {
        Names.resize(N);
        for (int i = 0; i < N; i++) {
            Names[i] = 'A' + i;
        }
        V.resize(N);
        for (auto& i : V) {
            i.resize(N);
        }
        for (int i = 0; i < N; i++) {
            V[i][i] = true;
        }

        


    }
};


int main() {
    Solution().Solve();
    return 0;
}