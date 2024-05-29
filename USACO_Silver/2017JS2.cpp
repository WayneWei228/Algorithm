#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100005
int N;

char A[MAXN];

struct count
{
    int p;
    int h;
    int s;
} arr[MAXN];

int win(int x)
{
    int a, b;
    a = max((arr[x].p), max(arr[x].s, arr[x].h));
    b = max((arr[N - 1].p - arr[x - 1].p), max((arr[N - 1].s - arr[x - 1].s), (arr[N - 1].h - arr[x - 1].h)));
    // printf("a %d\n",a);
    // printf("b %d\n",b);
    return a + b;
}

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int temp = A[0];
    bool flag = true;
    for (int i = 1; i < N; i++)
    {
        if (temp == A[i])
        {
            continue; 
        }
        flag = false;
        break;
    }
    if (flag)
    {
        cout << N << "\n";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if (A[0] == 'P')
    {
        arr[0].p += 1;
    }
    else if (A[0] == 'S')
    {
        arr[0].s += 1;
    }
    else
    {
        arr[0].h += 1;
    }

    for (int i = 1; i < N; i++)
    {
        arr[i].p += arr[i - 1].p;
        arr[i].s += arr[i - 1].s;
        arr[i].h += arr[i - 1].h;
        if (A[i] == 'P')
        {
            arr[i].p += 1;
        }
        else if (A[i] == 'S')
        {
            arr[i].s += 1;
        }
        else
        {
            arr[i].h += 1;
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << arr[i].p << ' ' << arr[i].s << ' ' << arr[i].h << "\n";
    // }
    int ans = 0;
    for (int i = 1; i < N - 1; i++)
    {
        ans = max(ans, win(i));
    }

    cout << ans << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}