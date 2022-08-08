#include <cstdio>
#include <vector>
using namespace std;

/*

大 IP 套 小 IP
两IP能合并

*/
struct Node {
    Node *C[2]{}; // children
    bool F = false;

    Node *Go(int d) { // 从当前点往d方向走 0 or 1 往下走
        if (!C[d]) C[d] = new Node; // 没这个孩子的话，构造孩子
        return C[d];
    }
};

struct Solution {
    int N;
    Node *Tree = new Node;

    void Solve(int caseNo) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            int n[4], s;
            scanf("%d.%d.%d.%d/%d", &n[0], &n[1], &n[2], &n[3], &s);
            unsigned ip = 0;
            // 00000000 00000000 00000000 00000000
            // n[0] n[1] n[2] n[3]
            ip = (ip << 8) + n[0];
            ip = (ip << 8) + n[1];
            ip = (ip << 8) + n[2];
            ip = (ip << 8) + n[3];
            vector<Node *> nodes;
            nodes.emplace_back(Tree);
            for (int i = 0; i < s; ++i) {
                int d = (ip >> (31 - i)) & 1;
                // 把走过的路存下来 
                nodes.emplace_back(nodes.back()->Go(d));
            }
            nodes.back()->F = true;
            nodes.pop_back();
            while (!nodes.empty()) {
                if (nodes.back()->Go(0)->F && nodes.back()->Go(1)->F) {
                    nodes.back()->F = true;
                } else {
                    break;
                }
                nodes.pop_back();
            }
        }
        printf("Case #%d:\n", caseNo);
        DFSPrint(Tree, 0, 0);
    }

    // caution : new Node != Null
    // new = creat 
    void DFSPrint(Node *n, int d, unsigned p) { // d = depth, p = prefix
        if (!n) return; // NULL
        if (n->F) return Print(d, p);
        DFSPrint(n->C[0], d + 1, p + p); // p + p = p << 1
        DFSPrint(n->C[1], d + 1, p + p + 1); // p + p + 1 = p << 1 + 1
        // 如果是 n->Go(0) 会爆内存  2^32
    }

    // unsigned >> 时，补0
    // int >> 时，补最高位数
    // int 1000 >> 2 = 1110
    // unsigned 1000 >> 2 = 0010
    void Print(int d, unsigned p) {
        p <<= 32 - d;
        int n[4];
        // 只取右8位，故左边拿什么补无所谓
        n[3] = 0xff & p;
        n[2] = 0xff & (p >> 8);
        n[1] = 0xff & (p >> 16);
        n[0] = 0xff & (p >> 24);
        printf("%d.%d.%d.%d/%d\n", n[0], n[1], n[2], n[3], d);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}