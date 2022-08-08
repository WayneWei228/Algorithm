#include <cstdio>
#include <limits>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Balloon {
    int H, P;
};

struct Solution {
    int N, M, Q;
    vector<int> velocity;
    vector<Balloon> balloons;
    int minTime = numeric_limits<int>::max();
    int minEnergy = numeric_limits<int>::max();
    int count = 0;
    void printIndent(int n) {
        for (int i = 0; i < n; i++) {
            printf("   ");
        }
    }

    void Permutate(int no, int cost) {
        printIndent(count++);
        printf("no = %d, cost = %d\n", no, cost);

        if (no >= N) {
            printIndent(--count);
            printf("return\n");
            return;
        }
        if (cost > Q) {
            printIndent(--count);
            printf("return\n");
            return;
        }
        Calculate(balloons, cost);
        int nowH = balloons[no].H;
        for (int i = 0; i < M; i++) {
            balloons[no].H = i;
            Permutate(no + 1, cost + abs(nowH - i));
        }
        balloons[no].H = nowH;

        printIndent(--count);
        printf("return\n");
        return;
    }

    void Calculate(const vector<Balloon>& b, int cost) {
        int time = 0;
        for (int i = 0; i < b.size(); i++) {
            if (b[i].P < 0 && velocity[b[i].H] < 0) return;
            if (b[i].P > 0 && velocity[b[i].H] > 0) return;
            if (velocity[b[i].H] == 0) return;
            time = max(time, abs(b[i].P) / abs(velocity[b[i].H]));
        }
        if (time < minTime) {
            minTime = time;
            minEnergy = cost;
        }
        if (time == minTime && cost < minEnergy) {
            minEnergy = cost;
        }
        return;
    }

    void Solve(int caseNo) {
        scanf("%d%d%d", &N, &M, &Q);
        velocity.resize(M);
        balloons.resize(N);
        for (int i = 0; i < M; i++) {
            scanf("%d", &velocity[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &balloons[i].P, &balloons[i].H);
        }
        printf("Case #%d: \n", caseNo);
        Permutate(0, 0);
        if (minTime == numeric_limits<int>::max()) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", minTime);
        }
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}