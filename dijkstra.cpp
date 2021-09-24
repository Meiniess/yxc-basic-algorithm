//最爱的城市
#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
int mp[maxn][maxn];
const int inf = 0x3f3f3f3f;
int n, m;
int dij(int s, int t)
{ //套用迪杰斯特拉算法的模板 不断更新位置来确定最短路径
    int dis[maxn], vis[maxn];
    for (int i = 1; i <= n; i++)
        dis[i] = inf, vis[i] = 0;
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = -1, min = inf;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && min > dis[j]) //vis[j]为0才能进行，也就是说每个点最终都会进行更新
                min = dis[k = j];        //每次挑选最小的dis的点继续更新与之连通的其他点的dis,并标记k=-1;
                                         //min=dis[j],k=j;
        }
        if (k == -1)
            break; //全图完成遍历 退出 返回求出的最短路径dis[t]
        vis[k] = 1;
        for (int j = 1; j <= n; j++)
            if (dis[j] > dis[k] + mp[k][j])
                dis[j] = dis[k] + mp[k][j]; //首次执行仅仅更新了与s连通的点的dis
    }
    return dis[t];
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                mp[i][j] = inf;
        }
        for (int i = 1; i <= m; i++)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            mp[a][b] = mp[b][a] = w;
        }
        int x, y;
        scanf("%d%d", &x, &y);
        int ans = dij(x, y);
        if (ans == inf)
        {
            printf("No path\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
}