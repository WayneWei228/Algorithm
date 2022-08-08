#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[80];
struct Dance;

struct Programs {
    string s = "abcdefghijklmnop";
    vector<unique_ptr<Dance>> V;
};

struct Dance {
    virtual ~Dance() = default;
    virtual void Do(Programs& p) = 0;
};

struct Spin : public Dance {
    int steps;

    unique_ptr<Spin> Clone() const { return make_unique<Spin>(*this); }

    void Do(Programs& p) {
        rotate(p.s.begin(), p.s.begin() + 16 - steps, p.s.end());
    }
};

struct Exchange : public Dance {
    int l, r;

    unique_ptr<Exchange> Clone() const {
        return make_unique<Exchange>(*this);
    }

    void Do(Programs& p) { swap(p.s[l], p.s[r]); }
};

struct Partner : public Dance {
    char l, r;

    unique_ptr<Partner> Clone() const {
        return make_unique<Partner>(*this);
    }

    void Do(Programs& p) {
        for (auto& i : p.s) {
            if (i == l) {
                i = r;
                continue;
            }
            if (i == r) {
                i = l;
                continue;
            }
        }
    }
};

struct ReadDance {
    unique_ptr<Dance> Parsed(const string& input) {
        if (input[0] == 's') {
            auto ans = make_unique<Spin>()->Clone();
            sscanf(input.c_str(), "%*c%d", &ans->steps);
            return ans;
        }
        if (input[0] == 'p') {
            auto ans = make_unique<Partner>()->Clone();
            sscanf(Buffer, "%*c%c/%c", &ans->l, &ans->r);
            return ans;
        }
        if (input[0] == 'x') {
            auto ans = make_unique<Exchange>()->Clone();
            sscanf(Buffer, "%*c%d/%d", &ans->l, &ans->r);
            return ans;
        }
        return nullptr;
    }
};

struct Solution {
    Programs P;
    unordered_map<string, int> M;

    void Solve() {
        while (true) {
            ReadDance r;
            int nchars = -1;
            scanf("%[^,],%n", Buffer, &nchars);
            P.V.emplace_back(r.Parsed(Buffer));
            if (nchars == -1) break;
        }
        int i = 1;
        int circle;
        while (true) {
            for (auto& j : P.V) {
                j->Do(P);
            }
            if (i == 1) {
                printf("%s\n", P.s.c_str());
            }
            if (M[P.s] == 0) {
                M[P.s] = i;
            } else {
                circle = i - M[P.s];
                break;
            }
            i++;
        }
        int c = 1000000000 % circle;
        if (c == 0) {
            c = circle;
        }
        for (auto i : M) {
            if (i.second == c) {
                printf("%s\n", i.first.c_str());
                break;
            }
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}