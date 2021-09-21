#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

struct Edge   {  int a, b, c; }   edges[M];

int n, m, k;
int dist[N];

int last[N];//备份数组

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;
    //迭代k次
    for (int i = 0; i < k; i++)
    {
        //备份，防止一次更新多条边
        memcpy(last, dist, sizeof dist);

        for (int j = 0; j < m; j++)
        {
            auto e = edges[j];
            //用备份的数据来做判断，防止更新多条边
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    bellman_ford();
    //可能存在负权边把无穷大的点更新成小于无穷
    if (dist[n] > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d\n", dist[n]);

    return 0;
}
