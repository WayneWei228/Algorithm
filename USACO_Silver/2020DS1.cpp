#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100000


int N;
int d[MAXN];

int main() {
    cin >> N;
    int a, b;
    for(int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        a--, b--;
        d[a]++, d[b]++;
    }
    int ans = N - 1;
    for(int i = 0; i < N; i++) {
        if(d[i] > 1 || i == 0) { // 判断是否为父节点
            int children = d[i];
            if(i != 0) {
                children--;
            }
            int day = 0;
            int cow_num = 1;
            while(cow_num < children + 1) {
                day++;
                cow_num *= 2;
            }
            ans += day;
        }
    }
    cout << ans << endl;
    return 0;
}