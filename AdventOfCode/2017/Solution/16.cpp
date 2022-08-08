#include <algorithm>
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Dance {
    char Dancer[17];

    Dance() {
        for (int i = 0; i < 16; ++i) Dancer[i] = 'a' + i;
        Dancer[16] = 0;
    }
};

struct Action {
    virtual ~Action() = default;
    virtual void Read() = 0;
    virtual void Run(Dance& d) = 0;
};

struct ActionSpin : public Action {
    int X;

    void Read() { scanf("%d", &X); }

    void Run(Dance& d) {
        rotate(&d.Dancer[0], &d.Dancer[16 - X], &d.Dancer[16]);
    }
};

struct ActionExchange : public Action {
    int A, B;

    void Read() { scanf("%d/%d", &A, &B); }

    void Run(Dance& d) { swap(d.Dancer[A], d.Dancer[B]); }
};

struct ActionPartner : public Action {
    char A, B;

    void Read() { scanf("%c/%c", &A, &B); }

    void Run(Dance& d) {
        for (char& i : d.Dancer) i = i == A ? B : i == B ? A : i;
    }
};

struct Solution {
    vector<unique_ptr<Action>> Input;

    template <typename T>
    unique_ptr<Action> ReadActionSome() {
        auto answer = make_unique<T>();
        answer->Read();
        return answer;
    }

    unique_ptr<Action> ReadAction() {
        scanf(",");
        char c;
        if (scanf("%c", &c) < 1) return nullptr;
        switch (c) {
            case 's':
                return ReadActionSome<ActionSpin>();
            case 'x':
                return ReadActionSome<ActionExchange>();
            case 'p':
                return ReadActionSome<ActionPartner>();
        }
        return nullptr;
    }

    string Repeat(int n) {
        Dance dance;
        unordered_map<string, int> visited;
        bool reduced = false;
        for (int i = 0;; ++i) {
            string s(dance.Dancer);
            if (!reduced) {
                auto result = visited.emplace(s, i);
                if (!result.second) {
                    int i0 = result.first->second;
                    n = (n - i0) % (i - i0) + i;
                    reduced = true;
                }
            }
            if (n == i) return s;
            for (const auto& i : Input) i->Run(dance);
        }
    }

    void Solve() {
        while (true) {
            auto action = ReadAction();
            if (!action) break;
            Input.emplace_back(move(action));
        }
        printf("%s\n", Repeat(1).c_str());
        printf("%s\n", Repeat(1000000000).c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
