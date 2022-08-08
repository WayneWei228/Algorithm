// 素数 第m 到 n 个素数 筛法 书 P164
// 题目概述：令Pi表示第i个数，现任意给两个正整数 M<=N<=10000，请输出Pm 到 Pn 的所有素数。
// 输入格式：输入在一行中给出的M和N，其间以空格分隔。
// 输出格式：输出从Pm～Pn 的所有素数， 每 10 个数字占一行， 其间以空格分隔，但行末不得有多余空格。
#include<cstdio>
const int maxn = 10000001;
int prime[maxn], num = 0;
bool p[maxn] = {0};

void Find_Prime(int n)
{
    for(int i = 2; i < maxn; i ++){
        if(p[i] == false){
            prime[num++] = i;
            if(num >= n) break;//只需要 n 个素数
            for(int j = i+i; j < maxn; j += i){
                p[j] = true;
            }
        }
    }
}


int main(){
    int m,n,count = 0;
    scanf("%d%d",&m,&n);
    Find_Prime(n);
    for(int i = m; i <= n; i ++){
        printf("%d",prime[i-1]);
        count ++;
        if (count % 10 != 0 && i < n) printf(" ");
        else printf("\n");
    }
    return 0;
}
