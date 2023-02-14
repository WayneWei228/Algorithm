#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> trees(T);
    for (int i = 0; i < T; i++) {
        cin >> trees[i].first >> trees[i].second;
    }
    trees.push_back(make_pair(0, 0));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {

        }
    }
    return 0;
}