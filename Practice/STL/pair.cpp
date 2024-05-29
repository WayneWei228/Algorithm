#include <cstdio>
#include <iostream>
#include <utility>
#include <map>
using namespace std;



// pair 中元素访问
// int main() {
//     pair<string, int> p;
//     p.first = "haha";
//     p.second = 5;
//     cout << p.first << ' ' << p.second << endl;
//     p = make_pair("xixi", 55);
//     cout << p.first << " " << p.second << endl;
//     p = pair<string, int> ("heihei",555);
//     cout << p.first << " " << p.second << endl;
//     return 0;
// }


// 比较操作数  以first的大小作为标准
// int main() {
//     pair<int, int> p1(5,10);
//     pair<int, int> p2(5, 15);
//     pair<int, int> p3(10, 5);
//     if(p1 < p3) cout << "p1 < p3\n";
//     if(p1 <= p3) cout << "p1 <= p3\n";
//     if(p1 < p2) cout << "p1 < p2\n";
//     return 0;
// }


// int main() {
//     map<string, int> mp;
//     mp.insert(make_pair("heihei", 5));
//     mp.insert(pair<string, int> ("haha", 10));
//     for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
//         cout << it -> first << " " << it -> second << endl;
//     }
//     return 0;
}

