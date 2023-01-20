#include <ctype.h>

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/*
AFB+888888 SC-4H-2 GDPE+9
*/

int main() {
    string instructions, sign, turns;
    while (true) {
        char input = getchar();
        if (input == EOF) break;

        if (isalpha(input) && turns != "") {
            cout << instructions << " " << sign << " " << turns << endl;
            instructions = "";
            sign = "";
            turns = "";
        }

        if (isalpha(input)) {
            instructions += input;
        } else if (input == '+') {
            sign = "tighten";
        } else if (input == '-') {
            sign = "loosen";
        } else if (isdigit(input)) {
            turns += input;
        }
    }
    cout << instructions << " " << sign << " " << turns << endl;
}