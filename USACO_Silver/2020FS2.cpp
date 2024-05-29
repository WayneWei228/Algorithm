#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll MAXN = 100005;
const ll MOD = 1e9 + 7;
const ll DIF = 10005;

struct Point {
    ll x, y;
} points[MAXN];

ll n, sumX[2 * DIF], sumY[2 * DIF], cntX[2 * DIF], cntY[2 * DIF];
ll lastX[2 * DIF], lastY[2 * DIF], ans;

bool cmp1(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

bool cmp3(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x > b.x;
    return a.y < b.y;
}

bool cmp4(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x > b.x;
    return a.y > b.y;
}

void work() {
    memset(sumX, 0, sizeof(sumX));//sumX数组，存每个x坐标对应的和目前是多少
    memset(sumY, 0, sizeof(sumY));//存每个y坐标对应的和
    memset(cntX, 0, sizeof(cntX));//存每个x坐标出现过多少个数字了
    memset(cntY, 0, sizeof(cntY));//存每个y坐标出现过多少个数字了
    for (ll i = 0; i < n; ++i) {//依次枚举每个点
        //用x和y记录一下当前点的x和y坐标，下面写起来轻松一点
        ll x = points[i].x, y = points[i].y;
        // cout << "x " << x - 10005 << " y " << y - 10005 << endl; 
        //当前x方向上的和，加上新点到上次的点的距离，乘以目前点的个数
        sumX[x] = (sumX[x] + abs(y - lastX[x]) * cntX[x]) % MOD;
        cntX[x]++;//多了一个点了
        lastX[x] = y;//记一下当前这个点的y值，下次跟这个来做差
        sumY[y] = (sumY[y] + abs(x - lastY[y]) * cntY[y]) % MOD;
        cntY[y]++;
        lastY[y] = x;
        cout << "sumX[x] " << sumX[x] << " sumY[y] " << sumY[y] << " lastX[x] " << lastX[x] << " lastY[y] " << lastY[y] <<  " cntX " << cntX[x] << " cntY " << cntY[y] << endl;

        ans = (ans + sumX[x] * sumY[y]) % MOD;//计算结果
        cout << "ans " << ans << endl;
    }
    cout << endl;
}

int main() {
    // freopen("triangles.in","r",stdin);
    // freopen("triangles.out","w",stdout);
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &points[i].x, &points[i].y);
        points[i].x += DIF;
        points[i].y += DIF;
    }
    //先延x从小到大，y从小到大的顺序排序，计算结果
    sort(points, points + n, cmp1);
    work();
    //其他方向依次处理
    sort(points, points + n, cmp2);
    work();
    sort(points, points + n, cmp3);
    work();
    sort(points, points + n, cmp4);
    work();
    printf("%lld\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}