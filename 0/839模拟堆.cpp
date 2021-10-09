#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int n;

int h[N], hp[N], ph[N], cnt;
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int x)
{
    int t = x;
    if (x * 2 <= cnt && h[x * 2] < h[t])
        t = x * 2;
    if (x * 2 + 1 <= cnt && h[x * 2 + 1] < h[t])
        t = x * 2 + 1;
    if (t != x)
    {
        heap_swap(x, t);
        down(t);
    }
}
void up(int x)
{
    while (x / 2 && h[x / 2] > h[x])
    {
        heap_swap(x, x / 2);
        x >>= 1;
    }
}
//难在映射
//因为要实现随机的插入和删除
int main()
{
    int m = 0;
    cin >> n;
    while (n--)
    {
        string op;
        int x, y;
        cin >> op;
        if (op == "I")
        {
            cin >> x;
            h[++cnt] = x;
            ph[++m] = cnt;
            hp[cnt] = m;
            up(cnt);
        }
        else if (op == "PM")
            cout << h[1] << endl;
        else if (op == "DM")
        {
            heap_swap(1, cnt--);
            down(1);
        }
        else if (op == "D")
        {
            cin >> x;
            x=ph[x];
            heap_swap(x, cnt--);
            up(x), down(x);
        }
        else
        {
            cin >> x >> y;
            x=ph[x];
            h[x]=y;
            up(x), down(x);
        }
    }
    return 0;
}