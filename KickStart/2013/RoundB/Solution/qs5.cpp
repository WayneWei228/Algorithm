#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer[101];

struct Coordinate {
    int X, Y;

    bool operator==(const Coordinate& that) const {
        return X == that.X && Y == that.Y;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate& c) const {
        return c.X * 9875321 + c.Y;
    }
};

typedef unordered_set<Coordinate, CoordinateHash> CoordinateSet;

int DX[6]{0, -1, -1, 0, 1, 1}, DY[6]{1, 1, 0, -1, -1, 0};

struct Solution {
    int N;
    vector<string> B;

    const char* Compute();

    void Solve(int caseNo) {
        scanf("%d", &N);
        B.resize(N);
        for (string& i : B) {
            scanf("%s", Buffer);
            i = Buffer;
        }
        printf("Case #%d: %s\n", caseNo, Compute());
    }
};

struct Node {
    int DFSNumber, Low;
};

struct DFS {
    Solution* S;
    char C;
    CoordinateSet NearBegin, NearEnd;
    Coordinate Begin{-1, 0},
        End{-1, -1};  // 简化模型，只要从 Begin 一个点开始搜，判断
                      // 有没有 End 即可知有无割点
    bool NoCutPoint = true;
    unordered_map<Coordinate, Node, CoordinateHash> Nodes;
    int Time = 0;

    int Count() {
        int answer = 0;
        for (const string& i : S->B) {
            for (char j : i) {
                if (j == C) ++answer;
            }
        }
        return answer;
    }
    // 只能near一条边
    vector<Coordinate> Near(const Coordinate& no) {
        vector<Coordinate> answer;
        auto add = [&](const CoordinateSet s) {
            for (const Coordinate& i : s) {
                if (S->B[i.X][i.Y] == C) answer.emplace_back(i);
                // 边边也有不是一色的
            }
            return answer;
        };
        if (no == Begin) return add(NearBegin);  // begin 到 NearBegin
        if (no == End) return add(NearEnd);      // End 到 NearEnd
        for (int i = 0; i < 6; ++i) {            // 六连通
            Coordinate next{no.X + DX[i], no.Y + DY[i]};
            if (next.X < 0 || S->N <= next.X) continue;
            if (next.Y < 0 || S->N <= next.Y) continue;
            if (S->B[next.X][next.Y] != C) continue;
            answer.emplace_back(next);
        }
        if (NearBegin.count(no)) answer.emplace_back(Begin);
        if (NearEnd.count(no)) answer.emplace_back(End);
        return answer;
    }

    bool Connect() {
        // 第二个表示父亲是谁
        Visit(Begin, Begin);
        return Nodes[End].DFSNumber != 0;  // 目的地都没到，不通
    }

    // no 和 no 的子树有没有End
    bool Visit(const Coordinate& no, const Coordinate& parent) {
        bool answer = no == End;  // 自己就是 end
        Node& node = Nodes[no];   // 当前点
        // DFSNumber 是当前点的顺序
        // Low 是当前点不通过父子边
        // 子树往上跳一下能达到的最小的DFSNumber 目标点是最小DFSNumber
        // 有图没树
        // 树是访问时人为造的树
        // 树里的那些边是正常访问时所连成的树
        // 非树边是指向已访问的点的边（无向图）

        // 如果low走不了的话，那就是DFSNumber
        node.DFSNumber = node.Low = ++Time;
        // 从 1 开始
        // 有重边的话（parent为连接parent的边（来的时候的边不能走，但另外连接parent的边可以走）
        // vector<vector<int>> Out
        // vector<int> E;
        /*
        for (auto i : Out[3]) { 所有出边的序号
            E[i] 存两点之和 或者 异或符号
            E[i] - 3
        }
        */
        for (const Coordinate& i : Near(no)) {
            if (i == parent) continue;
            const Node& next = Nodes[i];  // 指出去的点，子节点
            // 树边，没访问过
            if (Nodes[i].DFSNumber == 0) {
                bool hasEnd = Visit(i, no);  // 往下走，更新子树的值
                answer |= hasEnd;  // 子树 i 有没有end （以i为根的子树
                node.Low = min(
                    node.Low,
                    next.Low);  // 没访问过的子节点刷新low之后跟node比较然后更新node.low
                                // /
                                // next没跳过，在下面，可跳，所以比较的是low
                if (no == Begin || no == End)
                    continue;  // 不能割 Begin 和 End
                if (hasEnd &&  // next 里包括 End （写前面会快一些
                    node.DFSNumber <=
                        next.Low) {  // node是割点，子树中跳一次能跳到的数比当前序号还大，证明当前node是割点
                    NoCutPoint = false;  // 有割点
                }
            } else {
                // 已经见过的点，非树边
                // next 在上面
                // node 到 next 其实已经跳过了，所以用DFSNumber
                // 更新，不能再跳
                // 1 - 2, 2 - 3, 3 - 4, 4 - 5, 5 - 3,
                // 3 已访问，跟DFSNumber 比
                // 如果跟 3 的Low比就跳了两次
                node.Low = min(node.Low, next.DFSNumber);
            }
        }
        return answer;
    }
};

const char* Solution::Compute() {
    DFS r{this, 'R'}, b{this, 'B'};
    int countR = r.Count(), countB = b.Count();
    if (countB + 2 <= countR || countR + 2 <= countB) {
        return "Impossible";
    }
    for (int i = 0; i < N; ++i) {
        r.NearBegin.emplace(Coordinate{0, i});
        r.NearEnd.emplace(Coordinate{N - 1, i});
        b.NearBegin.emplace(Coordinate{i, 0});
        b.NearEnd.emplace(Coordinate{i, N - 1});
    }
    if (r.Connect()) {  // 要通
        // 判 +1 即可， +2及以上 149判过
        if (r.NoCutPoint || countR + 1 == countB) {
            return "Impossible";
        }
        return "Red wins";
    }
    if (b.Connect()) {
        if (b.NoCutPoint || countB + 1 == countR) {
            return "Impossible";
        }
        return "Blue wins";
    }
    // 两个都不通
    return "Nobody wins";
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}
