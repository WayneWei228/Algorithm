#include <cstdio>
#include <limits>
#include <map>
#include <vector>
using namespace std;

struct Coordinate {
    int X, Y;

    bool operator<(const Coordinate& that) const {
        return X < that.X || X == that.X && Y < that.Y;
    }
};

typedef map<Coordinate, int>::iterator Type1;
typedef pair<Type1, bool> Type2;

struct Solution {
    int N;
    vector<Coordinate> C;
    map<Coordinate, int> CNo;
    vector<int> Cook, Tool;
    vector<int> Answer;
    
    int ReadCoordinate() {
        Coordinate c;
        scanf("%d%d", &c.X, &c.Y);
        Type2 result = CNo.insert(make_pair(c, C.size()));
        if (result.second) C.push_back(c);
        return result.first -> second;
    }

    int Getlabel(int p, const vector<int>& state) {
        int answer = p;
        for(int i = 0; i < N; i++) {
            answer = answer * 3 + state[i];
        }
        return answer;
    }

    int Distance(int c1, int c2) {
        int dx = C[c2].X - C[c1].X;
        if(dx < 0) dx = -dx;
        int dy = C[c2].Y - C[c1].Y;
        if(dy < 0) dy = -dy;
        return dx + dy;
    }

    int Get(int p, const vector<int>& state) {
        int label = Getlabel(p, state);
        if(Answer[label] != 0) return Answer[label];
        int state1 = 0, state2 = 0;
        for(int i = 0; i < N; i++) {
            if(state[i] == 1) ++state1;
            if(state[i] == 2) ++state2;
        }
        if(state2 == N) return Answer[label] = Distance(p, 0);
        int answer = numeric_limits<int>::max();
        for(int i = 0; i < N; i++) {
            if(state[i] == 1) {
                vector<int> newState(state);
                newState[i] = 2;
                int result = Get(Cook[i], newState) + Distance(p, Cook[i]);
                if(result < answer) answer = result;
            }
        }
        if(state1 == 2) return Answer[label] = answer;
        for(int i = 0; i < N; i++) {
            if(state[i] == 0) {
                vector<int> newState(state);
                newState[i] = 1;
                int result = Get(Tool[i], newState) + Distance(p, Tool[i]);
                if(result < answer) answer = result;
            }
        }
        return Answer[label] = answer;
    }

    void Solve() {
        scanf("%d", &N);
        Coordinate zero = {0, 0};
        C.push_back(zero);
        CNo[zero] = 0;
        Cook.resize(N);
        Tool.resize(N);
        for(int i = 0; i < N; i++) {
            Cook[i] = ReadCoordinate();
            Tool[i] = ReadCoordinate();        
        }
        int answerSize = C.size();
        for(int i = 0; i < N; i++) answerSize *= 3;
        Answer.resize(answerSize);
        vector<int> state;
        for(int i = 0; i < N; i++) state.push_back(0);
        printf("%d\n", Get(0, state));
    }
};


int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) Solution().Solve();
    return 0;
}