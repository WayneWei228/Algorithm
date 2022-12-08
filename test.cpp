#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double force = 8.18E-8;
    double mass = 9.1093837E-31;
    double dis = 92.0E-12;
    cout << sqrt(force * dis / mass) << endl;
    return 0;
}