//2019 January Contest, Silver, Problem 3. Mountain View
/*
 The key observation is that mountain i is occluded by mountain j (i.e. its peak is lies on the shape of mountain j) if and only if xi−yi≥xj−yj and xi+yi≤xj+yj: that is, the base of mountain i (the interval [xi−yi,xi+yi]) is contained in the base of mountain j.
 
 First suppose for simplicity that every xi−yi is distinct. Then if we sort the mountains in increasing order by xi−yi, a mountain is occluded if and only if for every previous mountain j, the inequality xj+yj<xi+yi holds. This is because the previous mountains are exactly the mountains j for which xj−yj<xi−yi. So as we sweep through the sorted list of mountains, we can keep track of the largest value of xj+yj seen so far, and use this to determine whether each new mountain in the list is occluded or visible.
 
 The same idea works even if not all xi−yi are distinct, but we need to be careful about how we break ties when sorting. For two mountains i and j with xi−yi=xj−yj and, say, xi+yi<xj+yj, we want mountain j to appear before mountain i in the sorted list, since i is occluded by j but not vice versa.
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN 100000

int N;
int x[MAXN], y[MAXN];
int pos[MAXN], neg[MAXN];
int cid[MAXN];

bool cmp(int a,int b)
{
    if(neg[a] == neg[b])
        return pos[a] > pos[b];
    return neg[a] < neg[b];
}

int main()
{
    freopen("mountains.in", "r",stdin);//输入重定向，输入数据将从mountains.in文件中读取
    freopen("mountains.out","w",stdout);  //输出重定向，输出数据将保存在mountains.out文件中
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> x[i] >> y[i];
        pos[i] = x[i]+y[i];
        neg[i] = x[i]-y[i];
        cid[i] = i;
    }
    sort(cid,cid+N,cmp);
    int mxpos = -1;
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        if(pos[cid[i]] > mxpos)
        {
            ans++;
            mxpos = pos[cid[i]];
        }
    }
    cout << ans << '\n';
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
    return 0;

}
