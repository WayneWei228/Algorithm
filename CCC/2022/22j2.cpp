#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    bool isGoldTeam = true;
    int goldPlayer = 0;
    for (int i = 1; i <= N; i++) {
        int scored, fouled;
        cin >> scored >> fouled;
        int points = scored * 5 - fouled * 3;
        if (points <= 40) {
            isGoldTeam = false;
        } else {
            goldPlayer = goldPlayer + 1;
        }
    }
    cout << goldPlayer;
    if (isGoldTeam) {
        cout << '+' << endl;
    }
    /*
    line 20 ~ 23 equals to
    cout << goldPlayer << ((isGoldTeam == true) ? "+" : "") << endl;
    */

}