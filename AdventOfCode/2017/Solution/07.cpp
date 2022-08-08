#include <cstdio>
#include <limits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

struct Program {
    int Weight;
    vector<string> Children;
};

char Buffer[80];

struct Solution {
    unordered_map<string, Program> Tree;
    int Correction;

    string FindRoot() {
        unordered_set<string> nodes;
        for (const auto& i : Tree) nodes.emplace(i.first);
        for (const auto& i : Tree) {
            for (const auto& j : i.second.Children) nodes.erase(j);
        }
        for (const auto& i : nodes) return i;
        return {};
    }

    int Balance(const string& key) {
        const Program& value = Tree.at(key);
        if (value.Children.empty()) return value.Weight;
        unordered_map<int, int> count; // 子weight 对应 次数
        vector<int> balance; // 存 子weight
        for (const string& i : value.Children) {
            int b = Balance(i);
            ++count[b];
            balance.emplace_back(b);
        }
        for (auto i : balance) {
            cout << i << " ";
        }
        cout << endl;
        int max = numeric_limits<int>::min(), argmax = -1;
        for (const auto& i : count) { // 正确的则是出现最多次的
            if (max < i.second) {
                max = i.second;
                argmax = i.first; // 正确的值
            }
        }
        if (max != value.Children.size()) { // 有异常
            for (int i = 0; i < balance.size(); ++i) {
                if (balance[i] != argmax) {
                    cout << value.Children[i] << endl;
                    int oldWeight = Tree[value.Children[i]].Weight;
                    Correction = oldWeight - balance[i] + argmax;
                    // Correction = argmax - balance[i];
                    cout << oldWeight << endl;
                }
            }
        }
        return value.Weight + int(value.Children.size()) * argmax;
    }

    void Solve() {
        while (true) {
            Program p;
            int nchars = 0;
            int result =
                scanf("%s (%d) -> %n", Buffer, &p.Weight, &nchars);
            if (result < 2) break;
            auto& p0 = Tree.emplace(Buffer, move(p)).first->second;
            if (nchars == 0) continue;
            while (true) {
                char c = '\n';
                scanf("%[^,\n]%c ", Buffer, &c);
                p0.Children.emplace_back(Buffer);
                if (c != ',') break;
            }
        }
        string root = FindRoot();
        printf("%s\n", root.c_str());
        Balance(root);
        printf("%d\n", Correction);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
