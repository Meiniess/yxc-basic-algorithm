#include <iostream>

using namespace std;

const int N = 100010;

int p[N];

int find(int x)
{
    //如果x的父节点p[x]!=x,就调用自身，递归查找p[p[x]]
    //最后将父节点复制给走过路径上的所有节点
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    //输入n个数，每个数都是一个集合
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    while (m -- )
    {
        //小技巧，用数组读入一个字符，以免输入出现空格等等
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M') p[find(a)] = find(b);
        else
        {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}