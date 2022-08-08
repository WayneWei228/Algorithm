#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    array<int,8> foo = {1,2,4,8,16,32,64,128};

    if(none_of(foo.begin(), foo.end(), [](int i) {return i < 0;})) {
        cout << "There are no negative elements in the range.\n";
    }
    bool flag=false;
    for(int i=0;i<foo.size();i++)
    {
           if(foo[i]<0){
               //cout << "There are some negative elements in the range.\n";
               flag=true;
               break;
               

           }
    }   
    if(!flag) {
        cout << "There are no negative elements in the range.\n";

    } 
    return 0;
}