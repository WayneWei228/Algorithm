#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char Buffer[20000];

struct Solution {
    string Input;
    int Ans1 = 0;
    int Ans2 = 0;
    void Compute() {
        int no = 0;
        int level = 0;
        bool open = false;

        while (no < int(Input.size())) {
            switch (Input[no]) {
                case '{':
                    if (!open) {
                        ++level;
                        Ans1 += level;
                        no++;
                        break;
                    } else {
                        no++;
                        Ans2++;
                        break;
                    }
                case '}':
                    if (!open) {
                        --level;
                        ++no;
                        break;
                    } else {
                        ++no;
                        Ans2++;
                        break;
                    }
                case '!':
                    if (open) {
                        no += 2;
                        break;
                    }
                case '<':
                    if (open) {
                        Ans2++;
                    } else {
                        open = true;
                    }
                    ++no;
                    break;
                case '>':
                    if (!open) {
                        Ans2++;
                    } else {
                        open = false;
                    }
                    ++no;
                    break;
                default:
                    if (open) {
                        ++Ans2;
                    }
                    ++no;
                    break;
            }
        }
    }

    void Solve() {
        scanf("%[^\n]\n", Buffer);
        Input = Buffer;
        Compute();
        printf("%d\n", Ans1);
        printf("%d\n", Ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}