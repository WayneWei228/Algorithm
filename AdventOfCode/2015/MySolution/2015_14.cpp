#include <cstdio>
#include <string>
#include <vector>
using namespace std;

// Vixen can fly 8 km/s for 8 seconds, but then must rest for 53 seconds.

// Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.

/*
1s 后 -> 14m
2s 后 -> 28m
10s 后 -> 140m
11s 后 -> 140m
137s 后 -> 140m
138s 后 -> 156m
*/


char Buffer[80];



struct Player {
    string name;
    int flytime;
    int restime;
    int speed;
    bool is_fly = true;
    int have_fly = 0;
    int have_rest = 0;
    int dis = 0;
    int points = 0;
};

struct Solution {
    int N, Answer = 0;
    vector<Player> PlayerList;

    int Calculuate(const Player& player, int time) {
        Player p = player;
        int t = 0;
        int dis = 0;
        int have_rest = 0;
        int have_fly = 0;
        while (t < time) {
            if(have_rest == p.restime) {
                p.is_fly = true;
                have_rest = 0;
            }

            if(have_fly == p.flytime) {
                p.is_fly = false;
                have_fly = 0;
            }
            
            if(p.is_fly) {
                dis += p.speed;
                have_fly += 1;
            } else {
                have_rest += 1;
            }
            t++;
        }
        return dis;
    }

    void Solve() {
        N = 9;
        int num = 0;
        PlayerList.resize(N);

        while(true) {
            if(scanf("%s can fly %d km/s for %d seconds, but then must rest for %d seconds.",
            Buffer, &PlayerList[num].speed, &PlayerList[num].flytime, &PlayerList[num].restime) < 4) break;
            PlayerList[num].name = Buffer;
            num++;
        }
        int t = 2503; 
        for(int i = 0; i < PlayerList.size(); i++) {
            int dis = Calculuate(PlayerList[i], t);
            if(dis > Answer) Answer = dis;
        }
        printf("%d\n", Answer);
        int time = 0;
        int farthest = 0;
        while (time < t) {
            for(int i = 0; i < PlayerList.size(); i++) {
                if(PlayerList[i].have_rest == PlayerList[i].restime) {
                    PlayerList[i].is_fly = true;
                    PlayerList[i].have_rest = 0;
                }
                if(PlayerList[i].have_fly == PlayerList[i].flytime) {
                    PlayerList[i].is_fly = false;
                    PlayerList[i].have_fly = 0;
                }

                if(PlayerList[i].is_fly) {
                    PlayerList[i].dis += PlayerList[i].speed;
                    PlayerList[i].have_fly += 1;
                } else {
                    PlayerList[i].have_rest += 1;
                }
                if(PlayerList[i].dis > farthest) {
                    farthest = PlayerList[i].dis;
                }
            }
            for(int i = 0; i < PlayerList.size(); i++) {
                if(PlayerList[i].dis == farthest) {
                    PlayerList[i].points++;
                }
            }
            time++;
        }
        
        int points = 0;
        for(auto p : PlayerList) {
            if(p.points > points) {
                points = p.points;
            }
        }
        printf("%d\n", points);
    }
};

int main() {
    Solution().Solve();
    return 0;
}