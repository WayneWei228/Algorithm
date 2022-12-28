#include <iostream>
#include <vector>
using namespace std;
void sf(int number, int factor = 2) {
    if (number < 2) return;
    if (number % factor == 0) {
        cout << factor << " ";
        sf(number / factor, factor);
    } else
        sf(number, factor + 1);
}
int rob(vector<int>& nums) {
    return rob(0, int(nums.size() - 2),
               nums(nums.begin(), nums.end() - 2));
}

int rob(int start, int end, vector<int> nums) {
    for (int i = start; i <= end; i++) {
        // nums[i]
    }
}
int main() {
    // sf(10);
    // cout << "\n";

    return 0;
}