#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    deque<int> requests;
    int maxServersNeeded = 0;
    for (int i = 0; i < n; i++) {
        int newRequest;
        cin >> newRequest;
        while (!requests.empty() && requests[0] + 999 < newRequest) {
            requests.pop_front();
        }

        requests.push_back(newRequest);
        maxServersNeeded = max(maxServersNeeded, (int(requests.size()) + k - 1) / k);
    }
    cout << maxServersNeeded << endl;
    return 0;
}