// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cstring>
// using namespace std;
// const int MAXN = 100005;

// int N;

// struct change
// {
//     int left;
//     int right;
// };

// change arr[MAXN];

// bool cmp(change x, change y)
// {
//     return x.left < y.left || (x.left == y.left && x.right > y.right);
// }

// int main()
// {
//     freopen("mountains.in", "r",stdin);
//     freopen("mountains.out","w",stdout); 
//     scanf("%d", &N);
//     for (int i = 0; i < N; i++)
//     {
//         int a, b;
//         scanf("%d%d", &a, &b);
//         arr[i].left = a - b;
//         arr[i].right = a + b;
//     }
//     sort(arr, arr + N, cmp);
//     int l = arr[0].left, r = arr[0].right;
//     int cnt = 1;
//     for (int i = 1; i < N; i++)
//     {
//         if (arr[i].left >= l && arr[i].right <= r)
//         {
//             continue;
//         }
//         l = arr[i].left;
//         r = arr[i].right;
//         cnt++;
//     }
//     printf("%d\n", cnt);
//     fclose(stdin);//关闭文件
//     fclose(stdout);//关闭文件
//     return 0;
// }

//===============================================================
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
