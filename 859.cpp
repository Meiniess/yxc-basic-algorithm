#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;
int p[N];

struct Edge
{
    int a, b, w;
    //重载小于号
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edges[M];
//并查集的模板，找到x的祖宗节点
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    //将所有边从小到大排序
    sort(edges, edges + m);
    //初始化并查集
    for (int i = 1; i <= n; i++)
        p[i] = i;

    int res = 0, cnt = 0;
    //一共有m条边，全遍历一遍，直到所有点都存入一个集合为止
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        //如果a，b不在一个集合中，边的权值加入，cnt++
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    //如果没有n-1条边，则return INF
    if (cnt < n - 1)
        return INF;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    int t = kruskal();

    if (t == INF)
        puts("impossible");
    else
        printf("%d\n", t);

    return 0;
}
