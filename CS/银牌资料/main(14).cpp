//2017 December Contest, Silver, Problem 1. My Cow Ate My Homework
/*
 We firstly note that due to the large bounds, we cannot directly simulate, for K increasing from 1 to N−2, which score will be taken away and the sum of the remaining scores. We have to be more clever in deducing the sum and the score.

 If, instead of simulating K increasing from 1 to N−2, we simulate the opposite direction of K decreasing from N−2 to 1, we can update the sum of the uneaten assignments in O(1) and also update the minimum score that is available in O(1).

 We present two solutions that indicate how we can take advantage of this observation.

 We generate an array of the sums of the last H homework assignments, as well as the minimum score present among the last H homework assignments. Computing the optimal values of K can then by done by reading off of these arrays directly.
 
 
 */
#include <iostream>
#include <fstream>
#include <algorithm>
const int MAX_N = 100000;
using namespace std;
 
long long score[MAX_N+1];
long long suffix_sum[MAX_N+1];
long long suffix_min[MAX_N+1];
long long best_num, best_den;
 
int main(void)
{
  //ifstream fin ("homework.in");
  //ofstream fout ("homework.out");
 
  int N;
  
  //fin >> N;
  cin >> N;
  for (int i=1; i<=N; i++)
    cin >> score[i];
  
  suffix_sum[N] = score[N];
  suffix_min[N] = score[N];
  for (int i=N-1; i>=1; i--) {
    suffix_sum[i] = suffix_sum[i+1] + score[i];
    suffix_min[i] = min(suffix_min[i+1], score[i]);
  }
 
  best_num = 0;
  best_den = 1;
  
  for (int i=1; i<=N-2; i++)
    if ((suffix_sum[i+1]-suffix_min[i+1]) * best_den > best_num * (N-i-1)) {
      best_num = suffix_sum[i+1]-suffix_min[i+1];
      best_den = N-i-1;
    }
   // cout<<best_num<<endl;
   // cout<<best_den<<endl;
  for (int i=1; i<=N-2; i++)
    if ((suffix_sum[i+1]-suffix_min[i+1]) * best_den == best_num * (N-i-1))
      cout << i << "\n";
  
  return 0;
}
