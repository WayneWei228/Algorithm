#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer[200];

int Next[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct Cart {
    int y, x;
    int dir;
    int cnt;

    uint64 Hash() { return Fingerprint(y) + x; }

    void Move() {
        y += Next[dir][0];
        x += Next[dir][1];
    }

    bool operator<(const Cart& that) const {
        if (y != that.y) return y < that.y;
        return x < that.x;
    }

    bool operator==(const Cart& that) const {
        return that.x == x && that.y == y;
    }
};

struct Solution {
    vector<string> map;
    vector<Cart> M;
    Cart ans1;
    bool crash = false;

    void ChangeDir(Cart& cart) {
        switch (map[cart.y][cart.x]) {
            case '+': {
                cart.cnt += 1;
                int n = cart.cnt % 3;
                if (n == 0) {
                    cart.dir = (cart.dir + 1) % 4;
                } else if (n == 1) {
                    cart.dir = (cart.dir + 3) % 4;
                }
                break;
            }
            case '/': {
                if (cart.dir == 0) {
                    cart.dir = 1;
                } else if (cart.dir == 1) {
                    cart.dir = 0;
                } else if (cart.dir == 2) {
                    cart.dir = 3;
                } else if (cart.dir == 3) {
                    cart.dir = 2;
                }
                break;
            }
            case '\\': {
                if (cart.dir == 0) {
                    cart.dir = 3;
                } else if (cart.dir == 1) {
                    cart.dir = 2;
                } else if (cart.dir == 2) {
                    cart.dir = 1;
                } else if (cart.dir == 3) {
                    cart.dir = 0;
                }
                break;
            }
            default:
                break;
        }
    }

    void Solve() {
        while (scanf("%[^\n]%*c", Buffer) == 1) {
            string s = Buffer;
            map.emplace_back(s);
        }
        for (int y = 0; y < map.size(); y++) {
            for (int x = 0; x < map[0].size(); x++) {
                switch (map[y][x]) {
                    case '^':
                        M.emplace_back(Cart{y, x, 0, 0});
                        break;
                    case '>':
                        M.emplace_back(Cart{y, x, 1, 0});
                        break;
                    case 'v':
                        M.emplace_back(Cart{y, x, 2, 0});
                        break;
                    case '<':
                        M.emplace_back(Cart{y, x, 3, 0});
                        break;
                    default:
                        break;
                }
            }
        }

        while (M.size() > 1) {
            unordered_set<uint64> visited;
            vector<Cart> Erase;
            for (auto& cart : M) {
                if (visited.count(cart.Hash())) {
                    if (!crash) {
                        ans1 = cart;
                        crash = true;
                    }
                    Erase.emplace_back(cart);
                    continue;
                }
                cart.Move();
                auto res = visited.emplace(cart.Hash()).second;
                if (!res) {
                    Erase.emplace_back(cart);
                    if (!crash) {
                        ans1 = cart;
                        crash = true;
                    }
                }
                ChangeDir(cart);
            }
            sort(M.begin(), M.end());
            for (const auto& c : Erase) {
                for (int i = 0; i < int(M.size());) {
                    if (M[i] == c) {
                        M.erase(M.begin() + i);
                    } else {
                        i++;
                    }
                }
            }
        }
        printf("%d,%d\n", ans1.y, ans1.x);
        printf("%d,%d\n", M[0].x, M[0].y);
    }
};

int main() {
    Solution().Solve();
    return 0;
}