#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long int64;

unordered_map<int64, int> Factorize(int64 n) {
    unordered_map<int64, int> answer;
    for (int64 i = 2; i <= n / i; ++i) {
        while (n % i == 0) {
            ++answer[i];
            n /= i;
        }
    }
    if (1 < n) ++answer[n];
    return answer;
}

struct Solution {
    int64 N;

    void Solve(int caseNo) {
        scanf("%lld", &N);
        printf("Case #%d: %s\n", caseNo,
               Win(Factorize(N)) ? "Laurence" : "Seymour");
    }

    bool Win(const unordered_map<int64, int>& x) { // 先手必胜
        if (IsG(x)) return false; // 败
        for (const auto& i : x) { // 其中一个质因数
            unordered_map<int64, int> xNew(x);
            xNew.erase(i.first); // 删掉其中一个质因数
            if (!Win(xNew)) return true; // 存在一个对手赢不了的情况，我们就赢
        }
        
        return false;
    }

    bool IsG(const unordered_map<int64, int>& x) {
        int64 n = 1;
        for (const auto& i : x) {
            for (int j = 0; j < i.second; ++j) n *= i.first;
        }
        int64 answer = 0;
        for (int i : to_string(n)) answer += i - '0';
        return PrimeOr1(answer);
    }

    bool PrimeOr1(int64 n) {
        unordered_map<int64, int> x = Factorize(n);
        if (x.size() == 0) return true; // n = 1
        return x.size() == 1 && x.begin()->second == 1; // n is prime number
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}