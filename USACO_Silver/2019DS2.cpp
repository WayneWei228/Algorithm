#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi; 
typedef vector<pair<int,int> > vpi; 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second

int N, L;
vi w, x, d;

bool cmp(int a, int b) {
    return x[a] < x[b];
}

int getTime() {
    vi lef, rig;
    F0R(i, N) { // 如果是 -1， lef就添加位置，位置从左到右
        if (d[i] == -1) lef.pb(x[i]);
        else rig.pb(x[i]);
    }
    vpi v;

    F0R(i,sz(lef)) v.pb({lef[i],w[i]}); 
    F0R(i,sz(rig)) v.pb({L - rig[i], w[sz(lef) + i]}); // 第一个到达最左边的一定是最左边牛的体重
    sort(all(v));
    int tot = 0; trav(t, v) tot += t.s; // 体重和
    trav(t, v) {
        tot -= 2 * t.s;
        if(tot <= 0) return t.f;
    }

}
int main() {
    freopen("meetings.in","r",stdin);
    freopen("meetings.out","w",stdout);
    cin >> N >> L;
    w.rsz(N), x.rsz(N), d.rsz(N);
    F0R(i, N) cin >> w[i] >> x[i] >> d[i];
    vi inds(N);
    iota(all(inds), 0);
    sort(all(inds), cmp); // 位置在前的奶牛下标在前
    vi W, X, D;
    trav(t, inds) {
        W.pb(w[t]);
        X.pb(x[t]);
        D.pb(d[t]);
    } // 从左往右的体重，位置，方向依次加入
    // 可输出检测
    swap(w, W), swap(x, X), swap(d, D);

    int t = getTime();
    queue<int> rig;
    int ans = 0;
    F0R(i, N) {
        if(d[i] == -1) {
            while (sz(rig) && rig.front() + 2 * t < x[i]) rig.pop();
            ans += sz(rig);
        } else rig.push(x[i]);
    }
    cout << ans << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
