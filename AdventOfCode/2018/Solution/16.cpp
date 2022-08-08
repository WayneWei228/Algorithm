#include <cstdio>
#include <vector>
using namespace std;

enum OpCode {
    Addr,
    Addi,
    Mulr,
    Muli,
    Banr,
    Bani,
    Borr,
    Bori,
    Setr,
    Seti,
    Gtir,
    Gtri,
    Gtrr,
    Eqir,
    Eqri,
    Eqrr,
};

struct Solution {
    vector<vector<bool>> E;
    vector<int> Matched;
    vector<bool> Visited;

    void Operate(vector<int>& m, OpCode op, int a, int b, int c) {
        switch (op) {
            case Addr:
                m[c] = m[a] + m[b];
                break;
            case Addi:
                m[c] = m[a] + b;
                break;
            case Mulr:
                m[c] = m[a] * m[b];
                break;
            case Muli:
                m[c] = m[a] * b;
                break;
            case Banr:
                m[c] = m[a] & m[b];
                break;
            case Bani:
                m[c] = m[a] & b;
                break;
            case Borr:
                m[c] = m[a] | m[b];
                break;
            case Bori:
                m[c] = m[a] | b;
                break;
            case Setr:
                m[c] = m[a];
                break;
            case Seti:
                m[c] = a;
                break;
            case Gtir:
                m[c] = a > m[b];
                break;
            case Gtri:
                m[c] = m[a] > b;
                break;
            case Gtrr:
                m[c] = m[a] > m[b];
                break;
            case Eqir:
                // 0 和 1 可以往 bool 反向思考，节约代码
                m[c] = a == m[b];
                break;
            case Eqri:
                m[c] = m[a] == b;
                break;
            case Eqrr:
                m[c] = m[a] == m[b];
                break;
        }
    }
    // 匈牙利算法求最大匹配问题
    // O(N ^ 3)
    // 因为是邻接矩阵所以最大是 O(N ^ 3)
    // Hungarian N -> Match Visited N -> If Match(Matched[i]) N
    // = N ^ 3;
    // 邻接表的话就是 O(nm)
    // m 为 边的总个数
    // n 为 总点数
    // 把总点数都放一侧无所谓，N 与 2N无差，但N必须是较大那一侧
    void Hungarian() {
        // 初始化，都没有match上
        Matched.resize(16, -1);
        for (int i = 0; i < 16; ++i) {
            Visited.clear();
            Visited.resize(16);
            Match(i);
        }
    }

    bool Match(int no) {
        for (int i = 0; i < 16; ++i) {
            // 有边且未访问
            if (E[no][i] && !Visited[i]) {
                Visited[i] = true;
                //当前还没匹配，或者原来匹配的左边元素还能再找到
                // Visited 不重制
                // 该节点经历过的不想要的Matched[i]不必再走，该节点想要的Matched[i]也不能走
                // 所以真正有效的是Match[i]走在Visited之后的时候
                if (Matched[i] == -1 || Match(Matched[i])) {
                    Matched[i] = no;
                    return true;
                }
            }
        }
        return false;
    }

    void Solve() {
        E.resize(16);
        for (int i = 0; i < 16; ++i) E[i].resize(16, true);
        vector<int> before(4), after(4);
        int total = 0;
        // O(16 * InputSize);
        while (scanf("Before: [%d, %d, %d, %d] ",  //
                     &before[0], &before[1],       //
                     &before[2], &before[3]) == 4) {
            int op, a, b, c;
            scanf("%d%d%d%d ", &op, &a, &b, &c);
            scanf("After:  [%d, %d, %d, %d] ",  //
                  &after[0], &after[1], &after[2], &after[3]);
            int answer = 0;
            for (int i = 0; i < 16; ++i) {
                vector<int> m(before);
                Operate(m, OpCode(i), a, b, c);
                // vector 可以直接 == 
                if (m == after) {
                    ++answer;
                } else {
                    // 纵向当前顺序, 横向 op 
                    // 邻接表
                    E[i][op] = false;
                }
            }
            if (3 <= answer) ++total;
        }
        printf("%d\n", total);
        Hungarian();
        vector<int> m{0, 0, 0, 0};
        int op, a, b, c;
        // O(InputSize);
        while (scanf("%d%d%d%d", &op, &a, &b, &c) == 4) {
            Operate(m, OpCode(Matched[op]), a, b, c);
        }
        printf("%d\n", m[0]);
        // maxO(InputSize) because InputSize > 16 ^ 3;
    }
};

int main() {
    Solution().Solve();
    return 0;
}
