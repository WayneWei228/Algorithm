#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer[21];

/*
多变量排序
创建结构体写operator
*/

struct Person {
    string Name;
    int Count;

    bool operator<(const Person& that) const {
        if (Count != that.Count) return that.Count < Count;
        return Name < that.Name;
    }
};

struct Solution {
    int N;
    vector<Person> S;

    void Solve(int caseNo) {
        scanf("%d", &N);
        S.resize(N);
        for (auto& i : S) {
            scanf("\n%[^\n]", Buffer);
            i.Name = Buffer;
            unordered_set<char> u;
            for (char j : i.Name) {
                if (isupper(j)) u.emplace(j);
            }
            i.Count = u.size();
        }
        printf("Case #%d: %s\n", caseNo,
               min_element(S.begin(), S.end())->Name.c_str());
        // min_element(S.begin(), S.end())->Name.c_str()
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) Solution().Solve(i);
    return 0;
}
 