// SORT
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
    int x, y;
} ssd[10];

bool cmp(node a, node b)
{
    if (a.x != b.x)
        return a.x > b.x;
    else
        return a.y < b.y;
}

int main()
{
    ssd[0].x = 2;
    ssd[0].y = 2;
    ssd[1].x = 1;
    ssd[1].y = 3;
    ssd[2].x = 2;
    ssd[2].y = 1;
    sort(ssd, ssd + 3, cmp);
    for (int i = 0; i < 3; i++)
    {
        printf("%d %d\n", ssd[i].x, ssd[i].y);
    }
    return 0;
}