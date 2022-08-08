//2018 December Contest, Silver, Problem 2. Convention II
//C++ pair 默认对first升序，当first相同时对second升序；
//Sorting Algorithm
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
using namespace std;

int N;
/*
 使用 typedef 关键字来定义自己习惯的数据类型名称，来替代系统默认的基本类型名称、数组类型名称、指针类型名称与用户自定义的结构型名称、共用型名称、枚举型名称等。
 
 
 
 虽然在接机上耽误了挺长时间，Farmer John 为吃草爱好牛们举行的大会至今为止都非常顺利。大会吸引了世界各地的奶牛。

 然而大会的重头戏看起来却给 Farmer John 带来了一些新的安排上的困扰。他的农场上的一块非常小的牧草地出产一种据某些识货的奶牛说是世界上最美味的品种的草。因此，所有参会的 N 头奶牛都想要品尝一下这种草。由于这块牧草地小到仅能容纳一头奶牛，这很有可能会导致排起长龙。

 Farmer John 知道每头奶牛i计划到达这块特殊的牧草地的时间 a_i
  ，以及当轮到她时，她计划品尝这种草花费的时间 t_i。当奶牛 i 开始吃草时，她会在离开前花费全部 t_i 的时间，此时其他到达的奶牛需要排队等候。如果这块牧草地空出来的时候多头奶牛同时在等候，那么资历最深的奶牛将会是下一头品尝鲜草的奶牛。在这里，恰好在另一头奶牛吃完草离开时到达的奶牛被认为是“在等待的”。类似地，如果当没有奶牛在吃草的时候有多头奶牛同时到达，那么资历最深的奶牛是下一头吃草的奶牛。

 请帮助 FJ 计算所有奶牛中在队伍里等待的时间（a_{i}到这头奶牛开始吃草之间的时间）的最大值。
 
 
 
 
 
*/
typedef long long LL;
typedef pair<LL,LL> pll;
// .first=arrival, .second.first=seniority, .second.second=duration
vector<pair<int, pll> > cows;

// .first=priority, .second=cow index
set<pll> waiting;

LL solve(void)
{
    LL answer = 0, current_finished;
    int next_cow_to_arrive = 1;
    sort(cows.begin(), cows.end());
    current_finished = cows[0].first + cows[0].second.second;
    while (next_cow_to_arrive < N || waiting.size() > 0) {
        while (next_cow_to_arrive < N &&
               cows[next_cow_to_arrive].first <= current_finished) {
            waiting.insert(make_pair(cows[next_cow_to_arrive].second.first,
                                     next_cow_to_arrive));
            next_cow_to_arrive++;
        }
        if (waiting.size() == 0 && next_cow_to_arrive < N) {
            // Idle time; schedule next cow...
            current_finished = cows[next_cow_to_arrive].first +
            cows[next_cow_to_arrive].second.second;
            next_cow_to_arrive++;
        } else if (waiting.size() > 0) {
            // Next-most-senior cow in waiting list scheduled next
            set<pll>::iterator most_senior = waiting.begin();
            answer = max(answer, current_finished - cows[most_senior->second].first);
            current_finished = current_finished +
            cows[most_senior->second].second.second;
            waiting.erase(most_senior);
        }
    }
    return answer;
}

int main(void)
{
    int a, t;
    ifstream fin ("convention2.in");
    fin >> N;
    //printf("%d",N);
    
    for (int i=0; i<N; i++) {
        fin >> a >> t;
        cows.push_back(make_pair(a,make_pair(i,t)));
    }
    
    ofstream fout ("convention2.out");
    fout << solve() << "\n";
    return 0;
}
