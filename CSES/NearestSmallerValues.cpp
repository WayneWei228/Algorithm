#include <cstdio>
#include <stack>
using namespace std;

struct Solution {
    int N;
    stack<pair<int, int>> s;
    bool head = true;
    void Solve() {
        scanf("%d", &N);
        s.push(make_pair(0, 0));
        for (int i = 1; i <= N; i++) {
            int a; 
            scanf("%d", &a);
            while (!s.empty() && s.top().first >= a) {
                s.pop();
            }
            if (head) {
                printf("%d", s.top().second);
                head = false;
            } else {
                printf(" %d",s.top().second);
            }
            s.push(make_pair(a, i));
        }
        printf("\n");
    }
};

int main() {
    Solution().Solve();
    return 0;
}