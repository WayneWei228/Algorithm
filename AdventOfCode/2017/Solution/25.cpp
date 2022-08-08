#include <cstdio>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Strings {
    unordered_map<string, int> ToID;

    int ID(const string& s) {
        // 无论是否成功加入 ToID.emplace(s, ToID.size()).first 都指向
        // iterator 本题中 ->second 指的是此string 对应的 ID
        return ToID.emplace(s, ToID.size()).first->second;
    }
};

struct NextEntry {
    int Write, Move, State;
};

template <typename T>
struct InfiniteArray {
    deque<T> Data;
    int Offset = 0;

    T& operator[](int n) {
        n += Offset;
        while (int(Data.size()) <= n) Data.emplace_back();
        while (n < 0) {
            Data.emplace_front();
            ++Offset;
            ++n;
        }
        return Data[n];
    }
};

char Buffer[80];

struct Solution {
    vector<vector<NextEntry>> Next;
    int State, Cursor = 0, Counter;
    InfiniteArray<int> Tape{{0}};
    Strings S;

    /*
    Begin in state A.
    Perform a diagnostic checksum after 12586542 steps.

    In state A:
      If the current value is 0:
        - Write the value 1.
        - Move one slot to the right.
        - Continue with state B.
      If the current value is 1:
        - Write the value 0.
        - Move one slot to the left.
        - Continue with state B.
    */

    void Solve() {
        scanf("Begin in state %[^.]. ", Buffer);
        State = S.ID(Buffer);
        scanf("Perform %*[^0123456789] %d steps. I", &Counter);
        while (scanf("n state %[^:]: ", Buffer) == 1) {
            int state = S.ID(Buffer);
            if (Next.size() <= state) Next.resize(state + 1);
            int current, write;
            while (scanf("If %*[^0123456789] %d: ", &current) == 1) {
                // 把 I 也读了
                scanf("- Write the value %d. ", &write);
                scanf("- Move one slot to the %[^.]. ", Buffer);
                string direction = Buffer;
                int move = direction == "left" ? -1 : 1;
                scanf("- Continue with state %[^.]. ", Buffer);
                int newState = S.ID(Buffer);
                while (Next[state].size() <= current) {
                    Next[state].resize(current + 1);
                }
                // eg. state 是 A (对应ID 为 1) current value is 0 ,
                // Next[1][0] 为 NextEntry
                Next[state][current] = NextEntry{write, move, newState};
            }
        }

        for (auto i : Next) {
            for (auto j : i) {
                printf("%d %d %d\n", j.Write, j.Move, j.State);
            }
        }

        for (int i = 0; i < Counter; ++i) {
            auto& at = Tape[Cursor];
            auto& next = Next[State][at];
            at = next.Write;
            Cursor += next.Move;
            State = next.State;
        }
        int answer = 0;
        for (int i : Tape.Data) answer += i;
        printf("%d\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
