//2018 January Contest, Silver, Problem 2. Rental Service
/*一头牛卖奶还是租很明显要看哪个赚得钱更多。但是，对于某一头牛来说，假如它的产奶量高，虽然目前卖的钱更多，但是如果我贪心的卖了它，导致后期没牛卖得出去了(邻居个数是固定的)，后面的牛产的奶也没它多，那不是亏惨了吗? 我不如把它先留着，卖产奶量少的牛，因为每头牛卖出去的价格是相同的，无论产奶量多少。
 
 对于牛的产奶量排序并记录收益，然后假如有一个邻居出价比这个值还要高，那么就卖掉产奶量最少的一头牛，反之说明让这头牛产奶最优，于是让它产奶，然后初始化收益即可。*/
/*贪心: 1.留下产奶量多的奶牛; 2.卖orithm牛奶先卖给出价高的商铺; 3.把奶牛租给出价高的邻居。*/

//Greedy Algorithm
#include<iostream>
#include<algorithm>
#include <fstream>
#include<string>
using namespace std;
#define MAX_VALUE 100005
struct shop {
    int quantity;
    int price;
}shops[MAX_VALUE];

bool shop_cmp (shop a, shop b) {
    return a.price > b.price;
}
bool milkProduced_cmp(int a, int b) {
    return a > b;
}
bool rental_cmp(int a, int b) {
    return a > b;
}
int milkProduced[MAX_VALUE];
int rental[MAX_VALUE];
long maxProfit[MAX_VALUE];
int main() {
    // freopen("rental.in", "r",stdin);
    // freopen("rental.out","w",stdout);
    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++) {
        cin >> milkProduced[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> shops[i].quantity >> shops[i].price;
    }
    for(int i = 0; i < r; i++) {
        cin >> rental[i];
    }
    sort(milkProduced, milkProduced + n, milkProduced_cmp);
    sort(shops, shops + m, shop_cmp);
    sort(rental, rental + r, rental_cmp);
    int index = 0;
    for(int i = 0; i < n; i++) {
        maxProfit[i + 1] = maxProfit[i];
        while(index < m && milkProduced[i] > 0) {
            int use = min(milkProduced[i], shops[index].quantity);
            maxProfit[i + 1] += use * (long)shops[index].price;
            milkProduced[i] -= use;
            shops[index].quantity -= use;
            if(shops[index].quantity == 0) {
                index++;
            }
        }
    }
    int a = n - 1;
    int rI = 0;
    long rentalSoFar = 0;
    while (a >= 0 && rI < r) {
        rentalSoFar += rental[rI];
        maxProfit[a] += rentalSoFar;
        rI++;
        a--;
    }
    long ret = 0;
    for(int i = 0; i <= n; i++) {
        ret = max(ret,maxProfit[i]);
    }

    cout << ret << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
