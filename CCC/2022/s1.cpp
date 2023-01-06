#include <cstdio>
#include <iostream>
using namespace std;

/*
There is also a clever extremely quick solution that involves extending
the table listed above for the first subtask to N = 20 and considering
the quotient and remainder when N is divided by 20.*/
int main() {
    int N;
    cin >> N;
    int fours = 0;
    int flag = false;
    int i = 0;
    while (N - (i * 5) >= 0) {
        if ((N - (i * 5)) % 4 == 0) {
            fours = (N - (i * 5)) / 4;
            flag = true;
            break;
        }
        i++;
    }
    if (!flag) {
        cout << 0 << endl;
        return 0;
    }
    cout << fours / 5 + 1 << endl;
    return 0;
}