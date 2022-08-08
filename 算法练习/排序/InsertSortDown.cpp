//插入排序
#include <cstdio>
#include <cstring>
const int maxn = 1000;
int A[maxn];
int n;

void insertSort()
{
    for (int i = 0; i <= n - 1; i++)
    {
        int temp = A[i], j = i;
        while (j > 0 && temp > A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    insertSort();
    for (int j = 0; j < n; j++)
    {
        printf("%d ", A[j]);
    }
    printf("\n");
    return 0;
}