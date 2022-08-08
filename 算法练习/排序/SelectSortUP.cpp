//选择排序
#include <cstdio>
#include <cstring>
const int maxn=1000;
void selectSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        int temp = A[i]; //交换A[k]与A[i]
        A[i] = A[k];
        A[k] = temp;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[maxn];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    selectSort(A, n);
    for (int j = 0; j < n; j++)
    {
        printf("%d ", A[j]);
    }
        printf("\n");
    return 0;
}