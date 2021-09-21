#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
//邻接矩阵
int g[N][N];
//到原点的距离
int dist[N];
//搜索过的标志位
bool st[N];


int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    //与dijkstra算法的最大区别是，
    //p算法求得是最小生成树，而非一条路径
    //所以所有的点都要纳入集合
    //故，d算法更新的是所有点到原点的距离
    //p算法更新的是所有点到集合的距离
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        //找到没更新过的点中，距离最小的点
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;


        //如果未更新的点中没有距离小于INF的，则直接return INF
        if (i && dist[t] == INF) return INF;
        //将dist[t]直接加到res
        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}


int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);
    //读入
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}
