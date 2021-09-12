#include <iostream>
using namespace std;

const int N = 100000;
int n;
int q[N], tmp[N];
void mergesort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + ((r - l) >> 1);
    mergesort(q, l, mid), mergesort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        tmp[k++] = q[i] <= q[j] ? q[i++] : q[j++];
    }
    while (i <= mid)
    {
        tmp[k++] = q[i++];
    }
    while (j <= r)
    {
        tmp[k++] = q[j++];
    }
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    mergesort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d", q[i]);
    return 0;
}