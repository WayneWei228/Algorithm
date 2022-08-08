#include <cstdio>
#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int G, W, H, B, X, R;
    int64 D, LastSecond;
    vector<vector<int>> Pattern;

    void Solve(int caseNo) {
        G = Read();
        W = Read();
        H = Read();
        B = Read();
        X = Read();
        scanf("%lld", &D);
        LastSecond = Simulate();
        printf("Case #%d: %lld\n", caseNo, Compute());
    }

    int Read() {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        return (h * 60 + m) * 60 + s;
    }

    /*
     如果兔子能活无限长时间，那就会返回-1
     否则是兔子的最长寿命
     会修改全局变量 R and Pattern
     Pattern： 每一天什么时候喂兔子
     R：Pattern.size() 这一天 和 哪一天完全相同 开始循环的那一天
     只有返回-1，R才是有用的

    */
    int64 Simulate() {
        unordered_map<int, int> u;
        int64 time = 0; 
        // 最多86400天，肯定循环
        while (true) {
            // time 刚喂
            // 所以在time + 1 和 time + X + 1之间肯定喂过一次
            // 两秒之间检查
            if (!FindLast(time, time + 1, time + X + 1,
                          [this](int64 i) { return Awake(i); })) {
                return time + X; // 活在 time + X s 死在 time + X + 1 s
            }
            int t = time % 86400;
            int d = time / 86400;
            if (d == Pattern.size()) { 
                /* 
                Pattern[d] 还是越界的时候
                u: 每个时间点作为第一次喂兔子的时间出现在第几天
                利用第一维唯一性
                所以t在前，d在后
                */
                auto result = u.emplace(t, d);
                if (!result.second) { 
                    // 如果放不进去
                    // 说明上一次也是从这个时间喂兔子
                    // 今天和上次同一时间不同天数喂兔子，循环了
                    R = result.first->second;
                    return -1;
                }
            }
            Pattern.resize(d + 1); // 喂了兔子就resize d + 1
            Pattern[d].emplace_back(t);
        }
    }

    int64 Compute() {
        if (LastSecond == -1) { // 活过去
            if (D < R) return Sum(0, D) - Adjust(D - 1);
            // a.length = a.end - a.begin 左闭右开特性
            int64 m = Pattern.size() - R;
            int64 div = (D - R) / m;
            int64 mod = (D - R) % m;
            int64 sum0 = Sum(0, R); // 不循环
            int64 sum1 = Sum(R, Pattern.size()) * div; // 循环节
            /*
            在循环中， Pattern[Pattern.size() + K] == Pattern[R + K] 假设Pattern无限大
            1,234, 23, 4 234... 
            第一个逗号是 R
            第二个逗号是 Pattern.size();
            第三个逗号是 R + mod or Pattern.size() + mod (same)
            Pattern 1234
            */
            int64 sum2 = Sum(R, R + mod); // 剩下的
            return sum0 + sum1 + sum2 - Adjust(R + (mod + m - 1) % m);
        }
        if (D * 86400 <= LastSecond) return Sum(0, D) - Adjust(D - 1); // 活过去
        return -1;
    }

    // 醒着不工作
    bool Awake(int64 time) {
        time %= 86400;
        // 四点分五段，从大到小
        if (B <= time) return false;
        if (H <= time) return true;
        if (W <= time) return false;
        if (G <= time) return true;
        return false;
    }

    // 在[Begin, End)，找到最后一个ok, 有的话true，无的话false
    // 此ok可不连续
    // answer 放答案
    bool FindLast(int64& answer, int64 begin, int64 end,
                  function<bool(int64)> ok) {
        for (int i = end - 1; i >= begin; --i) {
            if (ok(i)) {
                answer = i;
                return true;
            }
        }
        return false;
    }


    int64 Sum(int begin, int end) {
        int64 answer = 0;
        for (int i = begin; i < end; ++i) answer += Pattern[i].size();
        return answer;
    }
    // 最后一天兔子撑过0点就行，不必管能不能撑过早上，所以可以少喂几次
    int Adjust(int no) {
        int answer = Pattern[no].size(); 
        for (int i : Pattern[no]) {
            --answer; // 等同于 j = 0, j++, answer -= j
            if (86400 <= i + X) break; // 撑过86400 就不管
        }
        return answer;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}