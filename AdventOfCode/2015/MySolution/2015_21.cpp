#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

char Buffer[80];

struct Gear {
    string name;
    int cost, damage, armor;
};

struct people {
    int hit_point;
    int damage;
    int armor;
};


struct Solution {
    vector<Gear>  gears = 
     // 0 ~ 4
    {Gear{"Dagger", 8, 4, 0},
     Gear{"Shortsword", 10, 5, 0},
     Gear{"Warhammer", 25, 6, 0},
     Gear{"Longsword", 40, 7, 0},
     Gear{"Greataxe", 74, 8, 0},
     // 5 ~ 10
     Gear{"Leather", 13, 0, 1},
     Gear{"Chainmail", 31, 0, 2},
     Gear{"Splintmail", 53, 0, 3},
     Gear{"Bandedmail", 75, 0, 4},
     Gear{"Platemail", 102, 0, 5},
     Gear{"none", 0, 0, 0},
     // 11 ~ 18
     Gear{"Damage +1", 25, 1, 0},
     Gear{"Damage +2", 50, 2, 0},
     Gear{"Damage +3", 100, 3, 0},
     Gear{"Defense +1", 20, 0, 1},
     Gear{"Defense +2", 40, 0, 2},
     Gear{"Defense +3", 80, 0, 3},
     Gear{"none", 0, 0, 0},
     Gear{"none", 0, 0, 0},
     };

    int cost = numeric_limits<int>::max();

    bool fight(const people& first, const people& second) {
        int attackfirst = second.damage - first.armor;
        int attacksecond = first.damage - second.armor;
        if(attackfirst < 1) attackfirst = 1;
        if(attacksecond < 1) attacksecond = 1;
        people a = first;
        people b = second;
        while(true) {
            b.hit_point -= attacksecond;
            if(b.hit_point <= 0) {
                return true;
            }
            a.hit_point -= attackfirst;
            if(a.hit_point <= 0) {
                return false;
            }
        }
    }

    void Solve() {
        people boss;
        people henry;
        henry.hit_point = 100;
        int d;
        scanf("%*[^:]: %d", &boss.hit_point);
        scanf("%*[^:]: %d", &boss.damage);
        scanf("%*[^:]: %d", &boss.armor);
        for(int i = 0; i <= 4; i++) {
            for(int j = 5; j <= 10; j++) {
                for(int k = 11; k < 18; k++) {
                    for(int z = k + 1; z <= 18; z++) {
                        henry.damage = gears[i].damage + gears[j].damage + gears[k].damage + gears[z].damage;
                        henry.armor = gears[i].armor + gears[j].armor + gears[k].armor + gears[z].armor;
                        int totalcost = gears[i].cost + gears[j].cost + gears[k].cost + gears[z].cost;
                        if(fight(henry, boss) && totalcost < cost) {
                            cost = totalcost;
                        }
                    }
                }
            }
        }
        printf("%d\n", cost);

        cost = numeric_limits<int>::min();
        for(int i = 0; i <= 4; i++) {
            for(int j = 5; j <= 10; j++) {
                for(int k = 11; k < 18; k++) {
                    for(int z = k + 1; z <= 18; z++) {
                        henry.damage = gears[i].damage + gears[j].damage + gears[k].damage + gears[z].damage;
                        henry.armor = gears[i].armor + gears[j].armor + gears[k].armor + gears[z].armor;
                        int totalcost = gears[i].cost + gears[j].cost + gears[k].cost + gears[z].cost;
                        if(!fight(henry, boss) && totalcost > cost) {
                            cost = totalcost;
                        }
                    }
                }
            }
        }
        printf("%d\n", cost);
    }
};

int main() {
    Solution().Solve();
    return 0;
}