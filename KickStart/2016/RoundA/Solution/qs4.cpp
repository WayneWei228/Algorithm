#include <cstdio>
#include <map>
#include <vector>
using namespace std;

struct Card {
    int K, L;
    vector<int> A, C;
};

typedef long long int64;

struct Solution {
    int M, N;
    int64 Answer = 0;
    vector<Card> Cards;
    map<int, int64> Map[9][12];
    // Map[pick][no] {m, attack}

    void Solve(int caseNo) {
        scanf("%d%d", &M, &N);
        Cards.resize(N);
        for (Card& i : Cards) {
            scanf("%d%d", &i.K, &i.L);
            i.A.resize(i.K);
            for (int& j : i.A) scanf("%d", &j);
            i.C.resize(i.K - 1);
            for (int& j : i.C) scanf("%d", &j);
        }
        Search(8, 0, M, 0);
        printf("Case #%d: %lld\n", caseNo, Answer);
    }

    /*
    pick : 还要拿几个
    no : 当前处理到第几个
    m : 当前还剩多少钱
    attack : 当前累计攻击力
    */
    void Search(int pick, int no, int m, int64 attack) {
        if (pick == 0) {
            if (Answer < attack) Answer = attack;
            return;
        }
        if (N - no < pick) return;
        auto it = Map[pick][no].lower_bound(m);
        // 为了让line 47 剪枝最强，该用lower_bound
        if (it != Map[pick][no].end() && attack < it->second) return;
        // 钱比我多，攻击力还比我高，所以不要
        Map[pick][no][m] = attack;
        // 用动态规划来做分支定界
        int64 cost = 0;
        for (int i = Cards[no].L; i <= Cards[no].K; ++i) {
            if (m < cost) break;
            Search(pick - 1, no + 1, m - cost,
                   attack + Cards[no].A[i - 1]);
            if (i < Cards[no].K)
                cost += Cards[no]
                            .C[i - 1];  // 计算下一次upgrade所需要的cost
        }
        Search(pick, no + 1, m, attack);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}