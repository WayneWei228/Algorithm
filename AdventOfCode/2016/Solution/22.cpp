#include <cstdio>
#include <cstdlib>
#include <memory>
#include <vector>
#include <string>
using namespace std;

struct Server {
    int X, Y, Used, Free;
};

struct Solution {
    vector<Server> Input;
    int XSize = 0, YSize = 0;

    char Show(const Server& s) {
        if (100 <= s.Used) return '#';
        if (s.X == XSize - 1 && s.Y == 0) return 'G';
        if (s.X == 0 && s.Y == 0) return 'g';
        if (s.Used == 0) return '_';
        return '.';
    }

    int Distance(int sX, int sY, int tX, int tY) {
        return abs(tX - sX) + abs(tY - sY);
    }
//  Filesystem            Size  Used  Avail  Use%
// /dev/grid/node-x0-y0   10T    8T     2T   80%
    void Solve() {
        scanf("%*[^%]%% ");
        while (true) {
            Server server;
            if (scanf("/dev/grid/node-x%d-y%d%*dT%dT%dT%*d%% ",  //
                      &server.X, &server.Y,                      //
                      &server.Used, &server.Free) < 4) {
                break;
            }
            Input.emplace_back(move(server));
        }
        int answer = 0;
        for (const auto& i : Input) {
            for (const auto& j : Input) {
                if (&i == &j) continue;
                if (i.Used != 0 && i.Used <= j.Free) ++answer;
            }
        }
        printf("%d\n", answer);
        for (const auto& i : Input) {
            if (XSize < i.X) XSize = i.X;
            if (YSize < i.Y) YSize = i.Y;
        }
        ++XSize;
        ++YSize;
        vector<string> Map(YSize);
        for (int i = 0; i < Map.size(); ++i) Map[i].resize(XSize, 0);
        for (const auto& i : Input) Map[i.Y][i.X] = Show(i);
        printf("Try to move G into g in the following map...\n");
        for (const auto& i : Map) printf("%s\n", i.c_str());
        int moveIntoG = Distance(20, 25, 4, 0) + Distance(4, 0, 33, 0);
        int moveG = Distance(32, 0, 0, 0) * 5;
        printf("%d\n", moveIntoG + moveG);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
