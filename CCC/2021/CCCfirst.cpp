#include <cstdio>
#include <iostream>
using namespace std;

int N;
double hight[10005];
double width[10005];

int main() {
    cin >> N;
    for(int i = 1; i <= N + 1; i++) {
        cin >> hight[i];
    }
    for(int i = 1; i <= N; i++) {
        cin >> width[i];
    }
    double area = 0;
    int index = 1;
    while(index <= N) {
        area += width[index] * (hight[index] + hight[index + 1]) / 2;
        index++;
    }
    cout << area << endl;
    return 0;
}