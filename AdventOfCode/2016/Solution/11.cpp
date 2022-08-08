#include <cstdio>
#include <queue>
#include <string>
#include <unordered_map>
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

uint64 Fingerprint(const vector<int>& x) {
    uint64 answer = 0;
    for (int i : x) answer = Fingerprint(answer + i);
    return answer;
}

char Buffer[80];

struct Node {
    vector<int> State;
    int Elevator, Distance, F;

    Node& ComputeF() {
        F = 0;
        for (int i : State) F += 3 - i;
        F = Distance + F / 2;  // 一次拉两个
        return *this;
    }

    bool operator<(const Node& that) const {
        return that.F < F;
    }  // F越小，优先级越高

    uint64 H() const { return Fingerprint(State) + Elevator; }

    bool Finish() const {  // 不对Node里变量进行修改
        for (int i : State) {
            if (i != 3) return false;
        }
        return true;
    }

    bool Valid() const {
        for (int i = 0; i < State.size(); i += 2) {  // microchip
            if (!Valid(i)) return false;
        }
        return true;
    }

    bool Valid(int no) const {
        if (State[no] == State[no + 1]) return true;  // 在同一层
        for (int i = 1; i < State.size(); i += 2) {   // generator
            if (State[no] == State[i])
                return false;  // 没供上电还跟其他generator在一起
        }
        return true;
    }

    Node ChildType1(int eNext, int index0) const {
        Node answer{State, eNext, Distance + 1};
        answer.State[index0] = eNext;  // 把这个物品移到eNext去
        return answer.ComputeF();
    }

    Node ChildType2(int eNext, int index0, int index1) const {
        Node answer{State, eNext, Distance + 1};
        answer.State[index0] = eNext;
        answer.State[index1] = eNext;
        return answer.ComputeF();
    }

    vector<Node> Children() const {
        vector<Node> answer;
        auto add = [&](Node&& node) {  // add 是函数
            if (node.Valid()) answer.emplace_back(move(node));
        };
        for (int eNext : vector<int>{Elevator - 1, Elevator + 1}) {
            // 电梯可上可下
            if (0 <= eNext && eNext < 4) {
                for (int i = 0; i < State.size(); ++i) {
                    if (State[i] != Elevator)
                        continue;               // 不在一层不能走
                    add(ChildType1(eNext, i));  // 移一个
                    for (int j = i + 1; j < State.size(); ++j) {
                        if (State[j] != Elevator) continue;
                        add(ChildType2(eNext, i, j));  // 移两个
                    }
                }
            }
        }
        return answer;
    }
};

struct Solution {
    int Search(const vector<int>& state) {
        priority_queue<Node> queue;
        unordered_map<uint64, int> visited;  // node判重
        Node initial{state, 0, 0};
        visited.emplace(initial.H(), initial.ComputeF().F);
        queue.emplace(move(initial));
        while (!queue.empty()) {
            auto top = queue.top();
            queue.pop();
            if (visited[top.H()] < top.F) continue;
            // visited里面包含top
            // 我见过跟top一样的状态，但是见过的比现在的好
            if (top.Finish()) return top.Distance;
            for (auto& i : top.Children()) {
                uint64 h = i.H();
                auto it = visited.find(h);
                if (it != visited.end() && it->second <= i.F)
                    continue;  // 状态 和 F 都一样 所以不需要它
                visited[h] = i.F;
                queue.emplace(move(i));
            }
        }
        return 0;
    }

    void Solve() {
        unordered_map<string, int[2]> at;
        // 0 is microchip 1 is generator
        for (int i = 0; i < 4; ++i) {
            scanf("The %*s floor contains a ");
            // scanf 读入发现错误时停止，
            while (true) {
                scanf("%[^- ] ", Buffer);
                string s0 = Buffer;  // 元素
                if (s0 == "nothing") {
                    scanf("%*s ");
                    break;
                }
                scanf("-compatible ");
                // 剩下字符为 generator or microchip
                scanf("%[^,. ] ", Buffer);
                string s1 = Buffer;
                bool isGenerator = s1 == "generator";
                at[s0][isGenerator] = i;
                int nchars = 0;
                scanf(".%n ", &nchars);
                if (nchars == 1) break;
                scanf(", ");
                scanf(" and ");
                scanf(" a ");
            }
        }
        vector<int> state;
        for (const auto& i : at) {
            for (const auto& j : i.second) state.emplace_back(j);
            // microchip 和 generator 相邻 ,
            // M is even, G is odd
        }
        printf("%d\n", Search(state));
        for (int i = 0; i < 4; ++i) state.emplace_back(0);
        printf("%d\n", Search(state));
    }
};

int main() {
    Solution().Solve();
    return 0;
}