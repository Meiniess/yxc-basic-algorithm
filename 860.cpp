#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;

int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u, int c)
{
    //先对这个点染色
    color[u] = c;
    //然后遍历这个点的相关点
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        //如果相关点没染过色，则继续深搜染成3-c色，如果返回0，则false
        if (!color[j])
        {
            if (!dfs(j, 3 - c)) return false;
        }
        //如果染过，且与自身相同，则false
        else if (color[j] == c) return false;
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    //染色法
    bool flag = true;
    for (int i = 1; i <= n; i ++ )
        if (!color[i])
        {
            //深搜整个树，如果返回0，则flag=false
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }

    if (flag) puts("Yes");
    else puts("No");

    return 0;
}