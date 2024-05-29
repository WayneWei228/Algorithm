#include <cstring>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

int N, B;
int road[255];
int ans;
set<int> vis;

struct node {
    int s;
    int d;
 } shoes[255];


int main() {
    freopen("snowboots.in", "r",stdin);
    freopen("snowboots.out","w",stdout);
    cin >> N >> B;
    for(int i = 1; i <= N; i++) {
        cin >> road[i];
    }
    for(int i = 0; i < B; i++) {
        cin >> shoes[i].s >> shoes[i].d;
    }
    vis.insert(1);
    for(int i = 0; i < B; i++) {
        set<int>::iterator it = vis.begin();
        while(it != vis.end()) {
            int dis = shoes[i].d;
            if(shoes[i].s >= road[*it]) {
                for(int j = 1; j <= dis; j++) {
                    if(road[*it + j] <= shoes[i].s && (*it + j) <= N) {
                        vis.insert(*it + j);
                    }
                }
            }
            it++;
        }
        if(*vis.rbegin() == N) {
            ans = i;            
            break;
        }
    }
    // for(auto it = vis.begin(); it != vis.end(); it++) {
    //     cout << *it << endl;
    // }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}