#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

double cal(double end, double begin) {
    return (end - begin) / ((end + begin) / 2);
}

int main() {
    double q = cal(27, 40);
    double p = 12 / 100.0;
    cout << q / p << endl;
}