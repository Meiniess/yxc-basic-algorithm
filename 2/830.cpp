#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        //只输出一个，所以用一个while即可
        while (tt && stk[tt] >= x)
            tt--;
        if (!tt)
            printf("-1 ");
        else
            printf("%d ", stk[tt]);
        stk[++tt] = x;
    }

    return 0;
}
