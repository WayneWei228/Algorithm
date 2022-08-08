#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

char Buffer[200];

int DX[6]{0, -1, -1, 0, 1, 1}, DY[6]{1, 1, 0, -1, -1, 0};

struct Coordinate {
    int X, Y;

    bool operator==(const Coordinate& that) const {
        return X == that.X && Y == that.Y;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate& c) const {
        return c.X * 9875321 + c.Y;
    }
};

typedef unordered_set<Coordinate, CoordinateHash> CoordinateSet;

struct Solution {
    int N;
    vector<string> B;
    void Solve(int caseNo) {
        scanf("%d", &N);
        B.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%s", Buffer);
            string s = Buffer;
            B[i] = s;
        }
        printf("Case #%d: %s\n", caseNo, Compute().c_str());
    }

    string Compute();
};

struct Node {
    int DFSNumber, Low;
};

struct DFS {
    Solution* S;
    char C;
    Coordinate Begin{-1, -1}, End{-2, -2};
    CoordinateSet NearBegin, NearEnd;
    unordered_map<Coordinate, Node, CoordinateHash> Nodes;
    int Time = 0;
    bool NoCutPoint = true;

    vector<Coordinate> Near(const Coordinate& c) {
        vector<Coordinate> answer;
        auto add = [&](const CoordinateSet& s) {
            for (const Coordinate& i : s) {
                if (S->B[i.X][i.Y] == C) answer.emplace_back(i);
            }
            return answer;
        };
        if (c == Begin) return add(NearBegin);
        if (c == End) return add(NearEnd);
        for (int i = 0; i < 6; i++) {
            int xnew = c.X + DX[i];
            int ynew = c.Y + DY[i];
            if (xnew < 0 || xnew >= S->N) continue;
            if (ynew < 0 || ynew >= S->N) continue;
            if (S->B[xnew][ynew] == C) {
                answer.emplace_back(Coordinate{xnew, ynew});
            }
        }
        if (NearBegin.count(c)) answer.emplace_back(Begin);
        if (NearEnd.count(c)) answer.emplace_back(End);
        return answer;
    }

    int Count() {
        int answer = 0;
        for (const string& i : S->B) {
            for (char j : i) {
                if (j == C) ++answer;
            }
        }
        return answer;
    }

    bool Visit(const Coordinate& no, const Coordinate& parent) {
        bool answer = no == End;
        Node& now = Nodes[no];
        now.DFSNumber = now.Low = ++Time;

        for (const Coordinate& i : Near(no)) {
            if (i == parent) continue;
            const Node& next = Nodes[i];
            if (Nodes[i].DFSNumber == 0) {
                bool hasEnd = Visit(i, no);
                answer |= hasEnd;
                now.Low = min(now.Low, next.Low);
                if (no == Begin || no == End) continue;
                if (hasEnd && next.Low >= now.DFSNumber) {
                    NoCutPoint = false;
                }
            } else {
                now.Low = min(now.Low, next.DFSNumber);
            }
        }
        return answer;
    }

    bool Connect() {
        Visit(Begin, Begin);
        return Nodes[End].DFSNumber != 0;
    }
};

string Solution::Compute() {
    DFS r{this, 'R'}, b{this, 'B'};
    int CountR = r.Count(), CountB = b.Count();
    if (CountR >= CountB + 2 || CountB >= CountR + 2) {
        return "Impossible";
    }
    for (int i = 0; i < N; i++) {
        r.NearBegin.emplace(Coordinate{0, i});
        r.NearEnd.emplace(Coordinate{N - 1, i});
        b.NearBegin.emplace(Coordinate{i, 0});
        b.NearEnd.emplace(Coordinate{i, N - 1});
    }
    if (r.Connect()) {
        if (r.NoCutPoint || CountR + 1 == CountB) {
            return "Impossible";
        }
        return "Red wins";
    }
    if (b.Connect()) {
        if (b.NoCutPoint || CountB + 1 == CountR) {
            return "Impossible";
        }
        return "Blue wins";
    }
    return "Nobody wins";
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) Solution().Solve(i);
    return 0;
}