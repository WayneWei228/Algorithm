//USACO 2021 January Contest, Silver Problem 2. No Time to Paint
/*
 For a candidate range (a,b), it suffices to compute the minimum number of strokes for the prefix of length a−1 and suffix of length N−b independently and add them up. Now I'll describe how to compute the minimum number of strokes for each prefix (suffixes are computed similarly).

 Let 𝚙𝚛𝚎𝚏𝚒𝚡[x] denote the answer for the prefix of length x. Given 𝚙𝚛𝚎𝚏𝚒𝚡[x], how do we compute 𝚙𝚛𝚎𝚏𝚒𝚡[x+1]?

 Let c denote the color of fence segment x+1. If c already appeared within the prefix of length x and there is no segment with a lighter color between the last occurrence of c and segment x+1, then we can simply extend the stroke that painted that previous occurrence of c to paint segment x+1 as well. In this case, 𝚙𝚛𝚎𝚏𝚒𝚡[x+1]=𝚙𝚛𝚎𝚏𝚒𝚡[x]. Otherwise, the best we can do is to use an additional stroke to paint the new occurrence of c, so 𝚙𝚛𝚎𝚏𝚒𝚡[x+1]=𝚙𝚛𝚎𝚏𝚒𝚡[x]+1.

 𝚙𝚛𝚎𝚏𝚒𝚡[x] - the answer for the prefix of length x
 
 c - the color of fence segment x+1
 
 The code below maintains the lightest color that has appeared since the last occurrence of color t in 𝚖𝚒𝚗_𝚜𝚒𝚗𝚌𝚎_𝚕𝚊𝚜𝚝[t]. When a new color c is added, we set 𝚖𝚒𝚗_𝚜𝚒𝚗𝚌𝚎_𝚕𝚊𝚜𝚝[t]=min(𝚖𝚒𝚗_𝚜𝚒𝚗𝚌𝚎_𝚕𝚊𝚜𝚝[t],c) for all t≠c and 𝚖𝚒𝚗_𝚜𝚒𝚗𝚌𝚎_𝚕𝚊𝚜𝚝[c]=c.
 
 𝚖𝚒𝚗_𝚜𝚒𝚗𝚌𝚎_𝚕𝚊𝚜𝚝[t] - the lightest color that has appeared since the last occurrence of color t
 
 Z C Z  𝚖𝚒𝚗_𝚜𝚒𝚗𝚌𝚎_𝚕𝚊𝚜𝚝[Z]=C
 X B X  𝚖𝚒𝚗_𝚜𝚒𝚗𝚌𝚎_𝚕𝚊𝚜𝚝[X]=B
 
 C B        𝚖𝚒𝚗_𝚜𝚒𝚗𝚌𝚎_𝚕𝚊𝚜𝚝[C]=B
 C B A      𝚖𝚒𝚗_𝚜𝚒𝚗𝚌𝚎_𝚕𝚊𝚜𝚝[C]=A
 C B A C
 */
#include <iostream>
using namespace std;
 
#define MAX_N 100000
int N, Q, min_since_last[26], prefix[MAX_N+1], suffix[MAX_N+2];
 
int main(void)
{
  string s;
  cin >> N >> Q >> s;
 
  // Build prefix counts of # of strokes needed
  for (int c=0; c<26; c++) min_since_last[c] = -1;
  for (int i=1; i<=N; i++) {
    int curchar = s[i-1] - 'A';
    for (int c=0; c<26; c++) min_since_last[c] = min(curchar, min_since_last[c]);
    prefix[i] = prefix[i-1];
    if (min_since_last[curchar] < curchar) prefix[i]++;
    min_since_last[curchar] = curchar;
  }
 
  // Build suffix counts of # of strokes needed
  for (int c=0; c<26; c++) min_since_last[c] = -1;
  for (int i=N; i>=1; i--) {
    int curchar = s[i-1] - 'A';
    for (int c=0; c<26; c++) min_since_last[c] = min(curchar, min_since_last[c]);
    suffix[i] = suffix[i+1];
    if (min_since_last[curchar] < curchar) suffix[i]++;
    min_since_last[curchar] = curchar;
  }
 
  for (int i=0; i<Q; i++) {
    int x, y;
    cin >> x >> y;
    cout << prefix[x-1] + suffix[y+1] << "\n";
  }
}


/*
 ABCD
 AAAA
 ABBB
 ABCC
 ABCD
 
 
 ABCDA
 AAAAA
 ABBBA
 ABCCA
 ABCDA
 
 ABCDAB
 AAAAAA
 ABBBAA
 ABCCAA
 ABCDAA
 ABCDAB
 
 
 ABAB
 AAAA
 ABBB
 ABAB
 
 BACDB
 
 
 
  Let c denote the color of fence segment x+1. If c already appeared within the prefix of length x and there is no segment with a lighter color between the last occurrence of c and segment x+1, then we can simply extend the stroke that painted that previous occurrence of c to paint segment x+1 as well. In this case, 𝚙𝚛𝚎𝚏𝚒𝚡[x+1]=𝚙𝚛𝚎𝚏𝚒𝚡[x]. Otherwise, the best we can do is to use an additional stroke to paint the new occurrence of c, so 𝚙𝚛𝚎𝚏𝚒𝚡[x+1]=𝚙𝚛𝚎𝚏𝚒𝚡[x]+1.
 
 ABDCBA
 AAAAAA
 ABBBBA
 ABDBBA
 ABDCBA
 */
