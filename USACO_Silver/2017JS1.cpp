#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 10005

int N, T;
int A[MAXN];
bool size(int k)
{
    int time = 0;
    priority_queue<int, vector<int>, greater<int> > q;
    if (k > N) return true;
    for (int i = 0; i < N; i++) {
        if (q.size() == k) {
            time = q.top();
            q.pop();
        }
        q.push(time + A[i]);
    }
    while (q.size() > 1) {
        q.pop();
    }
    time = q.top();
    if (time > T) {
        return false;
    } else {
        return true;
    }
}
int binSearch(int low, int high)
{
    if (low == high)
        return low;
    if (low + 1 == high) {
        if (size(low)) return low;
        return high;
    }
    int mid = (low + high) / 2;
    if (size(mid))
        return binSearch(low, mid);
    else
        return binSearch(mid + 1, high);
}

int main()
{
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << binSearch(0, 100000) << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
