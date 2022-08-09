#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
long long int N;

int main() {
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    string a;
    long long int leng,l;
    cin >> a >> N;
    leng = a.length();
    while (leng < N) {
        l = leng;
        while (l * 2 < N) {
            l *= 2;
        }
        N -= (l + 1);
        if (N == 0) N = l;
    }
    cout << a[N-1] << '\n';
    fclose(stdin);
    fclose(stdout);
}


// char parse(string s, long long int index) {
//     if (index < s.length()) {
//         return s[index];
//     }
//     long long int length = s.length();
//     while (length * 2 <= index) {
//         length *= 2;
//     }
//     if (length == index) {
//         return parse(s,length - 1);
//     }
//     return parse(s, index - length - 1);
// }

// int main() {
//     freopen("cowcode.in", "r", stdin);
//     freopen("cowcode.out", "w", stdout);
//     string a;
//     int leng,l;
//     cin >> a >> N;
//     cout << parse(a, N - 1) << '\n';
//     fclose(stdin);
//     fclose(stdout);
//     return 0;
// }