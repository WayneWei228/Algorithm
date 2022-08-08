#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

struct Solution {
    vector<int> Input;
    int Position;

    // static 修饰函数
    // 表示此函数不需要传入 this
    // 也不能访问成员变量
    // 相当于定义在struct之外
    // ❌
    // Student s;
    // s.xx()
    // ✅
    // Student::xx()
    static int Method0(const vector<int>& answers, int* metadata,
                       int metadataSize) {
        int answer = 0;
        for (int i : answers) answer += i;
        for (int i = 0; i < metadataSize; ++i) {
            answer += metadata[i];
        }
        return answer;
    }

    // int*是数组
    // 数组就是指针 
    // 指针就是数组
    static int Method1(const vector<int>& answers, int* metadata,
                       int metadataSize) {
        if (answers.empty()) {
            // 没有儿子， meta 相加
            return Method0(answers, metadata, metadataSize);
        }
        int answer = 0;
        for (int i = 0; i < metadataSize; ++i) {
            if (metadata[i] == 0) continue;
            if (answers.size() < metadata[i]) continue;
            // metadata[i] 往后偏移 i 格
            answer += answers[metadata[i] - 1];
        }
        return answer;
    }

    int SolveWith(function<int(const vector<int>&, int*, int)> f) {
        int children = Input[Position++];
        int metadata = Input[Position++];
        vector<int> answers; // 儿子的答案们
        for (int i = 0; i < children; ++i) {
            answers.emplace_back(SolveWith(f));
        }
        int answer = f(answers, &Input[Position], metadata);
        Position += metadata;
        return answer;
    }

    void Solve() {
        while (true) {
            int x;
            if (scanf("%d", &x) < 1) break;
            Input.emplace_back(x);
        }
        Position = 0;
        printf("%d\n", SolveWith(Method0));
        Position = 0;
        printf("%d\n", SolveWith(Method1));
    }
};

int main() {
    Solution().Solve();
    return 0;
}