#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int HumanHP = 50;
const int HumanMP = 500;


// dijkstra
// 探究dijkstra 和 广搜的区别
struct Node {
    int HP, MP, BossHP, Shield, Poison, Recharge, MPUsed, F;
    bool HumansTurn;

    Node& ComputeF() {
        // 如果最快的话 F = turn_used + boss血量 / 每回合最大伤害
        
        F = MPUsed + max(0, BossHP - Poison * 3) * 173 / 18;
        return *this;
    }

    bool operator<(const Node& that) const { return that.F < F; }

    bool CastMagicMissile() {
        if (MP < 53) return false;
        MP -= 53;
        BossHP -= 4;
        MPUsed += 53;
        HumansTurn = false;
        ComputeF();
        return true;
    }

    bool CastDrain() {
        if (MP < 73) return false;
        HP += 2;
        MP -= 73;
        BossHP -= 2;
        MPUsed += 73;
        HumansTurn = false;
        ComputeF();
        return true;
    }

    bool CastShield() {
        if (MP < 113 || 0 < Shield) return false;
        MP -= 113;
        Shield = 6;
        MPUsed += 113;
        HumansTurn = false;
        ComputeF();
        return true;
    }

    bool CastPoison() {
        if (MP < 173 || 0 < Poison) return false;
        MP -= 173;
        Poison = 6;
        MPUsed += 173;
        HumansTurn = false;
        ComputeF();
        return true;
    }

    bool CastRecharge() {
        if (MP < 229 || 0 < Recharge) return false;
        MP -= 229;
        Recharge = 5;
        MPUsed += 229;
        HumansTurn = false;
        ComputeF();
        return true;
    }

    bool BossAttack(int bossDamage) {
        if (0 < Shield) bossDamage -= 7;
        if (bossDamage < 1) bossDamage = 1;
        HP -= bossDamage;
        HumansTurn = true;
        ComputeF();
        return true;
    }

    vector<Node> Next(int bossDamage) {
        if (0 < Poison) BossHP -= 3;
        if (0 < Recharge) MP += 101;
        if (0 < Shield) --Shield;
        if (0 < Poison) --Poison;
        if (0 < Recharge) --Recharge;
        vector<Node> answer;
        if (HumansTurn) {
            Node answer1(*this);
            if (answer1.CastMagicMissile()) {
                answer.emplace_back(move(answer1));
            }
            Node answer2(*this);
            if (answer2.CastDrain()) {
                answer.emplace_back(move(answer2));
            }
            Node answer3(*this);
            if (answer3.CastShield()) {
                answer.emplace_back(move(answer3));
            }
            Node answer4(*this);
            if (answer4.CastPoison()) {
                answer.emplace_back(move(answer4));
            }
            Node answer5(*this);
            if (answer5.CastRecharge()) {
                answer.emplace_back(move(answer5));
            }
        } else {
            if (BossAttack(bossDamage)) {
                answer.emplace_back(move(*this));
            }
        }
        return answer;
    }
};

struct Solution {
    int BossHP, BossDamage;

    int LeastMana(bool hard) {
        priority_queue<Node> nodes; // 下一步的所有可能性的优先队列，其实就是临时标号队列, 永久标号就是出队
        nodes.emplace(
            Node{HumanHP, HumanMP, BossHP, 0, 0, 0, 0, 0, true}
                .ComputeF());
        while (!nodes.empty()) {
            auto top = nodes.top();
            nodes.pop();
            if (top.HumansTurn) top.HP -= hard;
            if (top.BossHP <= 0) return top.MPUsed;
            if (top.HP <= 0) continue;
            for (auto& i : top.Next(BossDamage)) {
                nodes.emplace(move(i));
            }
        }
        return 0;
    }

    void Solve() {
        scanf("Hit Points: %d ", &BossHP);
        scanf("Damage: %d ", &BossDamage);
        printf("%d\n", LeastMana(false));
        printf("%d\n", LeastMana(true));
    }
};

int main() {
    Solution().Solve();
    return 0;
}