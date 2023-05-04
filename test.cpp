#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const long double Kw = 1e-14;

double getOther(double in) {
    return Kw / in;
}

double getX(double K, double divisor) {
    return sqrt(K / divisor);
}

double getP(double in) {
    return -log10(in);
}

double getConcentration(double ph) {
    return pow(10, -ph);
}

double getOtherP(double in) {
    return 14 - in;
}

double getmol(double volumeInML, double molarity) {
    return volumeInML / 1000.0 * molarity;
}

int main() {
    // double volumeBase = 20;
    // double volumeTotal = (volumeBase + 50) / 1000.0;
    // double c_salt = (volumeBase / 1000.0 * 0.1) / volumeTotal;
    // double c_base = (50 / 1000.0 * 0.1 - getmol(volumeBase, 0.1)) / volumeTotal;
    // double ans = getP(1.8E-5) + log10(c_salt / c_base);
    // cout << ans << endl;
    double ans = sqrt(5.56E-10 * 5.0E-2);
    cout << ans << endl;
    cout << 14 - getP(ans) << endl;
};