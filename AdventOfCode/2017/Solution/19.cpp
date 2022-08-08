#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int DX[4]{0, -1, 0, 1}, DY[4]{1, 0, -1, 0}, DD[3]{0, 1, 3};

struct State {
    int X, Y, Direction;
};

char Buffer[300];

struct Solution {
    vector<string> Map;

    bool Go(State& state) {
        for (int i = 0; i < 3; ++i) {
            int newDirection = (state.Direction + DD[i]) % 4;
            State newState{state.X + DX[newDirection],
                           state.Y + DY[newDirection], newDirection};
            if (newState.X < 0 || Map.size() <= newState.X) continue;
            if (newState.Y < 0 || Map[0].size() <= newState.Y) continue;
            if (Map[newState.X][newState.Y] == ' ') continue;
            state = move(newState);
            return true;
        }
        return false;
    }

    void Solve() {
        while (scanf("%[^\n]%*c", Buffer) == 1) {
            Map.emplace_back(Buffer);
        }
        State state{0, int(Map[0].find('|')), 3};
        string answer1;
        int answer2 = 1;
        while (Go(state)) {
            char c = Map[state.X][state.Y];
            if (isalpha(c)) answer1 += c;
            ++answer2;
        }
        printf("%s\n%d\n", answer1.c_str(), answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
