#include <iostream>
using namespace std;

int arr1[100000];
int arr2[10000];

int q, n;
//我的
int bsearch_left(int num, int arr1[], int l, int r)
{
    if (l == r)
        return l;

    int mid = l + r >> 1, i = l, j = r;

    while (i < j)
    {
        //int mid = i + j >> 1;
        if (arr1[mid] < num)
        {
            i = mid + 1;
        }
        else if (arr1[mid] >= num)
        {
            j = mid;
        }
    }
    if (arr1[i] != num)
        return -1;

    return i;
}
int bsearch_right(int num, int arr1[], int l, int r)
{
    if (l == r)
        return l;

    int mid = l + r + 1 >> 1, i = l, j = r;
    while (i < j)
    {
        int mid = i + j + 1 >> 1;
        if (arr1[mid] <= num)
        {
            i = mid;
        }
        else if (arr1[mid] > num)
        {
            j = mid - 1;
        }
    }
    if (arr1[j] != num)
        return -1;

    return j;
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < q; i++)
        cin >> arr2[i];

    for (int i = 0; i < q; i++)
    {
        int left = bsearch_left(arr2[i], arr1, 0, n - 1);
        int right = bsearch_right(arr2[i], arr1, 0, n - 1);
        printf("%d %d\n", left, right);
    }
}
