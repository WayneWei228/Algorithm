#include <bits/stdc++.h>
using namespace std;

/* 
5 5
HHGHG
1 2
2 3
2 4
1 5
1 4 H
1 4 G
1 3 G
1 3 H
5 5 H
*/
typedef vector<int> vi; 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back

const int MX = 100005;
int N, M, comp[MX], num;
char col[MX];
vi adj[MX];

void dfs(int x) { // 如果头和尾都是相同数字，则说明类型没有变化
    if (comp[x]) return;
    comp[x] = num;
    trav(t, adj[x]) if(col[t] == col[x]) dfs(t);
}

int main() {
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    cin >> N >> M;
    string s; 
    cin >> s;
    FOR(i, 1, N + 1) col[i] = s[i - 1];
    F0R(i, N - 1) {
        int A, B;
        cin >> A >> B;
        adj[A].pb(B), adj[B].pb(A);
    }
    FOR(i, 1, N + 1) {
        if(!comp[i]) {
            num++;
            dfs(i);
        }
    }
    F0R(i, M) {
        int A, B;
        char C;
        cin >> A >> B >> C;
        if(col[A] == C || comp[A] != comp[B]) cout << 1;
        else cout << 0;
    }
    cout << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}