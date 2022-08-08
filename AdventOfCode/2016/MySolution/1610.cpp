#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

/*
value 5 goes to bot 2
bot 2 gives low to bot 1 and high to bot 0
value 3 goes to bot 1
bot 1 gives low to output 1 and high to bot 0
bot 0 gives low to output 2 and high to output 0
value 2 goes to bot 2
*/

char Buffer0[80], Buffer1[80];

struct Robot {
    vector<int> have;
    int give[2];

    bool operator==(const Robot& that) const {
        return that.give[0] == give[0] && that.give[1] == give[1];
    }
};


struct Solution {
    unordered_map<int, Robot> Robots;
    unordered_map<int, int> Output;
    int ans1 = 0;

    void Do(const Robot& input) {
        Robot no(input);
        if (no.have.size() != 2) return;
        if (no.have[0] > no.have[1]) {
            swap(no.have[0], no.have[1]);
        }
        if (no.have[0] == 17 && no.have[1] == 61) {
            for (auto& i : Robots) {
                if (i.second == no) {
                    ans1 = i.first;
                }
            }
        }
        for (int i = 0; i < 2; ++i) {
            if (no.give[i] >= 0) {
                Robots[no.give[i]].have.emplace_back(no.have[i]);
                Do(Robots[no.give[i]]);
            } else {
                Output[-(no.give[i] + 1)] = no.have[i];
            }
        }
    }

    void Solve() {
        while (true) {
            int a, b, c;
            if (scanf("value %d goes to bot %d\n", &a, &b) == 2) {
                Robots[b].have.emplace_back(a);
            } else if (scanf("bot %d gives low to %s %d and high to %s %d\n", 
                &a, Buffer0, &b, Buffer1, &c) == 5) {
                string s1 = Buffer0;
                if (s1 == "output") {
                    b = -b - 1;
                }
                string s2 = Buffer1;
                if (s2 == "output") {
                    c = -c - 1;
                }           
                Robots[a].give[0] = b;
                Robots[a].give[1] = c;
            } else {
                break;
            }
        }

        for (auto& i : Robots) {
            if (int(i.second.have.size()) == 2) {
                Do(i.second);
            }
        }
        printf("%d\n", ans1);
        int ans2 = Output[0] * Output[1] * Output[2];
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}