#include <cstdio>
#include <string>
#include <unordered_map>
#include <limits>
using namespace std;

char Buffer[20000];

struct Hexes {
    unordered_map<string, int> M;
    int ans2 = numeric_limits<int>::min();
    Hexes(string&& input) {
        M.emplace("n", 0);
        M.emplace("ne", 0);
        M.emplace("se", 0);
        M.emplace("s", 0);
        M.emplace("sw", 0);
        M.emplace("nw", 0);
        int pos = 0;
        while (true) {
            int nchars = -1;
            sscanf(input.c_str() + pos, "%[^,],%n", Buffer, &nchars);
            M[Buffer]++;
            int dis = Shorest();
            if (dis > ans2) ans2 = dis;
            if (nchars == -1) break;
            pos += nchars;
        }
    }


    int Shorest() {
        M["n"] -= M["s"];
        M["se"] -= M["nw"];
        M["sw"] -= M["ne"];
        M["s"] = 0;
        M["nw"] = 0;
        M["ne"] = 0;
        int Max = max(M["n"], max(M["se"], M["sw"]));
        int Min = min(M["n"], min(M["se"], M["sw"]));
        return Max - Min;
    }
};

struct Solution {
    void Solve() {
        scanf("%s", Buffer);
        string s = Buffer;
        Hexes a(move(s));
        printf("%d\n", a.Shorest());
        printf("%d\n", a.ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
