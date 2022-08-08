#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
/*
turn on 489,959 through 759,964
turn off 820,516 through 871,914
toggle 756,965 through 812,992

turn on 0,0 through 2,2
turn off 1,1 through 2,2
toggle 0,0 through 2,2
*/
struct Coordinate {
    int x, y;
};

struct Solution {
    Coordinate Turn_on_first(string line) {
        Coordinate ret;
        int pos = line.find(",");
        string temp1 = line.substr(8, pos);
        ret.x = stoi(temp1, 0, 10);
        int pos2 = line.find(" through");
        string temp2 = line.substr(pos + 1, pos2);
        ret.y = stoi(temp2, 0, 10);
        return ret;
    }

    Coordinate Turn_on_off_Second(string line) {
        Coordinate ret;
        int pos = line.rfind(",");
        int begin = line.find("through");
        begin += 8;
        string temp1 = line.substr(begin, pos);
        string temp2 = line.substr(pos + 1);
        ret.x = stoi(temp1, 0, 10);
        ret.y = stoi(temp2, 0, 10);
        return ret;
    }

    Coordinate Turn_off_first(string line) {
        Coordinate ret;
        int pos = line.find(",");
        string temp1 = line.substr(9, pos);
        ret.x = stoi(temp1, 0, 10);
        int pos2 = line.find(" through");
        string temp2 = line.substr(pos + 1, pos2);
        ret.y = stoi(temp2, 0, 10);
        return ret;
    }

    Coordinate Toggle_first(string line) {
        Coordinate ret;
        int pos = line.find(",");
        string temp1 = line.substr(7, pos);
        ret.x = stoi(temp1, 0, 10);
        int pos2 = line.find(" through");
        string temp2 = line.substr(pos + 1, pos2);
        ret.y = stoi(temp2, 0, 10);
        return ret;
    }


    void Solve1() {
        bool grid[1000][1000] = {0};
        while(true) {
            string line;
            getline(cin, line);
            if(line == "") break;
            Coordinate a, b;
            if(line.find("turn on") != -1) {
                a = Turn_on_first(line);
                cout << a.x << " " << a.y << endl;
                b = Turn_on_off_Second(line);
                cout << b.x << " " << b.y << endl;

                for(int i = a.x; i <= b.x; i++) {
                    for(int j = a.y; j <= b.y; j++) {
                        grid[i][j] = 1;
                    }
                }
            } else if(line.find("turn off") != -1) {
                a = Turn_off_first(line);
                b = Turn_on_off_Second(line);
                cout << a.x << " " << a.y << endl;
                cout << b.x << " " << b.y << endl;

                for(int i = a.x; i <= b.x; i++) {
                    for(int j = a.y; j <= b.y; j++) {
                        grid[i][j] = 0;
                    }
                }
            } else {
                a = Toggle_first(line);
                b = Turn_on_off_Second(line);
                cout << a.x << " " << a.y << endl;
                cout << b.x << " " << b.y << endl;

                for(int i = a.x; i <= b.x; i++) {
                    for(int j = a.y; j <= b.y; j++) {
                        if(grid[i][j]) {
                            grid[i][j] = 0;
                        } else {
                            grid[i][j] = 1;
                        }
                    }
                }
            }
        }
        int total;
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++) {
                if(grid[i][j]) {
                    total++;
                }
            }
        }
        cout << total << endl;
    }

    void Solve2() {
        int grid[1000][1000] = {0};
        while(true) {
            string line;
            getline(cin, line);
            if(line == "") break;
            Coordinate a, b;
            if(line.find("turn on") != -1) {
                a = Turn_on_first(line);
                cout << a.x << " " << a.y << endl;
                b = Turn_on_off_Second(line);
                cout << b.x << " " << b.y << endl;

                for(int i = a.x; i <= b.x; i++) {
                    for(int j = a.y; j <= b.y; j++) {
                        grid[i][j]++;
                    }
                }
            } else if(line.find("turn off") != -1) {
                a = Turn_off_first(line);
                b = Turn_on_off_Second(line);
                cout << a.x << " " << a.y << endl;
                cout << b.x << " " << b.y << endl;

                for(int i = a.x; i <= b.x; i++) {
                    for(int j = a.y; j <= b.y; j++) {
                        if(grid[i][j] > 0)
                            grid[i][j]--;
                    }
                }
            } else {
                a = Toggle_first(line);
                b = Turn_on_off_Second(line);
                cout << a.x << " " << a.y << endl;
                cout << b.x << " " << b.y << endl;

                for(int i = a.x; i <= b.x; i++) {
                    for(int j = a.y; j <= b.y; j++) {
                        grid[i][j] += 2;
                    }
                }
            }
        }
        int total;
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++) {
                total += grid[i][j];
            }
        }
        cout << total << endl;
    }
};

int main() {
    freopen("2015_6.txt", "r", stdin);
    // Solution().Solve1();
    Solution().Solve2();
    fclose(stdin);
    return 0;
}