#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

// 通过下标访问

// int main() {
//     string str = "abcd";
//     for(int i = 0; i < str.length(); i++) {
//         printf("%c",str[i]); // abcd
//     }
//     printf("\n");
//     return 0;
// }

// 输入输出

// 1) cin cout
// int main() {
//     string str;
//     cin >> str;
//     cout << str;
//     return 0;
// }


// 2) printf
// int main() {
//     string str = "abcd";
//     printf("%s\n",str.c_str()); // abcd
//     return 0;
// }


// 迭代器
// int main() {
//     string str = "abcd";
//     for(string::iterator it = str.begin(); it != str.end(); it++) {
//         printf("%c", *it);
//     }
//     return 0;
// }

// it 可加减
// int main() {
//     string str = "abcd";
//     string::iterator it = str.begin();
//     for(int i = 0; i < 4; i++) {
//         printf("%c",*(it + i));
//     }
//     printf("\n");
//     return 0;
// }


// operator +=
// 将两个string 直接直接拼接起来
// int main() {
//     string str1 = "abc", str2 = "xyz", str3;
//     str3 = str1 + str2;
//     str1 += str2;
//     cout << str1 << endl;
//     cout << str3 << endl;
//     return 0;
// }


// campare operator
//字典序比较大小
// int main() {
//     string str1 = "aa", str2 = "aaa", str3 = "abc", str4 = "xyz";
//     if(str1 < str2) printf("ok1\n");
//     if(str1 != str3) printf("ok2\n");
//     if(str4 >= str3) printf("ok3\n");
//     return 0;
// }


// length() / size()


//insert()
// 1) insert(pos,string)
// int main() {
//     string str = "abcde", str2 = "xyz";
//     str.insert(3,str2);
//     cout << str << endl;
//     return 0;
// }

// 2) insert(it,it2,it3)
// int main() {
//     string str = "abcxyz", str2 = "opq";
//     str.insert(str.begin() + 3, str2.begin(), str2.end());
//     cout << str << endl;  // abcopqxyz
//     return 0;
// }


//erase()

//删除单个

// int main() {
//     string str = "abcdefg";
//     str.erase(str.begin() + 4);
//     cout << str << endl; // abcdfg
//     return 0;
// }

// 删除一个区间 1) str.erase(first,last)

// int main() {
//     string str = "abcdefg";
//     str.erase(str.begin() + 2, str.end() - 1);
//     cout << str << endl; // abg
//     return 0;
// }

// 2) str.erase(pos,length)

// int main() {
//     string str = "abcdefg";
//     str.erase(3,2);
//     cout << str << endl; //abcfg
//     return 0;
// }

//clear()
// int main() {
//     string str = "abcd";
//     str.clear();
//     cout << str.length();
//     return 0;
// }


// substr(pos,len) 返回从 pos 开始 长度为len的字串, O(len)
// int main() {
//     string str = "Thank you for your smile.";
//     cout << str.substr(0,5) << endl;  // Thank
//     cout << str.substr(14,4) << endl;  // your
//     cout << str.substr(19,5) << endl; //smile
//     return 0;
// }


// string::npos
// int main() {
//     if(string::npos == -1) {
//         cout << "-1 is true." << endl;
//     }
//     if(string::npos == 4294967295) {
//         cout << "4294967295 is also true." << endl;
//     }
//     return 0;
// }



// find()

// str.find(str2) 当str2 是str的子串时， 返回其在str中第一次出现的位置
// str.find(str2,pos)，从str的pos号位开始匹配str2， 返回值与上相同
// int main() {
//     string str = "Thank you for your smile.";
//     string str2 = "you";
//     string str3 = "me";
//     if(str.find(str2) != string::npos) {
//         cout << str.find(str2) << endl;
//     }
//     if(str.find(str2,7) != string::npos) {
//         cout << str.find(str2,7) << endl;
//     }
//     if(str.find(str3) != string::npos) {
//         cout << str.find(str3) << endl;
//     } else
//     {
//         cout << "I know there is no position for me." << endl;
//     }
//     return 0;
// }


// replace()

// int main() {
//     string str = "Maybe you will turn around.";
//     string str2 = "will not";
//     string str3 = "surely";
//     cout << str.replace(10,4,str2) << endl;
//     cout << str.replace(str.begin(),str.begin() + 5,str3) << endl;
//     return 0;
// }