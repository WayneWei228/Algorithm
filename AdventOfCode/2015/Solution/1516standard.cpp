#include <cstdio>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer0[80], Buffer1[80], Buffer2[80];

struct Property {
    string Name;
    int Amount;
};

typedef unordered_map<string, function<bool(int)>> Sue;

struct Solution {
    Sue Sue0{
        {"children", Eq(3)},    {"cats", Eq(7)},   {"samoyeds", Eq(2)},
        {"pomeranians", Eq(3)}, {"akitas", Eq(0)}, {"vizslas", Eq(0)},
        {"goldfish", Eq(5)},    {"trees", Eq(3)},  {"cars", Eq(2)},
        {"perfumes", Eq(1)},
    };
    Sue Sue1{
        {"children", Eq(3)},    {"cats", Gt(7)},   {"samoyeds", Eq(2)},
        {"pomeranians", Lt(3)}, {"akitas", Eq(0)}, {"vizslas", Eq(0)},
        {"goldfish", Lt(5)},    {"trees", Gt(3)},  {"cars", Eq(2)},
        {"perfumes", Eq(1)},
    };

    function<bool(int)> Eq(int x) {
        return [x](int x0) { return x0 == x; };
    }

    function<bool(int)> Gt(int x) {
        return [x](int x0) { return x0 > x; };
    }

    function<bool(int)> Lt(int x) {
        return [x](int x0) { return x0 < x; };
    }

    bool Match(const unordered_map<string, function<bool(int)>>& sue,
               const vector<Property>& p) {
        for (const auto& i : p) {
            if (!sue.at(i.Name)(i.Amount)) return false;
        }
        return true;
    }

    void Solve() {
        int answer0 = 0, answer1 = 0;
        while (true) {
            int no, n0, n1, n2;
            vector<Property> sue;
            int result =
                scanf("Sue %d: %[^:]: %d, %[^:]: %d, %[^:]: %d ",  //
                      &no, Buffer0, &n0, Buffer1, &n1, Buffer2, &n2);
            if (result < 7) break;
            sue.emplace_back(Property{Buffer0, n0});
            sue.emplace_back(Property{Buffer1, n1});
            sue.emplace_back(Property{Buffer2, n2});
            if (Match(Sue0, sue)) answer0 = no;
            if (Match(Sue1, sue)) answer1 = no;
        }
        printf("%d\n%d\n", answer0, answer1);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
