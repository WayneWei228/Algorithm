#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int R, S;
    cin >> R >> S;
    int ans = (R * 8 + S * 3) - 28;
    cout << ans << endl;
    return 0;
}