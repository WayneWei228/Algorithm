#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <queue>
using namespace std;

#define f first
#define s second

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

bool present[3000][3000]; // which locations contain cows
queue<pair<int,int> > cows_to_place;


void re_evaluate (int x, int y) {
    if (!present[x][y]) {
        return;
    }
	int num_adj = 0;
	for (int d = 0; d < 4; ++d) { 
		num_adj += present[x+dx[d]][y+dy[d]];
    }
	if (num_adj == 3) {
		for (int d = 0; d < 4; ++d) {
			pair<int,int> nex {x+dx[d],y+dy[d]};
			if (!present[nex.f][nex.s]) {
				cows_to_place.push(nex);
            }        
		}
    }
    return;
}


int main() {
	int N; cin >> N;
	int total_cows = 0;
	for (int initial_cows = 1; initial_cows <= N; ++initial_cows) {
		pair<int,int> p; 
        cin >> p.f >> p.s;
		p.f += 1000, p.s += 1000;
		cows_to_place.push(p);
        re_evaluate(p.f, p.s);
		while (!cows_to_place.empty()) {
			pair<int,int> loc = cows_to_place.front(); 
			cows_to_place.pop();
			if (present[loc.f][loc.s]) continue;
			++ total_cows; 
            present[loc.f][loc.s] = 1;
			re_evaluate(loc.f,loc.s);
			for (int d = 0; d < 4; ++d) 
				re_evaluate(loc.f+dx[d],loc.s+dy[d]);
		}
		cout << total_cows-initial_cows << "\n";
	}
}






// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <utility>
// #include <set>
// using namespace std;
// typedef long long ll;
// typedef pair<ll, ll> pii;


// struct Graph {
//     set<pii> out_edges;
//     int size;
//     int values;
// };
// map<pii, Graph> point;

// int N;
// int ans;
// int dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};

// void add_edge(pii a, pii b) {
//     point[a].out_edges.insert(b);
//     point[b].out_edges.insert(a);
//     point[a].size = point[a].out_edges.size();
//     point[b].size = point[b].out_edges.size();
//     return;
// }

// void dfs(pii p){
//     for(int i = 0; i < 4; i++) {
//         pii p2 = make_pair(p.first + dir[i][0], p.second + dir[i][1]);
//         if(point[p2].values == 0) {
//             // cout << p2.first << p2.second << endl;
//             ans++;
//             point[p2].values = 2;
//             add_edge(p, p2);
//             for(int j = 0; j < 4; j++) {
//                 pii p3 = make_pair(p2.first + dir[j][0], p2.second + dir[j][1]);
//                 if(point[p3].values != 0 && p3 != p) {
//                     add_edge(p3, p2);
//                 }
//                 if(point[p3].size == 3) {
//                     dfs(p3);
//                 }
//             }
//             if(point[p2].size == 3) {
//                 dfs(p2);
//             }
//         }
//     }
//     return;
// }


// int main() {
//     cin >> N;
//     ans = 0;
//     for(int i = 1; i <= N; i++) {
//         bool flag = true;
//         int x1, y1;
//         cin >> x1 >> y1;
//         pii p = make_pair(x1, y1);
//         if(point[p].values == 2) {
//             ans--;
//             flag = false;
//         }
//         point[p].values = 1;
//         if(flag) {
//             for(int j = 0; j < 4; j++) {
//                 pii p1 = make_pair(x1 + dir[j][0], y1 + dir[j][1]);
//                 if(point[p1].values != 0) {
//                     add_edge(p, p1);
//                 }
//                 if(point[p1].size == 3) {
//                     dfs(p1);
//                 }
//             }
//             if(point[p].size == 3) {
//                 dfs(p);
//             }
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }