#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Solution {
    vector<int> Input;
    unordered_map<string, int> M;
    int len;
    int Answer1 = 0, Answer2 = 0;

    void Move(vector<int>& input) {
        auto Max_pos = max_element(input.begin(), input.end());
        int Max_Value = *Max_pos;
        *Max_pos = 0;
        int inc = Max_Value / len;
        int left = Max_Value % len;
        if (inc != 0) {
            for (auto& i : input) {
                i += inc;
            }
        }
        for (int i = 0; i < left; ++i) {
            Max_pos++;
            if (Max_pos == input.end()) Max_pos = input.begin();
            *Max_pos += 1;
        }
    }

    string Convert(const vector<int>& input) {
        string s = "";
        for (auto i : input) {
            s += to_string(i);
        }
        return s;
    }

    void Solve() {
        int num;
        while (scanf("%d ", &num) == 1) {
            Input.emplace_back(num);
        }
        len = int(Input.size());
        vector<int> a(Input);
        string s = Convert(a);
        M[s] = 1;
        int steps = 2;
        int first_appear = -1;
        while (true) {
            Move(a);
            string no = Convert(a);
            if (M[no] != 0) {
                first_appear = M[no];
                break;
            }
            M[no] = steps;
            steps++;
        }
        printf("%d\n", steps - 1);
        printf("%d\n", steps - first_appear);
    }
};

int main() {
    Solution().Solve();
    return 0;
}