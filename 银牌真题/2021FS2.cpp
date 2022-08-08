#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
#define MAXN 100000

/*
5 3
101
85
100
46
95
*/


int N, K;
int arr[MAXN];
// int diff[MAXN];
set<int> q;
multiset<int> diff;

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a = (a + 11) / 12;
        q.insert(a);
    }
    // cout << endl;
    int len = q.size();
    int index = 1;
    for(auto it = q.begin(); it != q.end(); it++) {
        // cout << *it << endl;
        arr[index++] = *it;
    }

    int total = *q.rbegin();
    // cout << total << endl;
    
    // cout << endl;

    // for(int i = 1; i <= len; i++) {
    //     cout << arr[i] << endl;
    // }
    arr[0] = 0;
    
    // cout << endl;

    for(int i = 0; i < len; i++) {
        diff.insert(arr[i + 1] - arr[i]);
    }

    // for(auto it = diff.begin(); it != diff.end(); it++) {
    //     cout << *it << endl;
    // }

    multiset<int>::reverse_iterator rit;
    rit = diff.rbegin();
    ll i = 1;
    while(i < K) {
       total -= *rit - 1;
       rit++;
       i++;
    }

    total *= 12;
    cout << total << endl; 


}