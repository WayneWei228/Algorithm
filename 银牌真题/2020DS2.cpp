#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;
bool ycomp(Point p, Point q) {
    return p.second < q.second;
}

const int MAX_N = 2500;
int N, Psum[MAX_N][MAX_N];
Point P[MAX_N];

int rsum(int x1, int y1, int x2, int y2) {
    return Psum[x2][y2] - Psum[x1 - 1][y2] - Psum[x2][y1 - 1] + Psum[x1 - 1][y1 - 1];
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        P[i] = make_pair(x, y);
    }

    // 压缩到 N * N
    sort(P, P + N, ycomp);
    for(int i = 0; i < N; i++) {
        P[i].second = i + 1;
    }

    sort(P, P + N);
    for(int i = 0; i < N; i++) {
        P[i].first = i + 1;
    }
    
    for(int i = 0; i < N; i++) { // 在二维地图中标记奶牛
        Psum[P[i].first][P[i].second] = 1;
    }

    cout << endl;
    for(int i = 0; i < N; i++) {
        cout << P[i].first << " " << P[i].second << endl;
    }

    cout << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << Psum[i][j] << " ";
        }
    }

    for(int i = 1; i <= N + 1; i++) { // 求前缀和
        for(int j = 1; j <= N + 1; j++) {
            Psum[i][j] += Psum[i - 1][j] + Psum[i][j - 1] - Psum[i - 1][j - 1];
        }
    }
    cout << endl;

    for(int i = N; i >= 0; i--) {
        for(int j = 0; j <= N; j++) {
            cout << Psum[i][j] << " ";
        }
        cout << endl;
    }


    
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            // cout << endl;
            // cout << P[i].first << " " << P[i].second << endl; 
            // cout << P[j].first << " " << P[j].second << endl; 

            int y1 = min(P[i].second, P[j].second);
            int y2 = max(P[i].second, P[j].second);
            ans += rsum(0, y1, i + 1, y2) * rsum(j, y1, N, y2);
        }
    }

    // cout << ans << endl;

    cout << rsum(1, 3, 2, 4) << endl;

    cout << Psum[1][2] << endl;
}


/*
4
1 3
2 1
3 2
4 4
*/