#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char Buffer[80];

struct Operation {
    virtual ~Operation() = default;
    virtual bool Read(const string& s) = 0;
    virtual void Do(string& input) = 0;
    virtual void Back(string& input) = 0;
};

// swap position X with position Y
struct OperationSwapPos : public Operation {
    int x, y;

    bool Read(const string& input) {
        if (sscanf(input.c_str(), "swap position %d with position %d",
                   &x, &y) == 2) {
            return true;
        }
        return false;
    }

    void Do(string& input) { swap(input[x], input[y]); }

    void Back(string& input) { Do(input); }
};

struct OperationSwapLetter : public Operation {
    char a, b;

    bool Read(const string& input) {
        if (sscanf(input.c_str(), "swap letter %c with letter %c", &a,
                   &b) == 2) {
            return true;
        }
        return false;
    }

    void Do(string& input) {
        for (int i = 0; i < int(input.size()); ++i) {
            if (input[i] == a) {
                input[i] = b;
                continue;
            }
            if (input[i] == b) {
                input[i] = a;
                continue;
            }
        }
    }

    void Back(string& input) { Do(input); }
};

// rotate left/right X steps
struct OperationRotateSteps : public Operation {
    int steps;
    bool isleft;
    bool Read(const string& input) {
        if (sscanf(input.c_str(), "rotate %s %d steps", Buffer,
                   &steps) == 2) {
            string s = Buffer;
            if (s == "left") {
                isleft = true;
            } else {
                isleft = false;
            }
            return true;
        }
        return false;
    }

    void Do(string& input) {
        if (isleft) {
            rotate(input.begin(), input.begin() + steps, input.end());
        } else {
            rotate(input.begin(),
                   input.begin() + int(input.size()) - steps,
                   input.end());
        }
    }

    void Back(string& input) {
        isleft = !isleft;
        Do(input);
        isleft = !isleft;
    }
};

struct OperationBasedOnPos : public Operation {
    char x;
    int steps;

    bool Read(const string& input) {
        if (sscanf(input.c_str(),
                   "rotate based on position of letter %c", &x) == 1) {
            return true;
        }
        return false;
    }

    void Do(string& input) {
        steps = int(input.find(x));
        if (steps >= 4) {
            steps++;
        }
        steps++;
        steps %= int(input.size());
        rotate(input.begin(), input.begin() + int(input.size()) - steps,
               input.end());
    }

    void Back(string& input) {
        string temp(input);
        while (true) {
            rotate(temp.begin(), temp.begin() + 1, temp.end());
            string s = temp;
            Do(s);
            if (s == input) {
                input = temp;
                return;
            }
        }
    }
};

struct OperationReverse : public Operation {
    int left, right;
    bool Read(const string& input) {
        if (sscanf(input.c_str(), "reverse positions %d through %d",
                   &left, &right) == 2) {
            return true;
        }
        return false;
    }

    void Do(string& input) {
        if (left > right) {
            swap(left, right);
        }
        reverse(input.begin() + left, input.begin() + right + 1);
    }

    void Back(string& input) { Do(input); }
};

struct OperationMove : public Operation {
    int from, to;
    string letter;

    bool Read(const string& input) {
        if (sscanf(input.c_str(), "move position %d to position %d",
                   &from, &to) == 2) {
            return true;
        }
        return false;
    }

    void Do(string& input) {
        letter = input[from];
        input.erase(from, 1);
        input.insert(to, letter);
    }

    void Back(string& input) {
        swap(from, to);
        Do(input);
        swap(from, to);
    }
};

struct ReadOperations {
    const string* Input;
    unique_ptr<Operation> Parsed;

    unique_ptr<Operation> Parse(const string& input) {
        Input = &input;
        auto a = make_unique<OperationSwapPos>();
        if (a->Read(*Input)) {
            Parsed = move(a);
        }
        auto b = make_unique<OperationSwapLetter>();
        if (b->Read(*Input)) {
            Parsed = move(b);
        }
        auto c = make_unique<OperationRotateSteps>();
        if (c->Read(*Input)) {
            Parsed = move(c);
        }
        auto d = make_unique<OperationBasedOnPos>();
        if (d->Read(*Input)) {
            Parsed = move(d);
        }
        auto e = make_unique<OperationReverse>();
        if (e->Read(*Input)) {
            Parsed = move(e);
        }
        auto f = make_unique<OperationMove>();
        if (f->Read(*Input)) {
            Parsed = move(f);
        }
        return move(Parsed);
    }
};

struct Solution {
    vector<unique_ptr<Operation>> Input;

    void Solve() {
        while (scanf("%[^\n]\n", Buffer) == 1) {
            Input.emplace_back(ReadOperations().Parse(Buffer));
        }
        string s1 = "abcdefgh";
        for (const auto& i : Input) {
            i->Do(s1);
        }
        printf("%s\n", s1.c_str());
        string s2 = "fbgdceah";
        for (int i = Input.size() - 1; i >= 0; --i) {
            Input[i]->Back(s2);
        }
        printf("%s\n", s2.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}