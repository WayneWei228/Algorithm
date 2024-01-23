#include <iostream>
#include <vector>
using namespace std;

struct Solution{

    int n, k;

    void Solve() {
        cin >> n >> k;
        bool head = true;
        for (int i = 0; i < k; i++) {
            if (head) {
               cout << i + 1;
               head = false;
            } else {
                cout << " " << i + 1;
            }
        }
        int N = n;
        for (int i = k; i < N; i++) {
            if (head) {
                cout << n--;
                head = false;
            } else {
                cout << " " << n--;
            }
        }
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        Solution().Solve();
    }
}