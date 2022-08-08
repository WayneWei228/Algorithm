#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

char Buffer[80];

// Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8


struct Food {
    int capacity;
    int durability;
    int flavor;
    int texture;
    int calories;
};


struct Solution {
    vector<Food> food;
    void Solve() {
        food.resize(4);
        int n = 0;
        while (true) {
            if(scanf("%[^:]: capacity %d, durability %d, flavor %d, texture %d, calories %d", 
            Buffer, &food[n].capacity, &food[n].durability, &food[n].flavor, &food[n].texture, &food[n].calories) < 6) break;
            n++;
        }

        int Answer1 = 0;
        for(int i = 1; i < 100; ++i) {
            for(int j = 1; j < 100; ++j) {
                for(int k = 1; k < 100; ++k) {
                    for(int z = 1; z < 100; ++z) {
                        if(i + j + k + z == 100) {
                            // cout << "i " << i << " j " << j << " k " << k << " z " << z << endl;
                            int total;
                            int cap = i * food[0].capacity + j * food[1].capacity + k * food[2].capacity + z * food[3].capacity;
                            int dur = i * food[0].durability + j * food[1].durability + k * food[2].durability + z * food[3].durability;
                            int fla = i * food[0].flavor + j * food[1].flavor + k * food[2].flavor + z * food[3].flavor;
                            int text = i * food[0].texture + j * food[1].texture + k * food[2].texture + z * food[3].texture;
                            if(cap < 0 || dur < 0 || fla < 0 || text < 0) {
                                total = 0;
                            } else {
                                total = cap * dur * fla * text;
                            }
                            if(total > Answer1) Answer1 = total;
                        }
                    }
                }
            }
        }
        printf("%d\n", Answer1);

        int Answer2 = 0;
        for(int i = 1; i < 100; ++i) {
            for(int j = 1; j < 100; ++j) {
                for(int k = 1; k < 100; ++k) {
                    for(int z = 1; z < 100; ++z) {
                        if(i + j + k + z == 100) {
                            // cout << "i " << i << " j " << j << " k " << k << " z " << z << endl;
                            int cal = i * food[0].calories + j * food[1].calories + k * food[2].calories + z * food[3].calories;
                            if(cal == 500) {
                                int total;
                                int cap = i * food[0].capacity + j * food[1].capacity + k * food[2].capacity + z * food[3].capacity;
                                int dur = i * food[0].durability + j * food[1].durability + k * food[2].durability + z * food[3].durability;
                                int fla = i * food[0].flavor + j * food[1].flavor + k * food[2].flavor + z * food[3].flavor;
                                int text = i * food[0].texture + j * food[1].texture + k * food[2].texture + z * food[3].texture;
                                if(cap < 0 || dur < 0 || fla < 0 || text < 0) {
                                    total = 0;
                                } else {
                                    total = cap * dur * fla * text;
                                }
                                if(total > Answer2) Answer2 = total;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", Answer2);
    }

};


int main() {
    Solution().Solve();
    return 0;
}