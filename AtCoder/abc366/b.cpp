/**
 *    author:  wayne
 *    created: 2024-08-13 01:49:55
 **/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int M = 0;

    // vector<string> S;
    // for (int i = 0; i < N; i++) {
    //     string s;
    //     cin >> s;
    //     S.push_back(s);
    //     M = max(M, (int)s.size());
    // }

    // better init
    vector<string> S(N);
    for (auto& s : S) {
        cin >> s;
        M = max(M, (int)s.size());
    }

    vector<string> T(M, string(N, '*'));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)S[i].size(); j++) {
            T[j][N - i - 1] = S[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        while (T[i].back() == '*') {
            T[i].pop_back();
        }
        cout << T[i] << endl;
    }

    //unknow bug below

    // int N;
    // cin >> N;
    // int M = -1;
    // vector<string> S;

    // for (auto& s : S) {
    //     cin >> s;
    //     M = max(M, (int)s.size());
    // }

    // while (N--) { // never use N-- unless N will not be use anymore
    //     string s;
    //     cin >> s;
    //     M = max(M, (int)s.size());
    //     S.push_back(s);
    // }

    // vector<string> T(M, string(N, "*"));


    // for (int i = 0; i < S.size(); i++) {
    //     for (int j = 0; j < (int)S[i].size(); j++) {
    //         T[j][N - i - 1] = S[i][j];
    //     }
    // }
    return 0;
}