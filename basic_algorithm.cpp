#include <algorithm>
#include <iostream>

using namespace std;

//排序
//快速排序--分治
//归并排序
const int N = 1e6 + 10;
int n;
int q[N];
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do  i++;  while (q[i] < x);
        do  j--;  while (q[j] > x);
        if (i < j)  swap(q[i], q[j]);
    }
    //注意：如果用j做下一步递归，x不能取右边界；
    //如果用i做下一步递归，x不能取左边界
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <n;i++)  scanf("%d",&q[i]);
    
    quick_sort(q, 0, n-1);
    
    for(int i = 0;i<n;i++)     printf("%d",q[i]);
    
    return 0;
}
