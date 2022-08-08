#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

// set 容器内元素的访问
// int main() {
//     set<int> st;
//     st.insert(3);
//     st.insert(5);
//     st.insert(2);
//     st.insert(3);
//     for(set<int>::iterator it = st.begin(); it != st.end(); it++) {
//         printf("%d",*it); // 2 3 5
//     }
//     printf("\n");
//     return 0;
// }


//insert()  find()
// int main() {
//     set<int> st;
//     for(int i = 1; i <= 3; i++) {
//         st.insert(i);
//     }
//     set<int>::iterator it = st.find(2);
//     printf("%d\n",*it);
//     // printf("%d\n", *(st.find(2)));
//     return 0;
// } 


//erase()
// int main() {
//     set<int> st;
//     st.insert(100);
//     st.insert(200);
//     st.insert(100);
//     st.insert(300);
//     st.erase(st.find(100));
//     st.erase(st.find(200));
//     for(set<int>::iterator it = st.begin(); it != st.end(); it++) {
//         printf("%d\n",*it); // 300
//     }
//     return 0;
// }

// st.erase(value)
// int main() {
//     set<int> st;
//     st.insert(100);
//     st.insert(200);
//     st.erase(100);
//     for(set<int>::iterator it = st.begin(); it != st.end(); it++) {
//         cout << *it << endl;
//     }
//     return 0;
// }


// st.earse(first,last)
// int main() {
//     set<int> st;
//     st.insert(20);
//     st.insert(10);
//     st.insert(40);
//     st.insert(30);
//     set<int>::iterator it = st.find(30);
//     st.erase(it,st.end());
//     for(it = st.begin(); it != st.end(); it++) {
//         printf("%d\n",*it); // 10 20
//     }
//     return 0;
// }


// size()
// int main() {
//     set<int> st;
//     st.insert(2);
//     st.insert(5);
//     st.insert(4);
//     cout << st.size() << endl;  // 3
//     return 0;
// }


//clear()
// int main() {
//     set<int> st;
//     st.insert(2);
//     st.insert(5);
//     st.insert(4);
//     st.clear();
//     cout << st.size() << endl;  // 0
//     return 0;
// }
