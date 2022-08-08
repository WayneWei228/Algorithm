#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];

struct Disc {
    int number, pos, start;

    Disc(const string& input) {
        sscanf(input.c_str(),
               "Disc #%d has %d positions; at time=0, it is at "
               "position %d.",
               &number, &pos, &start);
    }

    Disc(int a, int b, int c) : number(a), pos(b), start(c){};
};

struct Solution {
    vector<Disc> Discs;
    bool canPass(int time, const Disc& disc) {
        return ((disc.start + time + disc.number) % disc.pos == 0);
    }

    bool canPassAll(int time, vector<Disc>& discs) {
        for (Disc& i : discs) {
            if (!canPass(time, i)) {
                return false;
            }
        }
        return true;
    }

    int Compute1() {
        int time = 1;
        while (true) {
            if (canPassAll(time, Discs)) {
                return time;
            }
            time++;
        }
    }

    void Solve() {
        while (scanf("%[^\n]\n", Buffer) == 1) {
            string s = Buffer;
            Discs.emplace_back(s);
        }
        printf("%d\n", Compute1());
        int num = Discs[int(Discs.size()) - 1].number + 1;
        Discs.emplace_back(Disc{num, 11, 0});
        printf("%d\n", Compute1());
    }
};

int main() {
    Solution().Solve();
    return 0;
}