#include <algorithm>
#include <cstdio>
#include <memory>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct Action {
    virtual ~Action() = default;
    virtual bool Parse(const string& s) = 0;
    virtual void Go(string& s) = 0;
    virtual void GoBack(string& s) = 0;
};

struct ActionSwapPosition : public Action {
    int X, Y;

    bool Parse(const string& s) {
        const char* format = "swap position %d with position %d";
        return sscanf(s.c_str(), format, &X, &Y) == 2;
    }

    void Go(string& s) { swap(s[X], s[Y]); }
    void GoBack(string& s) { Go(s); }
};

struct ActionSwapLetter : public Action {
    char X, Y;

    bool Parse(const string& s) {
        const char* format = "swap letter %c with letter %c";
        return sscanf(s.c_str(), format, &X, &Y) == 2;
    }

    void Go(string& s) {
        for (char& c : s)
            c = c == X ? Y : c == Y ? X : c;  // 加&可修改，取地址
    }

    void GoBack(string& s) { Go(s); }
};

struct ActionRotateLeft;
struct ActionRotateRight;

void RotateLeft(string& s, int x) {
    rotate(s.begin(), s.begin() + x, s.end());
}

struct ActionRotateLeft : public Action {
    int X;

    bool Parse(const string& s) {
        const char* format = "rotate left %d steps";
        return sscanf(s.c_str(), format, &X) == 1;
    }

    void Go(string& s) { RotateLeft(s, X); }
    void GoBack(string& s) { RotateLeft(s, s.size() - X); }
};

struct ActionRotateRight : public Action {
    int X;

    bool Parse(const string& s) {
        const char* format = "rotate right %d steps";
        return sscanf(s.c_str(), format, &X) == 1;
    }

    void Go(string& s) { RotateLeft(s, s.size() - X); }
    void GoBack(string& s) { RotateLeft(s, X); }
};

struct ActionRotateByPosition : public Action {
    char X;

    int Offset(int index) { return index + 1 + (4 <= index); }

    bool Parse(const string& s) {
        const char* format = "rotate based on position of letter %c";
        return sscanf(s.c_str(), format, &X) == 1;
    }

    void Go(string& s) {
        RotateLeft(s, s.size() - Offset(s.find(X)) % s.size());
    }

    void GoBack(string& s) {
        int indexNew = s.find(X);
        int index = 0, offset;
        while (true) {
            offset = Offset(index) % s.size();  // 向右走
            if ((index + offset) % s.size() == indexNew)
                break;  // 之前位置加上向右走等于现在位置
            ++index;
        }
        RotateLeft(s, offset);  // 现在位置向左走等于之前位置
    }
};

struct ActionReverse : public Action {
    int X, Y;

    bool Parse(const string& s) {
        const char* format = "reverse positions %d through %d";
        return sscanf(s.c_str(), format, &X, &Y) == 2;
    }

    void Go(string& s) { reverse(s.begin() + X, s.begin() + Y + 1); }
    void GoBack(string& s) { Go(s); }
};

struct ActionMove : public Action {
    int X, Y;

    bool Parse(const string& s) {
        const char* format = "move position %d to position %d";
        return sscanf(s.c_str(), format, &X, &Y) == 2;
    }

    void Go(string& s) {
        if (X < Y) {
            rotate(s.begin() + X, s.begin() + X + 1,
                   s.begin() + Y + 1);  // X 到 Y + 1 向左移一格
        } else {
            rotate(s.begin() + Y, s.begin() + X, s.begin() + X + 1);
            // 向右一格，等于向左 size() - 1
            // size() = X - Y + 1
            // 向左移: X - Y + 1 - 1 = X - Y 格;
            // 开始为 Y, 中间为 Y + X - Y = X, 末尾为 X + 1;
        }
    }

    void GoBack(string& s) {
        swap(X, Y);
        Go(s);
        swap(X, Y);
    }
};

struct ActionParser {
    const string* Input;
    unique_ptr<Action> Parsed;  // 必须是父类
    // 父类 等于 子类，调用子类
    // 单纯返回子类类型没用，且没有初始化
    /* 例如
    if(make_unique<OperationSwapPos>()->Read(*Input)) {
        return make_unique<OperationSwapPos>()
    }
    */

    template <typename ActionSome>
    void Try() {
        auto action = make_unique<ActionSome>();
        if (action->Parse(*Input)) Parsed = move(action);  // 且初始化
    }

    unique_ptr<Action> Parse(const string& input) {
        Input = &input;
        Try<ActionMove>();
        Try<ActionReverse>();
        Try<ActionRotateByPosition>();
        Try<ActionRotateLeft>();
        Try<ActionRotateRight>();
        Try<ActionSwapLetter>();
        Try<ActionSwapPosition>();
        return move(Parsed);
    }
};

char Buffer[80];

struct Solution {
    vector<unique_ptr<Action>> Input;

    void Solve() {
        while (scanf("%[^\n]\n", Buffer) == 1) {
            Input.emplace_back(ActionParser().Parse(Buffer));
        }
        string s1 = "abcdefgh";
        for (const auto& i : Input) i->Go(s1);
        printf("%s\n", s1.c_str());
        string s2 = "fbgdceah";
        for (int i = Input.size() - 1; i >= 0; --i) {
            Input[i]->GoBack(s2);
        }
        printf("%s\n", s2.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}