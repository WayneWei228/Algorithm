#include <cstdio>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// 本题其实只有一个解， 最短解

// best first search : A* 的变种
// 最快速度出解 （不保证最优
// 方法：设置点到目的地的下界来确定优先级
// A* 广搜基础上， 对每个点估计到目的地的下界, 得出原点到目的地的下界， 下界最小的为头首

// 广搜是A*的特殊情况 点到目的地的下界设置为0就是广搜

// A* 下界可以自己设置，因而产出更好方法
struct Rule {
    string From, To;
};

struct Node {
    string S;
    int N;

    // a <= b
    // ! (b < a)
    // a == b
    // ! (a < b) && ! (b < a)
    bool operator<(const Node& that) const { // 字符串最短的放在前面, 从候选中取最短
        return S.size() > that.S.size();     // 系统判断两个object大小永远调用 < operator
    }
    // size大的为 True, 在小于号左边, size小的在右边, 所以size越小在越前面
};

char Buffer[600], Buffer1[80];

struct Solution {
    vector<Rule> Rules; // 存储规则
    string Input;

    vector<string> Next(const string& s,  // 返回一条规律的所有可能结果
                        const string& from, const string& to) { 
        vector<string> answer;
        int index = -1;
        while (true) { // 一条规律, 在整个string实行一遍
            index = s.find(from, index + 1);
            if (index == -1) break;
            string answer1(s.begin(), s.begin() + index);
            answer1.append(to);
            answer1.append(s.begin() + index + from.size(), s.end());
            answer.emplace_back(move(answer1)); // move() 把answer1加入后删除
        }
        return answer;
    }

    void Solve() {
        while (true) {
            int result = scanf("%s => %s", Buffer, Buffer1);
            if (result == 2) {
                Rules.emplace_back(Rule{Buffer, Buffer1});
            } else if (result == 1) {
                Input = Buffer;
            } else {
                break;
            }
        }
        unordered_set<string> answer;
        for (const auto& i : Rules) {
            for (string& j : Next(Input, i.From, i.To)) {
                answer.emplace(move(j));
            }
        }
        printf("%d\n", int(answer.size()));
        answer.clear();
        priority_queue<Node> nodes;
        nodes.emplace(Node{Input, 0});
        answer.emplace(Input);
        while (!nodes.empty()) {
            auto s = nodes.top().S;
            auto n = nodes.top().N;
            nodes.pop();
            for (const auto& i : Rules) {
                for (string& j : Next(s, i.To, i.From)) { // 注意∆ 由 To 到 From
                    if (answer.count(j)) continue; // 已出现过不处理增加效率
                    if (j == "e") {
                        printf("%d\n", n + 1);
                        return; // 最快找到解
                    }
                    nodes.emplace(Node{j, n + 1});
                    answer.emplace(move(j));
                }
            }
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}
