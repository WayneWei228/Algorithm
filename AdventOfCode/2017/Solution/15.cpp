#include <cstdio>
#include <vector>
using namespace std;

typedef unsigned long long uint64;


// 写在外面的是函数
// 写在对象里面的是方法
// 写在函数里面的是匿名函数

struct Generator {
    uint64 Factor, Seed;

    void ReadSeed() { scanf("Generator %*c starts with %llu ", &Seed); }

    Generator& MoveNext() {
        Seed = Seed * Factor % 2147483647;
        return *this;
    }

    template <class Lambda>
    Generator& MoveNext(Lambda&& lambda) {
        while (true) {
            MoveNext();
            // x4(1);
            if (lambda(Seed)) return *this;
        }
    }
};

struct Solution {
    int Compute1(Generator g1, Generator g2) {
        int answer = 0;
        for (int i = 0; i < 40000000; ++i) {
            if ((g1.MoveNext().Seed & 0xffff) ==
                (g2.MoveNext().Seed & 0xffff)) {
                ++answer;
            }
        }
        return answer;
    }

    bool x4(int x, int answer) { return x % 4 == 0; }
    int Compute2(Generator g1, Generator g2) {
        int answer = 0;
        // 匿名函数： 函数里面定义函数
        // 只能在函数里用
        // 匿名函数类型只能是 auto
        // [] 里面是不通过参数，直接可用的变量
        // () 参数
        // [&] 所有都可以使用，且传的是引用
        // [=] 所有都可以用，但是穿的是值 复制一份传，外面不受到修改
        // [y] 这个变量可以用，传值
        // [] struct 也可以传

        vector<int> a;
        sort(a.begin(), a.end(), [](int a, int b) { return a > b; });
        auto x4 = [](int x) { return x % 4 == 0; };
        auto x8 = [](int x) { return x % 8 == 0; };
        for (int i = 0; i < 5000000; ++i) {
            // 0xffff 十六个 1 
            if ((g1.MoveNext(x4).Seed & 0xffff) ==
                (g2.MoveNext(x8).Seed & 0xffff)) {
                ++answer;
            }
        }
        return answer;
    }

    void Solve() {
        Generator g1{16807}, g2{48271};
        g1.ReadSeed();
        g2.ReadSeed();
        printf("%d\n", Compute1(g1, g2));
        printf("%d\n", Compute2(g1, g2));
    }
};

int main() {
    Solution().Solve();
    return 0;
}