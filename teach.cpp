#include <iostream>
#include <map>
#include <string>
#include <vector>

/*
库
library

Method
"\n" = endl

int, double, bool, string, char

value:     6
          __, __, __, __, __,
index:     0,  1,  2,  3,  4,

array

*/
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    // cout << n;
    return n * factorial(n - 1);
}

int main() {
    // int array[5];

    // int i = 0;
    // while (i < 5) {
    //     array[i] = i - 1;
    //     cout << array[i] << " ";
    //     i += 1;
    // }
    // cout << endl;
    // for (int i = 0; i < 5; i++) {
    //     array[i] = i - 1;
    //     cout << array[i] << " ";
    // }
    // vector<int> a = {1, 2, 3};
    // a.push_back(1);
    // a.push_back(2);
    // // a.pop_back();
    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    // vector<int> arr = {1, 2, 3};

    // map<int, string> studentInfo;
    // studentInfo.insert(make_pair(3, "Jonathan"));
    // studentInfo.insert(make_pair(1, "Wayne"));
    // studentInfo.insert(make_pair(2, "Kelsey"));
    // for (auto i : studentInfo) {
    //     cout << i.first << " " << i.second << endl;
    // }

    // vector<vector<int>> arr2D;
    // arr2D.resize(3);
    // for (int i = 0; i < arr2D.size(); i++) {
    //     arr2D[i].resize(4);
    // }
    // cout << arr2D.size() << " " << arr2D[0].size() << endl;

    // int k = 1;
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         arr2D[i][j] = k;
    //         k++;
    //     }
    // }

    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << arr2D[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int c = Sum(5, 2);
    // cout << c << endl;

    // vector<int> arr;
    // arr.resize(10);
    // for (int i = 0; i < 10; i++) {
    //     arr[i] = i;
    // }
    // for (int i = 0; i < 10; i++) {
    //     for (int j = i + 1; j < 10; j++) {

    //     }
    // }

    int ans = factorial(3);
    cout << ans << endl;
    return 0;
}