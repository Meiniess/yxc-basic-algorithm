#include <iostream>
#include <cstring>

using namespace std;
const int N = 510, M = 10010;
int n, m, k;
int dist[N], last[N];
struct edge
{
    int a, b, c;

} edge[M];

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    //只能走k步，所以只更新k次
    for (int i = 0; i < k; i++)
    {
        //每次更新用last数组记录初始值，来达到只更新了k次，也就是只走了k步的目的
        memcpy(last, dist, sizeof dist);
        //每次更新遍历所有的边，更新每个边的dist
        for (int j = 0; j < m; j++)
        {
            auto t = edge[j];
            dist[t.b] = min(dist[t.b], last[t.a] + t.c);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edge[i] = {x, y, z};
    }
    bellman_ford();
    //因为存在负权回路，所以可能会有一个正无穷大的点把第n个点更新成小于无穷
    if (dist[n] >= 0x3f3f3f3f / 2)
        puts("impossible");
    else
        cout << dist[n];
    return 0;
}