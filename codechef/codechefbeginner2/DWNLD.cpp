#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*
3

2 2
2 1
2 3

2 2
1 2
2 3

3 0
1 2
2 4
10 10

*/
// 模拟
struct extra {
    int time;
    int fee;
};
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        vector<extra> arr;
        arr.resize(N);
        for(int j = 0; j < N; j++) {
            int t, m;
            cin >> t >> m;
            arr[j].time = t;
            arr[j].fee = m;
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if(K >= arr[i].time) {
                K -= arr[i].time;
            } else
            {
                arr[i].time -= K;
                ans += arr[i].time * arr[i].fee;
                K = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

// 分解时间
// #include <cstdio>
// #include <vector>
// using namespace std;
// struct Solution
// {

//     int N, K;
//     vector<int> D;
//     void Solve()
//     {
//         scanf("%d%d", &N, &K);
//         for (int i = 0; i < N; ++i)
//         {
//             int t, d;
//             scanf("%d%d", &t, &d);
//             for (int j = 0; j < t; ++j)
//                 D.push_back(d);
//         }
//         int answer = 0;
//         for (int i = K; i < D.size(); ++i)
//             answer += D[i];
//         printf("%d\n", answer);
//     }
// };

// int main()
// {
//     int t;
//     scanf("%d", &t);
//     for (int i = 0; i < t; ++i)
//         Solution().Solve();
//     return 0;
// }