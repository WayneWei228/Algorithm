#include <algorithm>
#include <cstdio>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Day {
    int id = -1;
    int month, day, hour, min;
    int transfer;
    int type;

    bool Read() {
        int res =
            scanf("[%*d-%d-%d %d:%d] ", &month, &day, &hour, &min);
        if (res != 4) return false;
        transfer = hour * 60 + min;
        int nchars = -1;
        scanf("falls asleep %n", &nchars);
        if (nchars != -1) {
            type = 1;
            return true;
        }
        scanf("wakes up %n", &nchars);
        if (nchars != -1) {
            type = 2;
            return true;
        }
        scanf("Guard #%d begins shift ", &id);
        type = 0;
        return true;
    }

    bool operator<(const Day& that) const {
        if (month != that.month) {
            return month <= that.month;
        }
        if (month == that.month && day != that.day) {
            return day <= that.day;
        }
        if (month == that.month && day == that.day &&
            transfer != that.transfer) {
            return transfer < that.transfer;
        }
        return false;
    }
};

struct Solution {
    vector<Day> Days;
    unordered_map<int, vector<int>> M;
    int most = numeric_limits<int>::min();
    int id1;
    void Solve() {
        Day a;
        while (true) {
            Day a;
            if (a.Read()) {
                Days.emplace_back(move(a));
            } else {
                break;
            }
        }
        sort(Days.begin(), Days.end());
        int ID, start, end;
        for (const auto& i : Days) {
            switch (i.type) {
                case 0:
                    ID = i.id;
                    if (M.find(ID) == M.end()) {
                        vector<int> a{};
                        a.resize(60);
                        M.emplace(ID, move(a));
                    }
                    break;
                case 1:
                    start = i.min;
                    break;
                case 2:
                    end = i.min;
                    auto& s = M[ID];
                    for (int j = start; j < end; j++) {
                        s[j] += 1;
                    }
                    break;
            }
        }
        for (auto i : M) {
            int total = 0;
            for (auto j : i.second) {
                total += j;
            }
            if (total > most) {
                most = total;
                id1 = i.first;
            }
        }
        int time =
            max_element(M[id1].begin(), M[id1].end()) - M[id1].begin();
        printf("%d\n", time * id1);
        int id2, pos, value = 0;
        for (auto& i : M) {
            for (int j = 0; j < 60; j++) {
                if (i.second[j] > value) {
                    value = i.second[j];
                    pos = j;
                    id2 = i.first;
                }
            }
        }
        printf("%d\n", id2 * pos);
    }
};

int main() {
    Solution().Solve();
    return 0;
}