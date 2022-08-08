#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

//用指针访问容器元素

// int main() {
//     vector<int> vi;
//     for(int i = 1; i <= 5; i++) {
//         vi.push_back(i);
//     }
//     // vi.begin() 为取vi的首元素地址，而it指向这个地址
//     vector<int>::iterator it = vi.begin();
//     for(int i = 0; i < 5; i++) {
//         printf("%d\n", *(it + i));
//     }
//     return 0;
// }

//另一种方法

// int main() {
//     vector<int> vi;
//     for(int i = 1; i < 5; i++) {
//         vi.push_back(i);
//     }
//     for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++) {
//         printf("%d\n", *it);
//     }
//     return 0;
// }


// push_back()
// int main() {
//     vector<int> vi;
//     for(int i = 1; i <= 3; i++) {
//         vi.push_back(i);
//     }
//     for(int i = 0; i < vi.size(); i++) {
//         printf("%d",vi[i]);
//     }
//     return 0;
// }


//pop_back()
// int main() {
//     vector<int> vi;
//     for(int i = 1; i <= 3; i++) {
//         vi.push_back(i);
//     }
//     vi.pop_back();
//     for(int i = 0; i < vi.size(); i++) {
//         printf("%d\n",vi[i]);
//     }
//     return 0;
// }


//size()
// int main() {
//     vector<int> vi;
//     for(int i = 1; i <= 3; i++) {
//         vi.push_back(i);
//     }
//     cout << vi.size() << endl;
//     return 0;
// }


//clear()
// int main() {
//     vector<int> vi;
//     for(int i = 1; i <= 3; i++) {
//         vi.push_back(i);
//     }
//     vi.clear();
//     cout << vi.size() << endl;
//     return 0;
// }



//insert()
// int main() {
//     vector<int> vi;
//     for(int i = 1; i <= 5; i++) {
//         vi.push_back(i);
//     }
//     vi.insert(vi.begin() + 2, -1);
//     for(int i = 0; i < vi.size(); i++) {
//         printf("%d\n",vi[i]); // 1 2 -1 3 4 5
//     }
//     return 0;
// }


//erase()
// int main() {
//     vector<int> vi;
//     for(int i = 5; i <= 9; i++) {
//         vi.push_back(i); // 5 6 7 8 9 
//     }
//     vi.erase(vi.begin() + 3);
//     for(int i = 0; i < vi.size(); i++) {
//         printf("%d\n",vi[i]); // 5 6 7 9
//     }
//     return 0;
// }


//erase(first,last) [first,last)
// int main() {
//     vector<int> vi;
//     for(int i = 5; i <= 9; i++) {
//         vi.push_back(i); // 5 6 7 8 9
//     }
//     vi.erase(vi.begin() + 1, vi.begin() + 4); 
//     for(int i = 0; i < vi.size(); i++) {
//         printf("%d\n",vi[i]); // 5 9
//     }
//     return 0;
// }



