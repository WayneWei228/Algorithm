#include <cstdio>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Solution {
    vector<int> Out[26];
    vector<bool> Visited;
    string FinishSequence;

    void DFS(int no) {
        if (Visited[no]) return;
        Visited[no] = true;
        // 每次访问都是最大的先
        for (int i : Out[no]) DFS(i);
        FinishSequence += 'A' + no;
        // 存放字母序最大到最小的拓扑排序
    }

    string Solve0() {
        // O(v + e)
        // 复杂度跟 e 有关，
        // 因为哪怕这个点访问过了，通往这个点的路还得走一遍
        for (int i = 0; i < 26; ++i) {
            sort(Out[i].begin(), Out[i].end(),
                 [](int a1, int a2) { return a2 < a1; });
            // 由大到小排序
        }
        Visited.resize(26);
        // 由最大字母开始访问
        for (int i = 25; i >= 0; --i) {
            DFS(i);
        }
        // DFS的结束顺序的逆序 就是 拓扑排序
        // 拓扑排序只要别出现没有满足前置条件就访问的，就行。
        reverse(FinishSequence.begin(), FinishSequence.end());
        return FinishSequence;
    }

    int Solve1() {
        vector<int> inDegree;       // 每个点的入度量
        priority_queue<int> ready;  // 准备接受任务队列
        inDegree.resize(26);
        for (int i = 0; i < 26; ++i) {
            for (int j : Out[i]) ++inDegree[j];
        }
        for (int i = 0; i < 26; ++i) {
            if (inDegree[i] == 0) ready.emplace(-i);
            // 存 -i 字母序从小到大排
        }

        // 目前有五个任务可提供
        int available = 5;
        vector<vector<int>> finish(1);  // 外层大小是 1
        // O max(86 * 26);
        for (int i = 0; i < finish.size(); ++i) {
            for (int j : finish[i]) {  // 任务完成
                ++available;
                for (int k : Out[j]) {  // j 任务完成， j出口的点入度 -1
                                        // 若入度为 0，加入ready
                    if (--inDegree[k] == 0) ready.emplace(-k);
                }
            }
            while (0 < available && !ready.empty()) {
                // 添加任务 到时间完成什么
                --available;
                int top = -ready.top();
                ready.pop();
                // 当前时间加上完成此任务时间为 newFinish
                int newFinish = i + 61 + top;
                if (finish.size() < newFinish + 1) {
                    finish.resize(newFinish + 1);
                }
                finish[newFinish].emplace_back(top);
                // 在那个时间完成 字母 top （用int表示）
            }
        }
        return finish.size() - 1;
    }

    void Solve() {
        while (true) {
            char v1, v2;
            if (scanf("Step %c %*[^p]p %c can begin. ", &v1, &v2) < 2) {
                break;
            }
            Out[v1 - 'A'].emplace_back(v2 - 'A');
            // 将接下来要去的邻点加入现点列表中
        }
        printf("%s\n", Solve0().c_str());
        printf("%d\n", Solve1());
    }
};

int main() {
    Solution().Solve();
    return 0;
}