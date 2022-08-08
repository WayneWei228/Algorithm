#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

/*
London to Dublin = 464
London to Belfast = 518
Dublin to Belfast = 141
*/

char Buffer0[80], Buffer1[80];

struct Solution {
    vector<string> V;
    map<string, int> mp;
    int S[30][30] = {0};
    vector<int> Answer1;
    vector<int> Answer2;
    int cnt = 0;
    int n;

    void Read(const string& input) {
        string s = input;
        if(mp.find(s) == mp.end()) {
            mp.insert(make_pair(s, V.size()));
            V.push_back(s);
            cnt++;
        }
    }

    int Getlabel(int p, const vector<int>& state) {
        int answer = p;
        for(int i = 0; i < cnt; i++) {
            answer = answer * 2 + state[i];
        }
        return answer;
    }

    int Distance(int c1, int c2) {
        return S[c1][c2];
    }

    int Get1(int p, const vector<int>& state) {
        int label = Getlabel(p, state);
        if(Answer1[label] != 0) return Answer1[label];
        int state1 = 0, state2 = 0;
        for(int i = 0; i < cnt; i++) {
            if(state[i] == 0) ++state1;
            if(state[i] == 1) ++state2;
        }
        if(state2 == cnt) return Answer1[label] = 1;
        int answer = numeric_limits<int>::max();
        for(int i = 0; i < cnt; i++) {
            if(state[i] == 0) {
                vector<int> newState(state);
                newState[i] = 1;
                int res = Get1(i, newState) + Distance(p, i);
                if(res < answer) answer = res;
            }
        }
        return Answer1[label] = answer;
    }

    int Get2(int p, const vector<int>& state) {
        int label = Getlabel(p, state);
        if(Answer2[label] != 0) return Answer2[label];
        int state1 = 0, state2 = 0;
        for(int i = 0; i < cnt; i++) {
            if(state[i] == 0) ++state1;
            if(state[i] == 1) ++state2;
        }
        if(state2 == cnt) return Answer2[label] = 1; // 为避免计算过后 == 0 还计算
        int answer = 0;
        for(int i = 0; i < cnt; i++) {
            if(state[i] == 0) {
                vector<int> newState(state);
                newState[i] = 1;
                int res = Get2(i, newState) + Distance(p, i);
                if(res > answer) answer = res;
            }
        }
        return Answer2[label] = answer;
    }

    void Solve() {
        while (true) {
            if(scanf("%s to %s = %d", Buffer0, Buffer1, &n) < 3) break;
            Read(Buffer0);
            Read(Buffer1);
            S[mp[Buffer0]][mp[Buffer1]] = n;
            S[mp[Buffer1]][mp[Buffer0]] = n;
        }
        V.resize(cnt);
        int answerSize = V.size();
        for(int i = 0; i < cnt; i++) answerSize *= 2;
        Answer1.resize(answerSize);
        Answer2.resize(answerSize);
        vector<int> state1;
        for(int i = 0; i < cnt; i++) state1.push_back(0);
        vector<int> state2(state1);

        printf("%d\n", Get1(0, state1) - 1);
        printf("%d\n", Get2(0, state2) - 1);
        
        int ans = 0;
        for(int i = 1; i < Answer2.size(); i++) {
            if(Answer2[i] > ans) {
                ans = Answer2[i] - 1;
            }
        }
        cout << "ans" << ans << endl;
    }
};

int main() {
    Solution().Solve();
    return 0;
}