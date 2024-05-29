//USACO 2020 January Contest, Silver Problem 3. Wormhole Sort

/*
 Binary search on the answer x. For all wormholes i such that x≤wi, draw an edge between barns ai and bi. It is possible to sort the cows with wormholes of width at least x if and only if pi is in the same connected component as i for all i.

 To see that this is true, consider the case when the resulting edges form a tree. We can always perform swaps until one of the barns that is a leaf in the tree contains the correct cow. Then remove this leaf from the tree and continue the process.
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Edge {
    int d, w;
};

int n, m;
int loc[100000];
int component[100000];
vector<Edge> edges[100000];

void dfs(int curr, int label, int minW) {
    if(component[curr] == label) return;
    component[curr] = label;

    for(Edge child: edges[curr]) {
        if(child.w >= minW) {
            dfs(child.d, label, minW);
        }
    }
}


bool valid(int minW) {
    fill(component,component + n, -1);
    int numcomps = 0;
    for(int i = 0; i < n; i++) {
        if(component[i] < 0) {
            dfs(i, numcomps++, minW);
        }
    }
    for(int i = 0; i < n; i++) {
        if(component[i] != component[loc[i]]) return false;
    }
    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    memset(loc, 0, sizeof(loc));
    fill(component,component + n, -1);
    for(int i = 0; i < n; i++) {
        int index;
        cin >> index;
        loc[i] = --index;
    }
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        Edge e1, e2;
        e1.d = b - 1;
        e1.w = w;
        e2.d = a - 1;
        e2.w = w;
        edges[a - 1].push_back(e1);
        edges[b - 1].push_back(e2);
    }
    int minW = 0;
    int maxW = 1000000001;
    while(minW != maxW) {
        int mid = (minW + maxW + 1) / 2;
        if(valid(mid)) minW = mid;
        else maxW = mid - 1; 
    } 
    if(minW > 1e9) minW = -1;
    cout << minW << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}



