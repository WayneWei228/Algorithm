#include <cstdio>
#include <cmath>
using namespace std;

struct Solution {
    int input;
    
    int calculate1 (int a) {
        for(int i = 1; i < a; i++) { // i -> now
            int sum = 0;
            int num = int(sqrt(i));
            for(int j = 1; j <= num; j++) { // 因数和
                if(i % j == 0) {
                    sum += j;
                    sum += i / j;
                }
            }
            if(sum >= input / 10) {
                return i;
            }
        }
        return 0;
    }

    int calculate2 (int a) { // eg: 8 : 1 2 4 8
        for(int i = 1; i < a; i++) { // i -> now
            int sum = 0;
            int num = int(sqrt(i)); // 提高效率
            for(int j = 1; j <= num; j++) { // 因数和
                if(i % j == 0) {
                    if(i / j <= 50) {
                        sum += j;
                    }
                    if(j <= 50) {
                        sum += i / j;
                    }
                }
            }
            if(sum * 11 >= input) {
                return i;
            }
        }
        return 0;
    }

    void Solve() {
        scanf("%d\n", &input);
        int answer1 = calculate1(input);
        printf("%d\n", answer1);
        
        int answer2 = calculate2(input);
        printf("%d\n", answer2);
    }
};

int main() {
    Solution().Solve();
    return 0;
}