#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

#define PI 3.14159265

ll read() {
    ll a = 0, b = getchar(), c = 1;
    while (!isdigit(b)) c = b == '-' ? -1 : 1, b = getchar();
    while (isdigit(b)) a = a * 10 + b - '0', b = getchar();
    return a * c;
}
vector<pair<long double, int> > a;
int n, ansx, ansy;
long double sum = 1e5;
int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        int x = read(), y = read();
        a.push_back({atan2(y, x), i + 1});
    }
    sort(a.begin(), a.end());
    a.push_back(a[0]);
    for (int i = 0; i < n; i++) {
        long double x = a[i + 1].first - a[i].first;
        cout << a[i].first << endl;
        if (x < 0) x += 2 * acos(-1);
        if (x < sum)
            sum = x, ansx = a[i].second, ansy = a[i + 1].second;
    }
    printf("%d %d\n", ansx, ansy);
    return 0;
}