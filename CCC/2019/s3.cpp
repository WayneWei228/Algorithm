#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> triangles;

int main() {
    int N, K;
    cin >> N >> K;
    triangles.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            int x;
            cin >> x;
            triangles[i].push_back(x);
        }
    }
    
}