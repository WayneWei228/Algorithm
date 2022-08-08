//2017 February Contest, Silver Problem 1. Why Did the Cow Cross the Road
/*
 Let's consider the chicken that has the earliest time preference for helping a cow out. If no cow wants to cross at that time, then we can ignore that chicken. Otherwise, we have some cows that we can assign to that chicken. Intuitively, we want to assign that chicken to the cow that stops wanting to cross the road the earliest, as this gives us the most flexibility to assign chickens to cows in the future.
 */
//鸡帮助牛学过马路
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int,int> pii;

multiset<int> chickens;
vector<pii> cows;
int C, N;

int main(void)
{
  ifstream fin("helpcross.in");
  ofstream fout("helpcross.out");

  fin >> C >> N;
  int x, y, total=0;
  for (int i=0; i<C; i++) { fin >> x; chickens.insert(x); }
  for (int i=0; i<N; i++) { fin >> x >> y; cows.push_back(pii(y,x)); }
  sort (cows.begin(), cows.end());
  for (int j=0; j<N; j++) {
    multiset<int>::iterator which_chicken = chickens.lower_bound(cows[j].second);
    if (which_chicken != chickens.end() && *which_chicken <= cows[j].first) {
      total++;
      chickens.erase(which_chicken);
    }
  }
  fout << total << "\n";
  return 0;
}
