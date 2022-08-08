#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

char Buffer[80];
// Sue 1: goldfish: 9, cars: 0, samoyeds: 9
struct Aunt {
    unordered_map<string, int> Properties;

    Aunt(const string& input) { // 一段一段输入 运用 %n
        int position = 0, nchars;
        sscanf(input.c_str() + position, "Sue %*d: %n", &nchars);
        // cout << "fnchars " << nchars << endl;
        position += nchars;
        while (true) {
            int number;
            nchars = 0;
            sscanf(input.c_str() + position, " %[^:]: %d,%n", Buffer, // %[] 不吃空格, 前面放一个空格就可以消灭所有空格，输入没空格也没事
                   &number, &nchars);
            // cout << "nchars " << nchars << endl;
            // cout << "buffer " << Buffer << endl;
            // 必须在break之前, 因为最后一个不带逗号, 读到逗号则中断
            Properties[Buffer] = number;
            if (nchars == 0) break;
            position += nchars;
        }
    }
};

struct Solution {
    Aunt Sue{
        "Sue 0: children: 3, cats: 7, samoyeds: 2, "
        "pomeranians: 3, akitas: 0, vizslas: 0, goldfish: 5, "
        "trees: 3, cars: 2, perfumes: 1"};
    vector<Aunt> Aunts;

    bool Match1(const Aunt& aunt) {
        for (const auto& i : aunt.Properties) {
            if (i.second != Sue.Properties[i.first]) return false;
        }
        return true;
    }

    bool Match2(const Aunt& aunt) {
        for (const auto& i : aunt.Properties) {
            if (i.first == "cats" || i.first == "trees") {
                if (i.second <= Sue.Properties[i.first]) return false;
            } else if (i.first == "pomeranians" ||
                       i.first == "goldfish") {
                if (Sue.Properties[i.first] <= i.second) return false;
            } else {
                if (i.second != Sue.Properties[i.first]) return false;
            }
        }
        return true;
    }

    void Solve() {
        while (scanf("%[^\n]\n", Buffer) == 1) {
            Aunts.emplace_back(Buffer);
        }
        for (int i = 0; i < Aunts.size(); ++i) {
            if (Match1(Aunts[i])) {
                printf("%d\n", i + 1);
                break;
            }
        }
        for (int i = 0; i < Aunts.size(); ++i) {
            if (Match2(Aunts[i])) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}