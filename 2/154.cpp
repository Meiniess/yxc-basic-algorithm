//单调队列&滑动窗口
#include <iostream>

using namespace std;

const int N = 1000010;
//q[]记录的是数组的下标，a[]是输入的数组
int a[N], q[N];
//基本思路，将队列中的冗余元素删掉，使队列形成单调递增或递减的单调性，那么每次找最小元素就取队头或队尾就可以了
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    //输出最小值
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        //如果头指针小于尾指针，且头超出k的范围，hh++
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;
        //遍历滑动窗口，如果窗口中有数比我当前数a[i]大，我就把他删掉，来维护一个单调递增的窗口
        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;
        //把i加入队尾
        q[ ++ tt] = i;
        //当i滑过k个数字之后可以开始打印
        //为什么是k-1  ,因为我们的i是从0开始数的
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;
        //遍历滑动窗口，如果窗口中有数比我当前数a[i]小，我就把他删掉，来维护一个单调递减的窗口
        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
        q[ ++ tt] = i;

        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");

    return 0;
}