#include <cstdio>
#include <string>
#include <unordered_set>
#include <utility>
using namespace std;

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) { // 给一个uint64 得到一个uint64, 越乱越好, 对于同一个uint64, 必须得到同一个解, 不同的尽量得到不同的解 要求看到结果尽量猜不出原来的数
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

// 把东西存入哈希表需要哈希函数
// 哈希函数： 把任何东西映射到一个 uint64


// 哈希表: 很多数据， 快速判断存在与否， 需用到哈希表，
// 每个数据算hash, 算完之后把hash % 一个表长（一个比较的大数字）
// 表 为 vector<bool> 模完之后对应位置设置为true 
// 看东西存在与否 则只需要计算 Fingerprint
// 把元素与位置对应来判断数据存在与否就是哈希表
// 几个对应一个: vector<vector<string>> a 实现 string hash值为 7， a[7].emplace_back(string) 比堆一块快
// 先计算string hash值, 然后在a[hash]里查找
// 这就实现了unordered_set O(1)
// 对应格子数量很小, 所以为O(1);
// 需传递两个类型参数 1，放什么东西, 2 怎么hash 
// 放快递, 十个格子, 不同格子放对应味好快递, 查找时则只需要在对应尾号格子中查找 此案例中算hash值的方法为 % 10, 快递号 % 10 = 尾号

char Buffer[8193];

struct Coordinate {
    int X, Y;

    bool operator==(const Coordinate& that) const {
        return X == that.X && Y == that.Y;
    }
};

struct CoordinateHash {
    // size_t Run(const Coordinate& c) {} // a.Run(b) 

    size_t operator()(const Coordinate& c) const { // a(b)
        return Fingerprint(c.X) + c.Y;
    }
};
// CoordinateHash a;
// a(Coordinate)
typedef unordered_set<Coordinate, CoordinateHash> CoordinateSet;
// unordered_set<基本数据类型> a;
// unordered_set<结构体, 哈希方式> a;
// 结构体需写operator== 判等
// CoordinateHash 必须有 operator()
struct Santa {
    CoordinateSet* U;
    int X = 0, Y = 0;

    void Go(char c) {
        switch (c) {
            case '>':
                ++X;
                break;
            case '^':
                ++Y;
                break;
            case '<':
                --X;
                break;
            case 'v':
                --Y;
                break;
        }
        U->emplace(Coordinate{X, Y});
    }
};

struct Solution {
    string S;

    void Solve() {
        scanf("%s", Buffer);
        S = Buffer;
        CoordinateSet answer;
        answer.emplace(Coordinate{0, 0});
        Santa santa{&answer};
        for (int i = 0; i < S.size(); ++i) santa.Go(S[i]);
        printf("%d\n", int(answer.size()));
        answer.clear();
        answer.emplace(Coordinate{0, 0});
        Santa santas[2]{{&answer}, {&answer}};
        int d = 0;
        for (int i = 0; i < S.size(); ++i) {
            santas[d].Go(S[i]);
            d = 1 - d;
        }
        printf("%d\n", int(answer.size()));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
