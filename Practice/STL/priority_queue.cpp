#include <iostream>
#include <string>
#include <queue>
using namespace std;

//priority_queue容器内元素的访问
// int main() {
//     priority_queue<int> q;
//     q.push(3);
//     q.push(4);
//     q.push(1);
//     cout << q.top() << '\n';
//     return 0;
// }

// push() top() pop()
// int main() {
//     priority_queue<int> q;
//     q.push(3);
//     q.push(4);
//     q.push(1);
//     cout << q.top() << '\n';  // 4
//     q.pop();
//     cout << q.top() << '\n';  // 3
//     return 0;
// }

//empty()
// int main() {
//     priority_queue<int> q;
//     if(q.empty() == true) {
//         cout << "Empty\n";
//     } else
//     {
//         cout << "Not Empty\n";
//     }
//     q.push(1);
//     if(q.empty() == true) {
//         cout << "Empty\n";
//     } else
//     {
//         cout << "Not Empty\n";
//     }
//     //Empty
//     //Not Empty
//     return 0;
// }

//size()
// int main() {
//     priority_queue<int> q;
//     q.push(3);
//     q.push(4);
//     q.push(1);
//     cout << q.size() << '\n';  // 3
//     return 0;
// }

// 基础数据类型的优先级设置;
// int main() {
//     priority_queue<int, vector<int>, greater<int> > q;
//     q.push(3);
//     q.push(4);
//     q.push(1);
//     cout << q.top() << '\n';  // 1
//     return 0;
// }

// 结构体的优先级设置
struct fruit
{
    string name;
    int price;
    friend bool operator < (fruit f1, fruit f2) {
        return  f1.price < f2.price;
    }
}f1,f2,f3;

int main() {
    priority_queue<fruit> q;
    f1.name = "peach";
    f1.price = 3;
    f2.name = "pear";
    f2.price = 4;
    f3.name = "apple";
    f3.price = 1;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout << q.top().name << " " << q.top().price << endl;
    return 0;
}
