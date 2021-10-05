#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, k;
int q[N];
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    //经常忘记，不return就会死循环
    int i = l - 1, j = r + 1, mid = q[l + r >> 1];
    //经常忘记，要从两边开始，因为进去是do-while
    //mid要放外面，while只循环一轮
    //数组在变化，mid要取实际的值，而非下标
    while (i < j)
    {

        do
            i++;
        while (mid > q[i]);
        do
            j--;
        while (mid < q[j]);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
int main()
{
    cin >> n>> k;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    quick_sort(q, 0, n - 1);

    cout << q[k - 1];

    return 0;
}