#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int N;

struct change {
    int pos;
    int cost;
    int hearing;
}arr[200005];

long long time(long long p) {
    long long sum_time = 0;
    for(int i = 1; i <= N; i++) {
        if(abs(arr[i].pos - p) - arr[i].hearing <= 0) continue;
        sum_time += (abs(arr[i].pos - p) - arr[i].hearing) * arr[i].cost;
    }
    //cout<<sum_time<<" "<<p<<endl;
    return sum_time;
    
}

long long binSearch(long long low, long long high)
{
    if (low == high)
        return low;
    long long mid = (low + high ) / 2;
    if (time(mid) < time(mid+1)) {
        return binSearch(low, mid);
    } 
    else if(low==mid){
     return high;
    } 
    else {
        return binSearch(mid, high);
    }
}

// long long binSearch(long long low, long long high)
// {
//     if (low == high)
//         return low;
//     long long mid = (low + high ) / 2;
//     if (time(mid) < time((mid+high)/2)) {
//         return binSearch(low, mid);
//     } else if(low == mid) {
//         return high;
//     }
//     else {
//         return binSearch(mid, high);
//     }
// }

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i].pos >> arr[i].cost >> arr[i].hearing;
    }
    long long ans = time(binSearch(0,1000000001));
    cout << ans << endl;
    return 0;
    // long long ans = 9999999999999999;
    // for(int i = 0; i <= 2002; i++) {
    //     long long temp = time(i);
    //     ans = min(ans, temp);
    // }
    // cout << ans << endl;
    // return 0;
}
//
// 3
// 6 8 3
// 1 4 1
// 14 5 2