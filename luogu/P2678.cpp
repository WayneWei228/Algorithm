#include <bits/stdc++.h>
using namespace std;

long long L, N, M;
vector<long long> vi;

bool isValid(long long len) {
    long long total_delete = 0;
    long long start = 0;
    long long next = 0;
    // if(len > L) return false;
    while(next < vi.size()) {
        next++;
        // cout << "diff " << vi[next] - vi[start] << endl;
        // cout << vi[next] << " " << vi[start] << endl;
        if(next < vi.size() && vi[next] - vi[start] < len) {
            total_delete++;
        } else {
            start = next;
        }
    }
    // cout << "total_delete " << total_delete << endl; 
    if(total_delete > M) {
        return false;
    } else {
        return true;
    }

    // if(total_delete <= M) {
    //     return true;
    // } else {
    //     return false;
    // }
}

int main() {
    cin >> L >> N >> M;
    vi.push_back(0);
    for(long long i = 0; i < N; i++) {
        long long a;
        cin >> a;
        vi.push_back(a);
    }
    vi.push_back(L);

    // for(int i = 0; i < vi.size(); i++) {
    //     cout << vi[i] << " ";
    // }
    // cout << endl;
    long long l = 0, r = L + 1;   
    
    // cout << isValid(5) << endl;
    long long ans = 0;
    // cout << isValid(4) << endl;
    while(l <= r) {
        // cout << l << " " << r << endl;
        long long mid = (l + r) / 2;
        if(isValid(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}