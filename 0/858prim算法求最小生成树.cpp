#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;

int n, m;
int dist[N], st[N];
int g[N][N];
//prim算法实际上就是对dijkstra算法的一个变形
//与之相同的是，首先遍历找到附近点距离最小的一个，然后用这个点去更新其他的点
//只不过加入的一个内容是，找到最小边后要加入res
int prim()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }
        if (i && dist[t] == 0x3f3f3f3f)
            return dist[t];
        if (i)
            res += dist[t];
        st[t] = 1;
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    return res;
}
int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int t = prim();
    if (t == 0x3f3f3f3f)
        puts("impossible");
    else
        cout << t << endl;
    return 0;
}