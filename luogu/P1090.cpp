#include <bits/stdc++.h>
using namespace std;

//  3 
//  1 2 9 

int main() {
    int n;
    priority_queue<long long,vector<long long>,greater<long long> > q;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    long long ans = 0;
    while(!q.empty()) {
        long long num = 0;
        num += q.top();
        // cout << "first " << q.top();
        q.pop();
        num += q.top();
        // cout << " second " << q.top();
        q.pop();
        ans += num;
        // cout << " ans " << ans << endl;
        q.push(num);
        if(q.size() == 1) {
            break;
        }
    }

    // 1, 2, 9  // 3
    // 3, 9 // 12
    // 12

    cout << ans << endl;

    // 1, 2, 3, 4
    // 3, 3, 4
    // 6, 4

}