#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int q[N], a[N];
int n, k;
int head = 0, tail = -1;
//单调队列
//同时维护一个固定大小的窗口
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < n; i++)
    {
        while (head <= tail && i - k + 1 > a[head])
            head++;
        while (head <= tail && q[a[tail]] >= q[i])
        {
            tail--;
        }
        a[++tail] = i;
        if (i  >= k-1)
            cout << q[a[head]] << ' ';
    }
    puts("");
    head=0,tail=-1;
    for (int i = 0; i < n; i++)
    {
        while (head <= tail && i - k + 1 > a[head])
            head++;
        while (head <= tail && q[a[tail]] <= q[i])
        {
            tail--;
        }
        a[++tail] = i;
        if (i  >= k-1)
            cout << q[a[head]] << ' ';
    }

    return 0;
}