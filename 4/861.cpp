#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;

int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    { 
        int j = e[i];
        //防止多次搜索同一个点
        if (!st[j])
        {
            //先把这扇门关上，为当需要调剂时做准备
            st[j] = true;
            //如果是为配对状态，或者配对了但是能调剂状态都可以成功配对。
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    //匈牙利算法
    int res = 0;
    for (int i = 1; i <= n1; i ++ )
    {   
        //每换一个新的选手来配对，都要将候选人全部初始化为未配对状态
        //以为二对一的情况下更好的调剂
        memset(st, false, sizeof st);
        //如果配对成功就++
        if (find(i)) res ++ ;
    }

    printf("%d\n", res);

    return 0;
}