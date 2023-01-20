#include <iostream>
#include <vector>
using namespace std;
void sf(int number, int factor = 2) {
    if (number < 2) return;
    if (number % factor == 0) {
        cout << factor << " ";
        sf(number / factor, factor);
    } else
        sf(number, factor + 1);
}

int main() {
    sf(10);
    return 0;
}