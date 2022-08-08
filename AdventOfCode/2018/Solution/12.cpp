#include <cstdio>
#include <string>
using namespace std;

typedef long long int64;

char Buffer[116];

struct Solution {
    string Input;
    unsigned Rule;

    int NumberOfPlants(int time) {
        string s(Input);
        int shift = 0;
        // O(5N)
        for (int i = 0; i < time; ++i) {
            // 新 string 左右两端延长两格都会收到旧string影响，所以sNew长度大4
            string sNew(s.size() + 4, '.');
            for (int j = 0; j < sNew.size(); ++j) {
                int id = 0;
                // sNew 的 0 算 s 的 -2
                // 要探究 sNew 0 的值得探究 左右各两格的值
                // 所以从 要从 -4 开始
                for (int k = 0; k < 5; ++k) {
                    int index = j + k - 4;
                    // 反正也是 '.' 不对id造成影响
                    if (index < 0 || s.size() <= index) continue;
                    id += (s[index] == '#') << k;
                }
                // 右位移核实
                if ((Rule >> id) & 1) sNew[j] = '#';
            }
            s = move(sNew);
            // 最初始状态 index 0 每次向右移两格
            // the initial state begins at pot 0
            // 题目意思中the initial state的第一个是 pot 0, 而不是说从pot 0 开始进行操作
            shift += 2;
        }
        int answer = 0;
        for (int i = 0; i < s.size(); ++i) {
            // i - 向右偏移的量
            if (s[i] == '#') answer += i - shift;
        }
        return answer;
    }

    void Solve() {
        scanf("initial state: %s", Buffer);
        Input = Buffer;
        for (int i = 0; i < 32; ++i) {
            char to;
            scanf("%s => %c", Buffer, &to);
            int index = 0;
            for (int j = 0; j < 5; ++j) {
                // 从左往右第几位是'#'，二进制中从右往左第几位就是1，形成独特的index
                index += (Buffer[j] == '#') << j;
            }
            // 如果变成'#', index位置上就是 1 
            if (to == '#') Rule += 1 << index;
        }
        printf("%d\n", NumberOfPlants(20));
        int n1000 = NumberOfPlants(1000);
        int n1001 = NumberOfPlants(1001);
        int64 d = n1001 - n1000;
        // 到一定数量后形成等差数列
        printf("%lld\n", n1000 + d * (50000000000 - 1000));
    }
};

int main() {
    Solution().Solve();
    return 0;
}