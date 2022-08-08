#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct Reindeer {
    int Speed, Fly, Rest;

    Reindeer(const string& input) {
        sscanf(input.c_str(),
               "%*s can fly %d km/s for %d seconds, but then must rest "
               "for %d seconds.",
               &Speed, &Fly, &Rest);
    }

    int Distance(int duration) const { 
        // 算飞行时间 * 速度
        int duration1 = duration / (Fly + Rest) * Fly;
        int duration2 = min(duration % (Fly + Rest), Fly);
        return (duration1 + duration2) * Speed;
    }
};

int Race(int time, const vector<Reindeer>& input) {
    vector<int> scores(input.size()); // 存储分数
    for (int i = 1; i <= time; ++i) { // 穷举1 ～ time 时间
        vector<int> distances(input.size()); // 存储特定时刻走的距离
        for (int j = 0; j < input.size(); ++j) {
            distances[j] = input[j].Distance(i); //
        }
        int maxDistance = 
            *max_element(distances.begin(), distances.end());
        for (int j = 0; j < input.size(); ++j) {
            if (distances[j] == maxDistance) ++scores[j]; // 如果最远 scores++
        }
    }
    return *max_element(scores.begin(), scores.end());
}

const int Time = 2503;

char Buffer[80];

struct Solution {
    vector<Reindeer> Input;

    void Solve() {
        while (true) {
            if (scanf("%[^\n]\n", Buffer) < 1) break;
            Input.emplace_back(Buffer);
        }
        int maxDistance = 0;
        for (const auto& i : Input) {
            int distance = i.Distance(Time);
            if (maxDistance < distance) maxDistance = distance;
        }
        printf("%d\n", maxDistance);
        printf("%d\n", Race(Time, Input));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
