//2018 February Contest, Silver, Problem 1. Rest Stops
/*
 先将每个休息站按照美味值从大到小排序，然后从头到尾扫一遍，能吃就一直吃到FJ追上来为止。
 
Sorting Algorithm/Greedy Algorithm
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long l, n, rF, rB, total_taste, timespan;
struct Stop {
    long long dist, taste;
}stops[100000];

bool cmp (const Stop &s1, const Stop &s2) {
    return s1.taste > s2.taste;
}


int main() {
    cin >> l >> n >> rF >> rB;
    for(long long i = 1; i <= n; i++) {
        cin >> stops[i].dist >> stops[i].taste;
    }
    sort(stops + 1, stops + 1 + n, cmp);
    long long timespan = 0, farthest = 0, total_taste = 0;
    for(int i = 1; i <= n; i++) {
        if(stops[i].dist >= farthest) {
            farthest = stops[i].dist;
            if(stops[i].dist * rB + timespan <= stops[i].dist * rF) {
                total_taste += (stops[i].dist * (rF - rB) - timespan) * stops[i].taste;
                timespan = stops[i].dist * (rF - rB);
            }
        }
        else continue;
    }

    cout << total_taste << endl;
    return 0;
}