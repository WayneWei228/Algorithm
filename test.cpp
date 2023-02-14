#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, long long>> animals;
    animals.emplace_back(40000, 4);      // Lions
    animals.emplace_back(80000, 2);      // giraffe
    animals.emplace_back(110000, 1);     // camel
    animals.emplace_back(16000, 1);      // seal
    animals.emplace_back(30000, 2);      // cheetah
    animals.emplace_back(8000, 0.6666);  // cow
    animals.emplace_back(12000, 1);      // monkey
    animals.emplace_back(40000, 2);      // asian elephant
    animals.emplace_back(120000, 6);     // african elephant
    animals.emplace_back(50000, 5);      // retile house
    animals.emplace_back(50000, 1);      // shark
    animals.emplace_back(10000, 1);      // kangaroo
    animals.emplace_back(15000, 2);      // tiger
    animals.emplace_back(32000, 10);     // birds
    animals.emplace_back(0, 0.6666);     // turkeys
    animals.emplace_back(150000, 4);     // hippos
    animals.emplace_back(50000, 2);      // gorilla
    animals.emplace_back(8000000, 4);    // panda
    animals.emplace_back(30000, 6);      // zebra
    animals.emplace_back(40000, 2);      // bear;
    int n = animals.size();
    vector<long long> dp;
    dp.resize(26);
    for (int i = 0; i < dp.size(); i++) {
        dp[i] = 0;
    }
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 25; j >= 0; j++) {
            if (j - animals[i].second >= 0) {
                assert(j - animals[i].second >= 0);
                dp[j] = min(dp[j],(long long)dp[j - animals[i].second] +
                                       animals[i].first);
                                       
            } else {
                dp[j] = dp[j];
            }
        }
    }
    // cout << dp[25] << endl;
    // return 0;
}