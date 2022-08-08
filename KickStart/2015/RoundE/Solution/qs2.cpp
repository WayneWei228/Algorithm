#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int64;

struct Solution {
    int N, K;
    vector<int> A[4];

    void Solve(int caseNo) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < 4; ++i) {
            A[i].resize(N);
            for (int& j : A[i]) scanf("%d", &j);
        }
        unordered_map<int, int> u0 = Xor(A[0], A[1]);
        unordered_map<int, int> u1 = Xor(A[2], A[3]);
        int64 answer = 0;
        // 利用map O(1) 查找 和 XOR 映射
        // Meet in the Middle 
        for (const auto& i : u0) {
            answer += (int64)u1[K ^ i.first] * i.second;
        }
        printf("Case #%d: %lld\n", caseNo, answer);
    }

    unordered_map<int, int> Xor(const vector<int>& a0,
                                const vector<int>& a1) {
        unordered_map<int, int> answer;
        for (int i : a0) {
            for (int j : a1) ++answer[i ^ j];
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