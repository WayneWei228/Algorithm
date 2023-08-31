#include <cstdio>
#include <string>
using namespace std;

char Buffer[2000];

struct Solution {
    string Input;

    int Compute1() {
        int cnt = 0;
        Input += Input[0];
        for (int i = 0; i < int(Input.size()); ++i) {
            if (Input[i] == Input[i + 1]) {
                cnt += Input[i] - '0';
            }
        }
        Input.pop_back();
        return cnt;
    }

    int Compute2() {
        int cnt = 0;
        int totallen = Input.size();
        int len = Input.size() / 2;
        for (int i = 0; i < int(Input.size()); ++i) {
            if (Input[i] == Input[(i + len) % totallen]) {
                cnt += Input[i] - '0';
            }
        }
        return cnt;
    }

    void Solve() {
        scanf("%s", Buffer);
        Input = Buffer;
        printf("%d\n", Compute1());
        printf("%d\n", Compute2());
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    Solution().Solve();
    return 0;
}