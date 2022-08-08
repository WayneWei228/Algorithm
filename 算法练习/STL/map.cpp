#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

// map 容器内元素访问

// 1 通过下标

// int main() {
//     map<char,int> mp;
//     mp['c'] = 20;
//     mp['c'] = 30; //20被覆盖；
//     cout << mp['c'] << '\n';
//     return 0;
// }

// 2 通过迭代器访问

// int main() {
//     map<char,int> mp;
//     mp['m'] = 20;
//     mp['r'] = 30;
//     mp['a'] = 40;
//     for(map<char,int>::iterator it = mp.begin(); it != mp.end(); it++) {
//         cout << it->first << ' ' << it -> second << '\n';
//     }
//     return 0;
// }


// find()
 
// int main() {
//     map<char,int> mp;
//     mp['a'] = 1;
//     mp['b'] = 2;
//     mp['c'] = 3;
//     map<char,int>::iterator it = mp.find('b');
//     cout << it -> first << ' ' << it -> second << '\n';
//     return 0;
// }


// erase()

// erase(it)  删除单个元素
// int main() {
//     map<char,int> mp;
//     mp['a'] = 1;
//     mp['b'] = 2;
//     mp['c'] = 3;
//     map<char,int>::iterator it = mp.find('b');
//     mp.erase(it);
//     for(map<char,int>::iterator it = mp.begin(); it != mp.end(); it++) {
//         cout << it -> first << ' ' << it -> second << '\n';
//     }
//     return 0;
// }

// erase(key)
// int main() {
//     map<char,int> mp;
//     mp['a'] = 1;
//     mp['b'] = 2;
//     mp['c'] = 3;
//     mp.erase('b');
//     for(map<char,int>::iterator it = mp.begin(); it != mp.end(); it++) {
//         cout << it -> first << ' ' << it -> second << '\n';
//     }   
//     return 0;
// }


// mp.erase(first,second)
// 删除一个区间内所有元素
// int main() {
//     map<char,int> mp;
//     mp['a'] = 1;
//     mp['b'] = 2;
//     mp['c'] = 3;
//     map<char,int>::iterator it = mp.find('b');
//     mp.erase(it,mp.end());
//     for(map<char,int>::iterator it = mp.begin(); it != mp.end(); it++) {
//         cout << it -> first << ' ' << it -> second << '\n';  // a 1
//     }   
//     return 0;
// }


// size()
// int main() {
//     map<char,int> mp;
//     mp['a'] = 10;
//     mp['b'] = 20;
//     mp['c'] = 30;
//     cout << mp.size() << '\n';  // 3
//     return 0;
// }

// clear()
// int main() {
//     map<char,int> mp;
//     mp['a'] = 1;
//     mp['b'] = 2;
//     mp.clear();
//     cout << mp.size() << '\n';
//     return 0;
// }














