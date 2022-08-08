//USACO 2016 January Contest, Silver Problem 2. Subsequences Summing to Sevens
/*
 
 In this problem, we have a list of numbers. We want to find a sublist of numbers where the sum of the numbers is divisible by 7.

 Define a prefix of a list to be the first K numbers of the list. Note that any sublist of numbers can be obtained by taking some prefix of the original list and removing a smaller prefix of the list. Note furthermore that if you take the sums of the two prefixes, they have the same remainder when divided by 7.

 Therefore, for every prefix, we can compute the sum of the numbers in the prefix modulo 7, and keep track of the shortest and longest prefixes that when summed are equivalent to x modulo 7 for 0<x<7. The answer is then the maximum difference between the lengths of the shortest and longest prefixes over all x.
 */
//子序列的和能够被7整除
//若两个数相减%7==0,那么这两个数%7的余数一定相同！
//求出相同的一个余数第一次和最后一次之间的长度即是最长长度！ 但是我们不知道哪个余数最长，所以： 枚举0~6 共7个余数各自的最长长度，再在他们7个里找最长的！

/*
 
  1   3   5   5   7   8  。。。。
  sum(i,j)=sum(1,j)-sum(1,i-1)
  [sum(1,j)-sum(1,i-1)]%7=0
  sum(1,j)%7=sum(1,i-1)%7
   前缀和算法
 */
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int first[7];
    int last[7];
    fill(first,first+7,INT_MAX);
    fill(last,last+7,0);
    int currPref = 0;
    for(int i = 1; i <= n; i++) {
        int item_value;
        cin>>item_value;
        currPref += item_value;
        currPref %= 7;
        first[currPref] = min(first[currPref], i);
        last[currPref] = i;
    }
    int ret = 0;
    for(int i = 0; i < 7; i++) {
        if(first[i] <= n) {
            ret = max(ret, last[i] - first[i]);
        }
    }
    printf("%d",ret);
}
