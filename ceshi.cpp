#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

// struct Solution {
//     int N;
//     unordered_set<vector<int>> store;

//     void dfs(int no, const vector<int>& a) {

//         if (a.size() != 1) {
//             store.emplace(a);
//         }

        
//         for (int i = no + 2; i <= N; i++) {
//             vector<int> arr(a);
//             arr.emplace_back(i);
//             dfs(i, arr);
//         }
//         return;
//     }

//     void Solve() {
//         N = 5;
//         vector<int> a = {1};
//         dfs(1, a);
//         for (auto& i : store) {
//             for (auto j : i) {
//                 cout << j << " ";
//             }
//             cout << endl;
//         }
//     }
// };

int main() {
    return 0;
}

