#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// ktlj (57)
// fwft (72) -> ktlj, cntj, xhth

char Buffer0[80], Buffer1[80], Buffer2[80], Buffer3[80];
;

struct Node {
    string father;
    vector<string> Children;
    int weight;
};

struct Solution {
    vector<Node> Input;
    unordered_map<string, Node> M;
    string ans1;

    int Reset(const string& s) { // 返回当前program的总和
        if (int(M[s].Children.size()) == 0) {
            return M[s].weight;
        }
        int total = 0;
        for (const auto& i : M[s].Children) {
            total += Reset(i);
        }
        M[s].weight += total;
        return M[s].weight; 
    }


    // Fail!!
    // 只有底层相同才能递推上层
    // 左边 1， 下面 1， 2 右边 4
    
    string Change(const string& s) {
        unordered_set<int> children;

        cout << s << "  list of weights : ";
        for (const auto& i : M[s].Children) {
            cout << M[i].weight << " ";
            children.emplace(M[i].weight);
        }
        cout << endl;
        if (children.size() == 1 || children.size() == 0) {
            return s;
        }
        int cnt = 0;

        for (auto i : M[s].Children) {
            if (M[s].weight == *children.begin()) {
                cnt++;
            }
        }
        int value;
        vector<int> v(children.begin(), children.end());
        (cnt == 1) ? value = v[0] : value = v[1];
        for (auto i : M[s].Children) {
            if (M[i].weight == value) {
                return Change(i);
            }
        }
        return "";
    }

    void Solve() {
        int weight;
        int nchar1 = 0, nchar2 = 0;

        while (scanf("%s (%d) ->%n ", Buffer0, &weight, &nchar1) >= 2) {
            string s = Buffer0;
            M[s].weight = weight;
            if (nchar1 == 0) continue;
            while (scanf("%[^,\n], %n", Buffer0, &nchar1) == 1) {
                string s1 = Buffer0;
                M[s].Children.emplace_back(s1);
                M[s1].father = s;
                if (nchar1 == 0) break;
                nchar1 = 0;
            }
        }

        for (auto i : M) {
            if (i.second.father == "") {
                ans1 = i.first;
            }
        }
        printf("%s\n", ans1.c_str());

        // for (auto i : M) {
        //     cout << i.first << " father " << i.second.father
        //          << " value " << i.second.weight << " : ";
        //     for (auto j : i.second.Children) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        cout << M["ifajhb"].weight << endl;
        Reset(ans1);
        cout << endl;

        // for (auto i : M) {
        //     cout << i.first << " " << i.second.weight << endl;
        // }

        string wrong = Change(ans1);
        cout << wrong << endl;

        int diff;
        string father = M[wrong].father;
        for (auto i : M[father].Children) {
            if (i != wrong) {
                diff = M[i].weight - M[wrong].weight;
                break;
            }
        }
        int wrong_origin = M[wrong].weight - int(M[wrong].Children.size()) * M[M[wrong].Children[0]].weight;
        int ans2 = wrong_origin + diff;
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}