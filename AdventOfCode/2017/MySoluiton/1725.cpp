#include <cstdio>
#include <deque>
#include <string>
#include <unordered_map>
using namespace std;

char Buffer[80];

template <typename T>
struct InfiniteArray {
    deque<T> Data;
    int Offset = 0;

    T& operator[](int n) {
        n += Offset;
        while (int(Data.size()) <= n) Data.emplace_back(0);
        while (n < 0) {
            Data.emplace_front(0);
            ++Offset;
            ++n;
        }
        return Data[n];
    }
};

struct Solution {
    enum States { A, B, C, D, E, F } Sta;
    unordered_map<string, States> ToState;
    int steps;
    InfiniteArray<int> q;

    void Solve() {
        ToState.emplace("A", States::A);
        scanf("Begin in state %c.\n", Buffer);
        scanf("Perform a diagnostic checksum after %d steps. ", &steps);
        string s = Buffer;
        Sta = ToState[s];
        int no = 0;
        q.Data.emplace_back(0);


        for (int i = 0; i < steps; i++) {
            switch (Sta) {
                case A:
                    if (!q[no]) {
                        q[no] = 1;
                        no++;
                    } else {
                        q[no] = 0;
                        no--;
                    }
                    Sta = States::B;
                    break;
                case B:
                    if (!q[no]) {
                        no++;
                        Sta = States::C;
                    } else {
                        no--;
                        Sta = States::B;
                    }
                    break;
                case C:
                    if (!q[no]) {
                        q[no] = 1;
                        no++;
                        Sta = States::D;
                    } else {
                        q[no] = 0;
                        no--;
                        Sta = States::A;
                    }
                    break;
                case D:
                    if (!q[no]) {
                        q[no] = 1;
                        no--;
                        Sta = States::E;
                    } else {
                        no--;
                        Sta = States::F;
                    }
                    break;
                case E:
                    if (!q[no]) {
                        q[no] = 1;
                        no--;
                        Sta = States::A;
                    } else {
                        q[no] = 0;
                        no--;
                        Sta = States::D;
                    }
                    break;
                case F:
                    if (!q[no]) {
                        q[no] = 1;
                        no++;
                        Sta = States::A;
                    } else {
                        no--;
                        Sta = States::E;
                    }
                    break;
                default:
                    break;
            }
        }
        printf("%d\n", int(q.Data.size()));
        int ans = 0;
        for (const int& i  : q.Data) {
            if (i == 1) ans++;
        }
        printf("\n");
        printf("%d\n", ans);
    }
};

int main() {
    Solution().Solve();
    return 0;
}