#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char Buffer[80];

struct Solution {
    enum Direction { N, NW, SW, S, SE, NE };
    unordered_map<string, Direction> ToDirection;
    vector<Direction> Input;

    int Distance(const vector<int>& c) {
        int maxC = *max_element(c.begin(), c.end());
        int minC = *min_element(c.begin(), c.end());
        return maxC - minC;
    }

    void Solve() {
        ToDirection["n"] = N;
        ToDirection["nw"] = NW;
        ToDirection["sw"] = SW;
        ToDirection["s"] = S;
        ToDirection["se"] = SE;
        ToDirection["ne"] = NE;
        vector<int> current(3);
        int answer2 = 0;
        while (scanf("%[^,],", Buffer) == 1) {
            switch (ToDirection[Buffer]) {
                case N:
                    ++current[0];
                    break;
                case NW:
                    --current[1];
                    break;
                case SW:
                    ++current[2];
                    break;
                case S:
                    --current[0];
                    break;
                case SE:
                    ++current[1];
                    break;
                case NE:
                    --current[2];
                    break;
            }
            int distance = Distance(current);
            if (answer2 < distance) answer2 = distance;
        }
        int answer1 = Distance(current);
        printf("%d\n%d\n", answer1, answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
