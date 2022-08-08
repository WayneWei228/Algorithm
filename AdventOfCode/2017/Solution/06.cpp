#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>
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
    vector<int> A;

    void Redistribute() {
        int k = max_element(A.begin(), A.end()) - A.begin();
        int maxA = A[k];
        A[k] = 0;
        while (true) {
            k = (k + 1) % A.size();
            if (maxA-- == 0) break;
            ++A[k];
        }
    }

    void Solve() {
        while (true) {
            int x;
            if (scanf("%d", &x) < 1) break;
            A.emplace_back(x);
        }
        unordered_set<vector<int>, VectorIntHash> H;
        while (H.count(A) == 0) {
            H.emplace(A);
            Redistribute();
        }
        int answer1 = H.size();
        printf("%d\n", answer1);
        while (H.count(A) != 0) {
            H.erase(A);
            Redistribute();
        }
        int answer2 = answer1 - H.size();
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}