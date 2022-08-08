#include <cstdio>
using namespace std;

typedef unsigned long long uint64;

struct GenA;
struct GenB;

struct Gen {
    virtual ~Gen() = default;
    virtual void Next() = 0;

};

struct GenA : public Gen {
    uint64 value;
    void Next() { value = (value * 16807) % 2147483647; }
};

struct GenB : public Gen {
    uint64 value;
    void Next() { value = (value * 48271) % 2147483647; }
};

// template<class T> 
// T类型是任何类型
// 能不能编译自己保证
// 有个算法针对 int 写
// 相同算法也可以用 double 写
// 把 int double 变成 T 类型


bool Compare(const GenA& a, const GenB& b) {
    for (int i = 0; i < 16; i++) {
        if (((a.value >> i) & 1) != ((b.value >> i) & 1)) {
            return false;
        }
    }
    return true;
}

// 子类指针可当父类指针用
// 如果想用多态， 就得用指针
// 多态：同一个接口表现不同行为
// 帮你模糊掉用哪个

struct Solution {
    int ans1 = 0;
    int ans2 = 0;

    GenA A;
    GenB B;
    void Solve() {
        uint64 a, b;
        scanf("Generator A starts with %lld ", &a);
        scanf("Generator B starts with %lld ", &b);

        A.value = a;
        B.value = b;

        for (int i = 0; i < 40000000; i++) {
            A.Next();
            B.Next();
            if (Compare(A, B)) {
                ans1++;
            }
        }
        printf("%d\n", ans1);

        A.value = a;
        B.value = b;
        for (int i = 0; i < 5000000; i++) {
            while (A.value % 4 != 0) {
                A.Next();
            }
            while (B.value % 8 != 0) {
                B.Next();
            }
            if (Compare(A, B)) {
                ans2++;
            }
            A.Next();
            B.Next();
        }
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}