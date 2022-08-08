#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int kWakeUp = -1, kFallAsleep = -2;
const int kMaxTime = 1440;

char Buffer[80];

struct Record {
    string Date;
    int Time, Operation;
    // Time : 1518-11-01
    Record& Parse(const string& input) {
        int h, m;
        char c;
        if (sscanf(input.c_str(), "[%s %d:%d] Guard #%d begins%c",  //
                   Buffer, &h, &m, &Operation, &c) == 5) {
            // 默认 Operation 为 id
            Date = Buffer;
            Time = h * 60 + m; // 转换为分钟
            return *this;
        }
        if (sscanf(input.c_str(), "[%s %d:%d] wakes%c",  //
                   Buffer, &h, &m, &c) == 4) {
            Date = Buffer;
            Time = h * 60 + m;
            Operation = kWakeUp;
            return *this;
        }
        if (sscanf(input.c_str(), "[%s %d:%d] falls%c",  //
                   Buffer, &h, &m, &c) == 4) {
            Date = Buffer;
            Time = h * 60 + m;
            Operation = kFallAsleep;
            return *this;
        }
        return *this;
    }

    bool operator<(const Record& that) const {
        if (Date != that.Date) return Date < that.Date;
        //先日期从小到大， 再 time 从小到大
        return Time < that.Time;
    }
};

struct Solution {
    vector<Record> Records;

    void Solve() {
        while (scanf("%[^\n]\n", Buffer) == 1) {
            Records.emplace_back(Record().Parse(Buffer));
        }
        sort(Records.begin(), Records.end());
        unordered_map<int, vector<int>> sleepCount;
        int currentGuard = 0, beginTime = 0;
        for (const Record& i : Records) {
            switch (i.Operation) {
                case kWakeUp:
                    sleepCount[currentGuard].resize(kMaxTime);
                    for (int j = beginTime; j < i.Time;) {
                        ++sleepCount[currentGuard][j];
                        if (++j == kMaxTime) j = 0;
                    }
                    break;
                case kFallAsleep:
                    beginTime = i.Time;
                    break;
                default:
                    currentGuard = i.Operation;
                    break;
            }
        }
        int maxTotalSleepTime = 0, maxDays = 0;
        int argmaxTotalSleepTime = -1, argmaxDays = -1;
        // 睡眠最多的机器人
        for (const auto& i : sleepCount) {
            int totalSleepTime = 0;
            for (int j : i.second) totalSleepTime += j;
            if (maxTotalSleepTime < totalSleepTime) {
                maxTotalSleepTime = totalSleepTime;
                argmaxTotalSleepTime = i.first;
            }
        }
        const auto& c = sleepCount[argmaxTotalSleepTime];
        for (int i = 0; i < kMaxTime; ++i) {
            if (maxDays < c[i]) {
                maxDays = c[i];
                argmaxDays = i;
            }
        }
        // 该机器人睡觉最多的时间点
        printf("%d\n", argmaxTotalSleepTime * argmaxDays);
        int maxDaysPerMinute = 0, argmaxDaysPerMinute = -1;
        for (const auto& i : sleepCount) {
            for (int j = 0; j < kMaxTime; ++j) {
                if (maxDaysPerMinute < i.second[j]) {
                    // 某一时间睡眠频率最大的机器人，返回睡眠频率 * id
                    maxDaysPerMinute = i.second[j];
                    argmaxDaysPerMinute = i.first * j;
                }
            }
        }
        printf("%d\n", argmaxDaysPerMinute);
    }
};

int main() {
    Solution().Solve();
    return 0;
}