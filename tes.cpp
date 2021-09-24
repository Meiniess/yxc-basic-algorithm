#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];

int dist[N];
bool st[N];

int dijkstra(int x, int y)
{
    //初始化dist为无穷大
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        //首先，确定一个点，这个点是没更新过的点中，到原点距离小于0x3f3f3f3f的
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        //其次，用确定好的点去更新其他的所有点
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        //将更新过的点打好标记
        st[t] = true;
    }
    //如果没更新到n，说明n走不到，返回-1

    return dist[y];
}

int main()
{
    int x, y;
    scanf("%d%d", &n, &m);
    //初始化g为无穷大
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            g[i][j] = INF;
    }
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        //如果有重边，则取最小的那个
        g[a][b] = g[b][a]=c;
    }
    cin >> x >> y;
    int t = dijkstra(x, y);
    if (t == 0x3f3f3f3f)
    {
        printf("No path\n");
    }
    else
    {
        printf("%d\n", t);
    }
    return 0;
}
