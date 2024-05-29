#include <bits/stdc++.h>
using namespace std;

#define maxn 500
typedef pair<int, int> pii;
// typedef vector<pii> plt;
multimap<pii, pii> switches;
bool on[maxn][maxn];
bool visited[maxn][maxn];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int N, M;




bool isVisited(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= N && visited[x][y];
}


bool isOn(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= N && on[x][y];
}

bool hasVisitedNeighbor(int x, int y) {
    for(int k = 0; k < 4; k++) {
        if(isOn(x + dx[k], y + dy[k]) && isVisited(x + dx[k], y + dy[k])) {
            return true;
        }
    }
    return false;
}

void search(int x, int y) {
    if(isVisited(x, y)) return;
    visited[x][y] = true;
    pii pair_key = make_pair(x, y);
    multimap<pii, pii>::iterator it = switches.find(pair_key);
    int num = switches.count(pair_key);
    while(num > 0) {
        if(!on[it->second.first][it->second.second]) {
            on[it->second.first][it->second.second] = true;
            if(hasVisitedNeighbor(it->second.first, it->second.second))
                search(it->second.first, it->second.second);
        }
        it++;
        num--;
    }
    for(int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(isOn(nx, ny)) {
			search(nx, ny);
		}
    }
}


int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {   
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        pii pair_1 = make_pair(x, y);
        pii pair_2 = make_pair(a, b);
        switches.insert(pair<pii, pii> (pair_1, pair_2));
    }

    // for(multimap<pii, pii>::iterator it = switches.begin(); it != switches.end(); it++) {
    //     cout << it->first.first << " " << it -> first.second << "  " << it->second.first << " " << it-> second.second << endl;

    // }
    // for(int i = 0; i <= N; i++) {
    //     for(int j = 1; j <= N; j++) {
    //         cout << on[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    on[1][1] = true;
    search(1, 1);
    long long ret = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(on[i][j]) {
                ret++;
                // cout << "(" << i << "," << j << ')' << endl;
            }
        }
    }
    cout << ret << endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}