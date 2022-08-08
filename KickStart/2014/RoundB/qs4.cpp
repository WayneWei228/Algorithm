#include <cstdio>
#include <limits>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long uint64;

uint64 Fingerprint(uint64 x) {
    const long long kMul = 0x9ddfea08eb382d69ULL;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    x *= kMul, x ^= x >> 47;
    return x * kMul;
}

struct VectorIntHash {
    size_t operator()(const vector<int>& x) const {
        uint64 answer = 0;
        for (int i : x) answer = Fingerprint(answer + i);
        return answer;
    }
};

struct Solution {
    int N, K;
    vector<int> arr;
    unordered_set<vector<int>, VectorIntHash> H;
    int answer = numeric_limits<int>::max();
    // 3个一组，33组
    // 每组有存在与不存在两个状态
    // 合法的中间状态至少有2^33个
    
    void Change(const vector<int>& arr) {
        if (H.count(arr)) return;
        H.emplace(arr);
        if (arr.size() <= 2) return;
        for (int i = 0; i < arr.size() - 2; i++) {
            if (arr[i] == arr[i + 1] - K &&
                arr[i] == arr[i + 2] - 2 * K) {
                vector<int> newarr(arr.begin(), arr.begin() + i);
                for (int j = i + 3; j < arr.size(); j++) {
                    newarr.emplace_back(arr[j]);
                }
                Change(move(newarr));
            }
        }
        return;
    }

    void Solve(int caseNo) {
        scanf("%d%d", &N, &K);
        arr.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        Change(arr);
        for (auto i : H) {
            answer = min(answer, int(i.size()));
        }
        printf("Case #%d: %d\n", caseNo, answer);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}