#include <iostream>

using namespace std;

const int N = 100010;

int m;
//栈只要一个尾指针 ，就可满足后进先出
//队列用一个尾指针实现进队，用一个头指针实现出队，最终实现先进先出
int q[N], hh, tt = -1;

int main()
{
    cin >> m;

    while (m -- )
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[ ++ tt] = x;
        }
        else if (op == "pop") hh ++ ;
        else if (op == "empty") cout << (hh <= tt ? "NO" : "YES") << endl;
        else cout << q[hh] << endl;
    }

    return 0;
}