#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    map<string, long> codelist;
    map<string, long>::iterator it;
    string city,state;
    cin >> n;
    string key;
    for(int i = 0; i < n; i++) {
        cin >> city >> state;
        if(city.substr(0.2).compare(state) != 0) {
            key = city.substr(0, 2) + state;
            if(codelist.find(key) == codelist.end()) {
                codelist[key] = 1;
            } else
            {
                codelist[key] += 1;
            }
        }
    }

    it = codelist.begin();
    long ret = 0;
    while (it != codelist.end())
    {
        string otherkey = it -> first.substr(2) + it -> first.substr(0, 2);
        if(codelist.find(otherkey) != codelist.end()) {
            ret += codelist[it -> first] * codelist[otherkey];
        }
        it++;
    }
    
    cout << ret/2 << endl;
    
    return 0;
    
}