#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


struct Solution {
    int total1;
    int total2;
    void Solve1() {
        while(true) {
            string line;
            getline(cin, line);
            if(line == "") 
                break;

            int flag = 0;

            if(line.find("ab") == -1 && line.find("cd") == -1 && line.find("pq") == -1 && line.find("xy") == -1) {
                flag++;    
            }

            int cnt = 0;
            for(int i = 0; i < line.size(); i++) {
                if(line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') {
                    cnt++;
                }
            }
            if(cnt >= 3) {
                flag++;
            }
            for(int i = 0; i < line.size() - 1; i++) {
                if(line[i] == line[i + 1]) {
                    flag++;
                    break;
                }
            }
            if(flag == 3) {
                total1++;
            }
        }
        cout << total1 << endl;
    }

    void Solve2() {
        while(true) {
            string line;
            getline(cin, line);
            if(line == "") break;
            cout << "line  " << line << endl;
            int flag = 0;
            for(int i = 0; i < line.size() - 2; i++) {
                if(line[i] == line[i + 2]) {
                    flag++;
                    break;
                }
            }
            cout << "flag " << flag << endl;
            for(int i = 0; i < line.size() - 1; i++) {
                if(i + 2 >= line.size()) break;
                string temp;
                cout << "line[i] " << line[i] << " " << "line[i + 1] " << line[i + 1] << endl;
                temp.push_back(line[i]);
                temp.push_back(line[i + 1]);
                cout << "temp " << temp << endl;
                int pos = line.find(temp, i + 2);
                cout << "pos " << pos << endl;
                if(pos != -1) {
                    flag++;
                    break;
                }
            }
            if(flag == 2) {
                total2++;
            }
        }
        cout << total2 << endl;
    }
};

int main() {
    freopen("2015_5.txt", "r", stdin);
    // Solution().Solve1();
    Solution().Solve2(); 
    fclose(stdin);
    return 0;
}