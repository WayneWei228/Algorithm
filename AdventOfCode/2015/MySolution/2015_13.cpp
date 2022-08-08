#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

const int N = 8;

char Buffer[150], Buffer0[80], Buffer1[80], Buffer2[80];


struct Solution {
    int N;
    map<string, int> ToNumber;
    vector<vector<int>> HappyValue;
    int Answer;
    vector<int> P;

    int MapToNumber(const string& input) {
        auto res = ToNumber.emplace(input, int(ToNumber.size()));
        return res.first -> second;
    }

    void Put(int now, int current) {
        if(now == N) {
            current += (HappyValue[P[now - 1]][P[0]] + HappyValue[P[0]][P[now - 1]]);
            if(current > Answer) Answer = current;
            return;
        }
        for(int i = now; i < N; i++) {
            swap(P[now], P[i]);
            int next = current;
            if(now != 0) next += (HappyValue[P[now - 1]][P[now]] + HappyValue[P[now]][P[now - 1]]);
            Put(now + 1, next);
            swap(P[now], P[i]);
        }

    }

    void Put2(int now, int current) {
        if(now == N + 1) {
            current += (HappyValue[P[now - 1]][P[0]] + HappyValue[P[0]][P[now - 1]]);
            if(current > Answer) Answer = current;
            return;
        }
        for(int i = now; i <= N; i++) {
            swap(P[now], P[i]);
            int next = current;
            if(now != 0) next += (HappyValue[P[now - 1]][P[now]] + HappyValue[P[now]][P[now - 1]]);
            Put(now + 1, next);
            swap(P[now], P[i]);
        }

    }

    void Solve() {
        N = 8;
        HappyValue.resize(N);
        for(int i = 0; i < HappyValue.size(); ++i) HappyValue[i].resize(N);
        while (true) {
            int d;
            if(scanf("%s would %s %d happiness units by sitting next to %[^.].", Buffer0, Buffer1, &d, Buffer2) < 4) break; // %s 读直到空白字符 ： 空格 回车 Tap
            int n0 = MapToNumber(Buffer0);
            int n1 = MapToNumber(Buffer2);
            if(Buffer1[0] == 'l') {
                d = -d;
            }
            // cout << "n0 " << n0 << " n1 " << n1 << endl;
            HappyValue[n0][n1] = d;
        }
        P.resize(N);
        for(int i  = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << HappyValue[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < N; ++i) P[i] = i;
        Answer = 0;
        Put(0, 0);
        printf("%d\n", Answer);

        N++;
        P.resize(N);
        for(int i = 0; i < N; ++i) P[i] = i;
        int me = MapToNumber("me");
        HappyValue.resize(N);
        for(int i = 0; i < HappyValue.size(); ++i) HappyValue[i].resize(N);
        for(int i = 0; i < N; i++) {
            HappyValue[i][me] = 0;
            HappyValue[me][i] = 0;
        }
        for(int i  = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << HappyValue[i][j] << " ";
            }
            cout << endl;
        }

        Answer = 0;
        Put(0, 0);
        printf("%d\n", Answer);
    }
};

int main() {
    // freopen("2015_13.txt", "r", stdin);
    Solution().Solve();
    // fclose(stdin);
    return 0;
}