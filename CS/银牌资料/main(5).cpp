//USACO 2021 January Contest, Silver Problem 3. Spaced Out
/*
 The key observation is that in any valid arrangement, either every row will alternate between cow and no-cow, or every column will alternate between cow and no-cow.

 Proof:

 If no two cows are adjacent to each other, the statement is obviously met (both rows and columns will alternate in this case).

 Otherwise, suppose there are two cows next to each other. Assume without loss of generality that they are horizontally adjacent.

 ?????
 ?CC??
 ?????
 ?????
 ?????
 It is not hard to see that the only way to fill up the columns that these two cows occupy is by alternating between cow and no-cow:

 ?..??
 ?CC??
 ?..??
 ?CC??
 ?..??
 Now we have to fill up the remaining columns. Start from either column adjacent to an already-filled column. We notice that they also have to be filled by alternating between cow and no-cow; otherwise, there will always be a 2 by 2 square that has 1 cow or 3 cows. This holds true for every remaining column that we fill. Thus, the statement is proven.

 C..C.
 .CC.C
 C..C.
 .CC.C
 C..C.
 To solve the problem, we just consider both cases (rows alternating or columns alternating), and for each row/column, select the arrangement (there are only two of them, because it must be alternating) that results in the maximum beauty.
 */
#include <iostream>
 
#define ll long long
 
using namespace std;
 
ll grid[1000][1000];
 
int main() {
    int n;
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> grid[y][x];
        }
    }
    ll horizontalAnswer = 0;
    for (int y = 0; y < n; y++) {
        ll sums[2];
        sums[0] = 0;
        sums[1] = 0;
        for (int x = 0; x < n; x++) {
            sums[x % 2] += grid[y][x];
        }
        horizontalAnswer += max(sums[0], sums[1]);
    }
    ll verticalAnswer = 0;
    for (int x = 0; x < n; x++) {
        ll sums[2];
        sums[0] = 0;
        sums[1] = 0;
        for (int y = 0; y < n; y++) {
            sums[y % 2] += grid[y][x];
        }
        verticalAnswer += max(sums[0], sums[1]);
    }
    cout << max(horizontalAnswer, verticalAnswer) << "\n";
    return 0;
}


/*
 
 ?????
 ?CC??
 ?????
 ?????
 ?????
 
 ?????
 ?CC??
 ?????
 ?????
 ?????
 

 ?..??
 ?CC??
 ?..??
 ?CC??
 ?..??
 

 C..C.
 .CC.C
 C..C.
 .CC.C
 C..C.
 
 CCCCC
 .....
 CCCCC
 .....
 CCCCC
 
 .....
 CCCCC
 .....
 CCCCC
 .....
 
 CC...
 ..CCC
 CC...
 ..CCC
 CC...
 
 CC.CC
 ..C..
 CC.CC
 ..C..
 CC.CC
 
 
 C.C.C
 .C.C.
 C.C.C
 .C.C.
 C.C.C
 
 .C..C
 C.CC.
 .C..C
 C.CC.
 .C..C
 */
