#include <cstdio>
#include <string>
#include <vector>
using namespace std;

char Buffer[80], Buffer1[80];

struct Solution {
    vector<string> origin{".#.", "..#", "###"};
    vector<string> test;
    vector<vector<pair<string, string>>> input;
    int size;

    void Read(const string& l, const string& r) {
        string a = "", b = "";
        int cnta = 0;
        for (int i = 0; i < int(l.size()); i++) {
            if (l[i] != '/') {
                a += l[i];
            } else {
                cnta++;
            }
        }
        for (int i = 0; i < int(r.size()); i++) {
            if (r[i] != '/') {
                b += r[i];
            }
        }
        input[cnta + 1].emplace_back(make_pair(a, b));
    }

    string match(const vector<string>& v, int size) {
        string s1 = "";
        string s2 = "";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                s1 += v[i][j];
                s2 += v[j][i];
            }
        }
        for (const auto& i : input[size]) {
            if (s1 == i.first || s2 == i.first) return i.second; 
        }
        s1.clear();
        s2.clear();
        for (int i = 0; i < size; i++) {
            for (int j = size - 1; j >= 0; j--) {
                s1 += v[i][j];
                s2 += v[j][i];
            }
        }
        for (const auto& i : input[size]) {
            if (s1 == i.first || s2 == i.first) return i.second; 
        }
        s1.clear();
        s2.clear();
        for (int i = size - 1; i >= 0; i--) {
            for (int j = 0; j < size; j++) {
                s1 += v[i][j];
                s2 += v[j][i];
            }
        }
        for (const auto& i : input[size]) {
            if (s1 == i.first || s2 == i.first) return i.second; 
        }
        s1.clear();
        s2.clear();
        for (int i = size - 1; i >= 0; i--) {
            for (int j = size - 1; j >= 0; j--) {
                s1 += v[i][j];
                s2 += v[j][i];
            }
        }
        for (const auto& i : input[size]) {
            if (s1 == i.first || s2 == i.first) return i.second; 
        }
        return "";
    }

    vector<string> Chai2() {
        int k = size / 2;
        size += k;
        vector<string> res;
        res.resize(size);
        for (auto& i : res) i.resize(size);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int a = i * 2;
                int b = j * 2;
                int c = i * 3;
                int d = j * 3;
                vector<string> v;
                v.resize(2);
                for (auto& i : v) i.resize(2);
                for (int x = a; x < a + 2; x++) {
                    for (int y = b; y < b + 2; y++) {
                        v[x - a][y - b] = test[x][y];
                    }
                }
                string s = move(match(v, 2));
                int n = 0;
                for (int x = c; x < c + 3; x++) {
                    for (int y = d; y < d + 3; y++) {
                        res[x][y] = s[n++];
                    }
                }
            }
        }
        return res;
    }

    vector<string> Chai3() {
        int k = size / 3;
        size += k;
        vector<string> res;
        res.resize(size);
        for (auto& i : res) i.resize(size);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int a = i * 3;
                int b = j * 3;
                int c = i * 4;
                int d = j * 4;
                vector<string> v;
                v.resize(3);
                for (auto& i : v) i.resize(3);
                for (int x = a; x < a + 3; x++) {
                    for (int y = b; y < b + 3; y++) {
                        v[x - a][y - b] = test[x][y];
                    }
                }
                string s = move(match(v, 3));
                int n = 0;
                for (int x = c; x < c + 4; x++) {
                    for (int y = d; y < d + 4; y++) {
                        res[x][y] = s[n++];
                    }
                }
            }
        }
        return res;
    }

    void Solve() {
        input.resize(10);
        while (scanf("%s => %s ", Buffer, Buffer1) == 2) {
            string l = Buffer, r = Buffer1;
            Read(l, r);
        }
        test = origin;
        size = 3;
        for (int i = 0; i < 5; i++) {
            if (size % 2 == 0) {
                test = move(Chai2());
            } else if (size % 3 == 0) {
                test = move(Chai3());
            }
        }
        int ans1 = 0;
        for (auto i : test) {
            for (auto j : i) {
                if (j == '#') ans1++;
            }
        }
        printf("%d\n", ans1);
        // test.clear();
        // test = origin;
        // size = 3;
        int ans2 = 0;
        for (int i = 0; i < 13; i++) { // 
            if (size % 2 == 0) {
                test = move(Chai2());
            } else if (size % 3 == 0) {
                test = move(Chai3());
            }
        }
        for (auto i : test) {
            for (auto j : i) {
                if (j == '#') ans2++;
            }
        }
        printf("%d\n", ans2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}