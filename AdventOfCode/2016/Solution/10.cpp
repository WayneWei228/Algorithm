#include <cstdio>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct Bot {
    int V[2], To[2], VSize = 0;

    Bot& AddV(int value) {
        V[VSize++] = value;
        return *this;
    }
};

char Buffer[80], Buffer0[80], Buffer1[80];

struct Solution {
    unordered_map<int, Bot> Bots;
    unordered_map<int, int> Output;
    int Answer1, Answer2 = 1;

    void Run(int no, Bot& bot) {
        if (bot.VSize != 2) return;
        bot.VSize = 3;
        if (bot.V[1] < bot.V[0]) swap(bot.V[0], bot.V[1]);
        if (bot.V[0] == 17 && bot.V[1] == 61) Answer1 = no;
        for (int i = 0; i < 2; ++i) {
            if (bot.To[i] < 0) {
                Output[~bot.To[i]] = bot.V[i];
            } else {
                Run(bot.To[i], Bots[bot.To[i]].AddV(bot.V[i]));
            }
        }
    }

    void Solve() {
        while (scanf("%[^\n]\n", Buffer) == 1) {
            string s = Buffer;
            int value, bot0, bot1, bot2;
            if (sscanf(                         //
                    s.c_str(),                  //
                    "value %d goes to bot %d",  //
                    &value, &bot0) == 2) {
                Bots[bot0].AddV(value);
            }
            if (sscanf(
                    s.c_str(),                                      //
                    "bot %d gives low to %s %d and high to %s %d",  //
                    &bot0, Buffer0, &bot1, Buffer1, &bot2) == 5) {
                string s0 = Buffer0, s1 = Buffer1;
                if (s0 == "output") bot1 = ~bot1;
                Bots[bot0].To[0] = bot1;
                if (s1 == "output") bot2 = ~bot2;
                Bots[bot0].To[1] = bot2;
            }
        }
        for (auto& i : Bots) Run(i.first, i.second);
        for (int i = 0; i < 3; ++i) Answer2 *= Output[i];
        printf("%d\n", Answer1);
        printf("%d\n", Answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
