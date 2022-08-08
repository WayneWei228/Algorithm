#include <algorithm>
#include <cstdio>
#include <limits>
#include <unordered_map>
using namespace std;

struct Wield {
    enum WieldType { Weapon, Armor, Ring } Type;
    int Cost, Damage, Defend;
};

Wield AvailableWields[16] = {
    {Wield::Weapon, 8, 4, 0},  {Wield::Weapon, 10, 5, 0},
    {Wield::Weapon, 25, 6, 0}, {Wield::Weapon, 40, 7, 0},
    {Wield::Weapon, 74, 8, 0}, {Wield::Armor, 13, 0, 1},
    {Wield::Armor, 31, 0, 2},  {Wield::Armor, 53, 0, 3},
    {Wield::Armor, 75, 0, 4},  {Wield::Armor, 102, 0, 5},
    {Wield::Ring, 25, 1, 0},   {Wield::Ring, 50, 2, 0},
    {Wield::Ring, 100, 3, 0},  {Wield::Ring, 20, 0, 1},
    {Wield::Ring, 40, 0, 2},   {Wield::Ring, 80, 0, 3},
};

struct Player {
    int HitPoint, Damage, Defend;

    void Read() {
        scanf("Hit Points: %d ", &HitPoint);
        scanf("Damage: %d ", &Damage);
        scanf("Armor: %d ", &Defend);
    }

    bool Win(const Player& that) const {
        int damageToThat = max(1, Damage - that.Defend);
        int damageToThis = max(1, that.Damage - Defend);
        int hpThat = that.HitPoint, hpThis = HitPoint;
        while (true) {
            hpThat -= damageToThat;
            if (hpThat <= 0) return true;
            hpThis -= damageToThis;
            if (hpThis <= 0) return false;
        }
    }
};

struct Solution {
    Player Boss, Human;
    unordered_map<Wield::WieldType, int> Min, Max;
    int Cost;
    int MinCost = numeric_limits<int>::max();
    int MaxCost = numeric_limits<int>::min();

    void Put(int no) {
        if (no == 16) {
            for (const auto& i : Min) {
                if (0 < i.second) return;
            }
            if (Human.Win(Boss)) {
                if (Cost < MinCost) MinCost = Cost;
            } else {
                if (MaxCost < Cost) MaxCost = Cost;
            }
            return;
        }
        Put(no + 1); // 当前不放
        if (0 < Max[AvailableWields[no].Type]) { // 当前放
            --Max[AvailableWields[no].Type];
            --Min[AvailableWields[no].Type];
            Human.Damage += AvailableWields[no].Damage;
            Human.Defend += AvailableWields[no].Defend;
            Cost += AvailableWields[no].Cost;
            Put(no + 1);
            Cost -= AvailableWields[no].Cost;
            Human.Defend -= AvailableWields[no].Defend;
            Human.Damage -= AvailableWields[no].Damage;
            ++Min[AvailableWields[no].Type];
            ++Max[AvailableWields[no].Type];
        }
    }

    void Solve() {
        Boss.Read();
        Min[Wield::Weapon] = 1;
        Min[Wield::Armor] = 0;
        Min[Wield::Ring] = 0;
        Max[Wield::Weapon] = 1;
        Max[Wield::Armor] = 1;
        Max[Wield::Ring] = 2;
        Human.HitPoint = 100;
        Put(0);
        printf("%d\n", MinCost);
        printf("%d\n", MaxCost);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
