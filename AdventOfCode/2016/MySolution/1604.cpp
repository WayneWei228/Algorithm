#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// aaaaa-bbb-z-y-x-123[abxyz]

char Buffer[80];

// bool cmp(const pair<char, int> &a, const pair<char, int> &b) {
//     if (b.second < a.second ||
//         b.second == a.second && b.first > a.first) {
//         return true;
//     }
//     return false;
// }

struct Room {
    string encrypted = "";
    int sectorID;
    string checksum;
    vector<pair<char, int>> Common;

    Room(const string &input) {
        int pos = 0;
        int nchars;
        while (true) {
            int res = sscanf(input.c_str() + pos, "%[^-0123456789]-%n",
                             Buffer, &nchars);
            if (res < 1) break;
            pos += nchars;
            encrypted += Buffer;
        }
        sscanf(input.c_str() + pos, "%d[%[^]]]", &sectorID, Buffer);
        checksum = Buffer;
    }

    bool Check() {
        for (auto e : encrypted) {
            bool flag = false;
            for (int i = 0; i < Common.size(); ++i) {
                if (Common[i].first == e) {
                    Common[i].second++;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                Common.emplace_back(pair{e, 0});
            }
        }
        sort(Common.begin(), Common.end(),
             [&](const pair<char, int> &a, const pair<char, int> &b) {
                 if (b.second < a.second ||
                     b.second == a.second && b.first > a.first) {
                     return true;
                 }
                 return false;
             });

        for (int i = 0; i < 5; ++i) {
            if (Common[i].first != checksum[i]) return false;
        }
        return true;
    }

    bool Change() {
        int num = sectorID % 26;
        string after;
        for (int i = 0; i < encrypted.size(); ++i) {
            char temp = encrypted[i] + num;
            if (temp > 'z') temp -= 26;
            after += temp;
        }
        if (after.substr(0, 9) == "northpole") {  //
            return true;
        }
        return false;
    }
};

struct Solution {
    vector<Room> Rooms;
    int total = 0;
    int answer2 = 0;
    void Solve() {
        while (true) {
            if (scanf("%s", Buffer) < 1) break;
            Rooms.emplace_back(Buffer);
        }
        for (int i = 0; i < Rooms.size(); ++i) {
            if (Rooms[i].Check()) {
                total += Rooms[i].sectorID;
            }
            if (Rooms[i].Change()) {
                answer2 = Rooms[i].sectorID;
            }
        }
        printf("%d\n", total);
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}