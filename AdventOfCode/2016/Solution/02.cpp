#include <cstdio>
#include <string>
using namespace std;

struct Next {
    string R, U, L, D;
    int Rank[256];

    // sT 原本字符排列方式
    // sR 每个字符右边是谁
    // sU        上面
    // sL        左边
    // sD        下面
    // string&& 传进的内容可以被毁掉, 右值可以做
    // 传入 "abcd" 可传右值
    // string& 只能传左值
    // const string& 可以传右值
    // move() 给&&传值必须加move()
    // move() 左值转右值
    Next(string&& sT,  //
         string&& sR, string&& sU, string&& sL, string&& sD)
        : R(move(sR)), U(move(sU)), L(move(sL)), D(move(sD)) { // 冒号可在构造函数圆括号后使用来进行初始化
        for (int i = 0; i < sT.size(); ++i) Rank[sT[i]] = i;   // R(move(sR)) : R 用 sR 初始化
    }                                                          // 对于系统内置类型 a = move(b) 有优化
                                                               // 转移 b 指针到 a, b 什么都不指
                                                               // Rank 给定一个字符查出是第几个


    char From(char c, char go) {
        switch (go) {
            case 'R':
                return R[Rank[c]];
            case 'U':
                return U[Rank[c]];
            case 'L':
                return L[Rank[c]];
            case 'D':
                return D[Rank[c]];
        }
        return 0;
    }
};

char Buffer[600];

struct Solution {
    string answer1, answer2;
    Next next1{
        "0123456789",                //
        "0233566899", "0123123456",  //
        "0112445778", "0456789789",  //
    };
    Next next2{
        "123456789ABCD",                   //
        "134467899BCCD", "121452349678B",  //
        "122355678AABD", "36785ABC9ADCD",  //
    };

    void Solve() {
        for (int i = 0; i < 5; ++i) {
            scanf("%s", Buffer);
            string s = Buffer;
            char current1 = '5', current2 = '5';
            for (char j : s) {
                current1 = next1.From(current1, j);
                current2 = next2.From(current2, j);
            }
            answer1 += current1;
            answer2 += current2;
        }
        printf("%s\n", answer1.c_str());
        printf("%s\n", answer2.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}