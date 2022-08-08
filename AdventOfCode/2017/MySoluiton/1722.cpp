#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[80];

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Coordinate {
    int x, y;
    char state = '.';
};

uint64 Hash(int x, int y) { return Fingerprint(x) + y; }

int Next[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Node {
    int x, y;
    int dir;
};

struct Solution {
    unordered_map<uint64, Coordinate> input;
    unordered_map<uint64, Coordinate> M;
    unordered_map<uint64, Coordinate> M2;

    int xSize, ySize;
    int ans1 = 0, ans2 = 0;
    Node no;

    Node& Compute2(Node& n) {
        uint64 h = Fingerprint(n.x) + n.y;
        auto it = M2.find(h);
        if (it != M2.end()) {
            if (it->second.state == '#') {
                it->second.state = 'F';
                n.dir = (n.dir + 1) % 4;
            } else if (it->second.state == 'W') {
                it->second.state = '#';
                ans2++;
            } else if (it->second.state == 'F') {
                M2.erase(it);
                n.dir = (n.dir + 2) % 4;
            }
        } else {
            if (--n.dir == -1) n.dir = 3;
            M2.emplace((Fingerprint(n.x) + n.y),
                      Coordinate{n.x, n.y, 'W'});
        }
        n.x += Next[n.dir][0];
        n.y += Next[n.dir][1];
        return n;
    }

    Node& Compute1(Node& n) {
        uint64 h = Fingerprint(n.x) + n.y;
        auto it = M.find(h);
        if (it != M.end()) {  // #
            n.dir = (n.dir + 1) % 4;
            M.erase(it);
        } else {  // .
            if (--n.dir == -1) n.dir = 3;
            M.emplace((Fingerprint(n.x) + n.y),
                      Coordinate{n.x, n.y, '#'});
            ans1++;
        }
        n.x += Next[n.dir][0];
        n.y += Next[n.dir][1];
        return n;
    }

    void Solve() {
        int i = 0;
        int k = 0;
        while (scanf("%s", Buffer) == 1) {
            string s = Buffer;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '#') {
                    uint64 h = Hash(i, j);
                    input.emplace(h, Coordinate{i, j, '#'});
                    k++;
                }
            }
            ySize = int(s.size());
            i++;
        }
        xSize = i;
        M = input;
        M2 = input;
        
        no.x = xSize / 2;
        no.y = ySize / 2;
        no.dir = 0;
        for (int i = 0; i < 10000; i++) {
            Compute1(no);
        }
        printf("%d\n", ans1);

        no.x = xSize / 2;
        no.y = ySize / 2;
        no.dir = 0;
        for (int i = 0; i < 10000000; i++) {
            Compute2(no);
        }
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}