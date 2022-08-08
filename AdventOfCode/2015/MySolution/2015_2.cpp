#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
// 29x13x26
int main()
{
    freopen("2015_2.txt", "r", stdin);
    long long total = 0;
    long long totallen = 0;
    while (true)
    {
        string line;
        getline(cin, line);
        if (line == "")
        {
            break;
        }
        cout << line << endl;
        int store[3] = {0, 0, 0};
        int min_num = numeric_limits<int>::max();
        string b = "";
        int num = 0;
        int pos = 0;

        for(int i = 0; i < line.size(); i++) {
            if(line[i] == 'x') {
                cout << "b " << b << endl;
                if(b.size() == 1) { // 个位数不除10单独判
                    num = b[0] - '0';
                } else { // 处理多位数
                    for (int i = 0; i < b.size(); i++)
                    {
                        num = (num + b[i] - '0') * 10;
                    }
                    num /= 10;
                }
                store[pos] = num;
                pos++;
                b = "";
                num = 0;
                i++; // 跳过 x
            }
            b += line[i];
        }
        cout << "b " << b << endl;
        if(b.size() == 1) {
            num = b[0] - '0';
        } else {
            for (int i = 0; i < b.size(); i++)
            {
                num = (num + b[i] - '0') * 10;
            }
            num /= 10;
        }
        store[pos] = num;
        sort(store, store + 3);
        for(int i = 0; i < 3; i++) {
            cout << store[i] << endl;
        }
        int x1 = store[0] * store[1];
        int x2 = store[1] * store[2];
        int x3 = store[0] * store[2];
        min_num = min(x1, min(x2, x3));
        // cout << "min_value " << min_num << endl;
        total += (x1 + x2 + x3) * 2 + min_num;
        totallen += 2 * (store[0] + store[1]) + (store[0] * store[1] * store[2]);
    }
    // cout << total << endl;
    cout << totallen << endl;
    return 0;
    fclose(stdin);
}