#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> mydeque;

    mydeque.push_back(100);
    mydeque.push_back(200);
    mydeque.push_back(300);

    cout << "Popping out the elements in mydeque:";

    while(!mydeque.empty()) {
        cout << " " << mydeque.front();
        mydeque.pop_front();
    }
    cout << "\nThe final size of mydeque is " << int(mydeque.size());
    cout << '\n';
    return 0;
}