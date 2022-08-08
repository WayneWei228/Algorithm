#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<vector<char> > pasture(N, vector<char>(M));
    for(vector<char>& a: pasture) {
        for(char& b: a) {
            cin >> b;
        }
    }

    vector<vector<int> > grid(N, vector<int>(M));
    for(int i = N - 1; i >= 0; i--) {
        vector<int> all_ones(M, 1);
        int row = 0;
        for(int j = i; j < N; j++) {
            int run = 1;
            for(int k = 0; k < M; k++) {
                if(pasture[j][k] == '.' && all_ones[k] != 0) {
                    all_ones[k] = run; 
                }
                else
                {
                    all_ones[k] = 0;
                    run = 0;
                }
                run++;
            }
            int index = 0;
            for(int p = M - 1; p >= 0; p--) {
                if(all_ones[p] != 0) {
                    grid[row][index++] += all_ones[p];
                }
                else
                {
                    index = 0;
                }
            }
            row++;
        }
    }

    for(auto a:grid) {
        for(auto b: a) {
            cout << b << ' ';
        }
        cout << "\n";
    }
    return 0;

}