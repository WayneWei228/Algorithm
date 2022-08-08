#include <cctype>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string ReadString() {
    string result;
    int c;
    do {
        // 先读一个字符
        c = getchar();
        // 不是空白符停止
    } while (isspace(c));

    do {
        // 因之前 c 先了存一个不是空白符的字符
        // result 加上 c
        result += c;
        // 接着读
        c = getchar();
        // 只要不是space继续读
    } while (!isspace(c));
    return result;
}

struct Vertex {
    int Color;
    vector<string> Out;
};

struct Solution {
    unordered_map<string, Vertex> V;

    void Solve(int caseNo) {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            string v1 = ReadString(), v2 = ReadString();
            V[v1].Out.emplace_back(v2);
            V[v2].Out.emplace_back(v1);
        }
        printf("Case #%d: %s\n", caseNo, Bipartite() ? "Yes" : "No");
    }

    // 二分图判定：判断是否为二分图
    // or 把一个图二染色 twocoloring
    // 基本方法 敌人的敌人就是朋友
    // 做 DFS 每次记录当前点颜色，然后把当前点邻居全都换成与当前点相反的颜色
    // 没颜色赋颜色
    // 有颜色判断是否为异色
    // DFS 放该节点会考虑所有链接路径的节点情况
    // 复杂度线性 O(n + m);

    bool Bipartite() {
        for (auto& vi : V) {
            // 有一个失败就是失败
            if (vi.second.Color == 0 && !ColorOK(vi.second, 1)) {
                return false;
            }
        }
        return true;
    }

    bool ColorOK(Vertex& vi, int color) {
        // 给该string赋颜色
        vi.Color = color;
        for (const string& i : vi.Out) {
            // 如果敌人也为同颜色，return false
            if (V[i].Color == color) return false;
            // 敌人无颜色但是不能赋新颜色，return false
            // 一共就 1，2两个颜色
            // 没颜色才能赋颜色
            if (V[i].Color == 0 && !ColorOK(V[i], 3 - color)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}