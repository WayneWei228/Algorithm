#include <cstdio>
#include <vector>
using namespace std;

struct Disc {
    int Size, Start;
};

struct Solution {
    vector<Disc> Input;

    int InputAt(int no, int time) {
        return (time + (no + 1) + Input[no].Start) % Input[no].Size;
    }

    bool InputsAt0(int time) {
        for (int i = 0; i < Input.size(); ++i) {
            if (InputAt(i, time) != 0) return false;
        }
        return true;
    }

    int GetTime() {
        int time = 0;
        while (!InputsAt0(time)) ++time;
        return time;
    }

    void Solve() {
        while (true) {
            int size, start;
            if (scanf("Disc #%*d has %d %*[^,], it is at position %d. ",
                      &size, &start) < 2) {
                break;
            }
            Input.emplace_back(Disc{size, start});
        }
        printf("%d\n", GetTime());
        Input.emplace_back(Disc{11, 0});
        printf("%d\n", GetTime());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
