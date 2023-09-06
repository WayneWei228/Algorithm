#include <iostream>
using namespace std;

int main() {
    int count[1000005] = {0};
    int N;
    int ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (count[x] == 0) {
            count[x - 1]++;
        } else {
            count[x]--;
            count[x - 1]++;
        }
    }
    for (int i = 0; i < N + 1; i++) {
        ans += count[i];
    }
    cout << ans << endl;
    return 0;
}
