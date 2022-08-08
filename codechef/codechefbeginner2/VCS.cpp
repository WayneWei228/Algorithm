#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<bool> ignored, tracked;
        ignored.resize(N+1);
        tracked.resize(N+1);
        for(int i = 0; i < M; i++) {
            int temp;
            cin >> temp;
            ignored[temp] = true;
        }
        for(int i = 0; i < K; i++) {
            int temp;
            cin >> temp;
            tracked[temp] = true;
        }
        int first = 0,second = 0;
        for(int i = 1; i <= N; i++) {
            if(ignored[i]&&tracked[i]) first++;
            if(!ignored[i]&&!tracked[i]) second++;
        }
        cout << first << " " << second << endl;
    }
    return 0;
}