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
        //如果栈顶比我当前的x大，那这就是一个逆序的关系，根据单调性，我们就可以把这个永远的删掉，即tt--

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
