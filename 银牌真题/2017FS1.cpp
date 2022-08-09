#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;

//// 右排序！

/*
5 4
7
8
6
2
9
2 5
4 9
0 3
8 13
*/

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int C,N;
    cin >> C >> N;
    vector<int> chicken;
    vector<vector<int> > cow;
    for(int i = 0; i < C; i++) {
        int64 temp;
        cin >> temp;
        chicken.push_back(temp);
    }
    cow.resize(N);
    for(int i = 0; i < N; i++) {
        int64 left, right;
        cow[i].resize(2);
        cin >> left >> right;
        cow[i][0] = left;
        cow[i][1] = right;
    }
    sort(chicken.begin(),chicken.begin() + C);
    
    // for(int i = 0; i < C; i++) {
    //     cout << chicken[i] << '\n';
    // }
    
    sort(cow.begin(),cow.begin() + N, cmp);

    // for(int i = 0; i < N; i++) {
    //     cout << cow[i][0] << " " << cow[i][1] << '\n';
    // }

    int ans = 0;
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < N; j++) {
            if(cow[j][0] == -1) continue;
            if(chicken[i] >= cow[j][0] && chicken[i] <= cow[j][1]) {
                ans += 1;
                cow[j][0] = -1;
                break;
            }
        }
    }
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;

}



//2017 February Contest, Silver Problem 1. Why Did the Cow Cross the Road
/*
 Let's consider the chicken that has the earliest time preference for helping a cow out. If no cow wants to cross at that time, then we can ignore that chicken. Otherwise, we have some cows that we can assign to that chicken. Intuitively, we want to assign that chicken to the cow that stops wanting to cross the road the earliest, as this gives us the most flexibility to assign chickens to cows in the future.
 */
//鸡帮助牛学过马路
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <algorithm>
// #include <set>

// using namespace std;

// typedef pair<int,int> pii;

// multiset<int> chickens;
// vector<pii> cows;
// int C, N;

// int main(void)
// {
//   ifstream fin("helpcross.in");
//   ofstream fout("helpcross.out");

//   fin >> C >> N;
//   int x, y, total=0;
//   for (int i=0; i<C; i++) { fin >> x; chickens.insert(x); }
//   for (int i=0; i<N; i++) { fin >> x >> y; cows.push_back(pii(y,x)); }
//   sort (cows.begin(), cows.end());
//   for (int j=0; j<N; j++) {
//     multiset<int>::iterator which_chicken = chickens.lower_bound(cows[j].second);
//     if (which_chicken != chickens.end() && *which_chicken <= cows[j].first) {
//       total++;
//       chickens.erase(which_chicken);
//     }
//   }
//   fout << total << "\n";
//   return 0;
// }