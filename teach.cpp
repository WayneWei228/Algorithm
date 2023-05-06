#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int AddNumber(int a, int b) {
    int x = a + b;
    return x;
}

int AddNumber(int a, int b, int c) {
    int x = a + b + c;
    return x;
}

int main() {
    // printf("Hello World");

    // int x;
    // cin >> x;
    // if (x > 90) {
    //     cout << "Grade A" << endl;
    // } else {
    //     cout << "Fail!" << endl;
    // }
    // while (x < 10) {
    //     cout << x << endl;
    //     x = x + 1;
    // }
    // int a, b;
    // cin >> a >> b;
    // int sum = AddNumber(AddNumber(a, b, 30), 30);
    // double a = 10.01;
    // int arr[3];
    // arr[0] = 1;
    // arr[1] = 2;
    // arr[2] = 50;
    // int index = 0;
    // for (int i = 0; i < 4; i++) {
    //     while (index < 3) {
    //         cout << arr[index] << endl;
    //         index = index + 1;
    //     }
    // }
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    // arr: 10 20
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }


    // cout << sum << endl;
    // cout << x << endl;
    return 0;
}