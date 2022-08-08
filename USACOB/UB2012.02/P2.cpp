#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Rectangle {
    int X0, Y0, X1, Y1;
};

struct Discretize {
    vector<int> V;

    void Prepare() {
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
    }

    int ToID(int v) {
        return lower_bound(V.begin(), V.end(), v) - V.begin();
    }
};

typedef long long int64;

struct Solution {
    int N;
    vector<Rectangle> R;
    Discretize X, Y;

    void Solve() {
        scanf("%d", &N);
        R.resize(N);
        for (Rectangle& i : R) {
            scanf("%d%d%d%d", &i.X0, &i.Y1, &i.X1, &i.Y0);
            X.V.emplace_back(i.X0);
            X.V.emplace_back(i.X1);
            Y.V.emplace_back(i.Y0);
            Y.V.emplace_back(i.Y1);
        }
        X.Prepare();
        Y.Prepare();
        for (Rectangle& i : R) {
            i.X0 = X.ToID(i.X0);
            i.X1 = X.ToID(i.X1);
            i.Y0 = Y.ToID(i.Y0);
            i.Y1 = Y.ToID(i.Y1);
        }
        vector<vector<bool>> g(X.V.size());
        for (auto& i : g) i.resize(Y.V.size());
        for (Rectangle& i : R) {
            for (int iX = i.X0; iX < i.X1; ++iX) {
                for (int iY = i.Y0; iY < i.Y1; ++iY) g[iX][iY] = true;
            }
        }
        int64 answer = 0;
        for (int iX = 0; iX < X.V.size(); ++iX) {
            for (int iY = 0; iY < Y.V.size(); ++iY) {
                if (!g[iX][iY]) continue;
                int64 x = X.V[iX + 1] - X.V[iX];
                int64 y = Y.V[iY + 1] - Y.V[iY];
                answer += x * y;
            }
        }
        printf("%lld\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}