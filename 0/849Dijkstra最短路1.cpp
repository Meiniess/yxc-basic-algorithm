#include <iostream>
#include <cstring>
using namespace std;

int n, m;
const int N = 510;
int g[N][N];
int dist[N];
bool st[N];
//本质还是bfs
//先遍历找到最小的点，然后用这个点去宽度更新临近点的dist数据
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            //遍历找到未更新的点中距离最小的点
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        st[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    else
        return dist[n];
}

int main()
{
    cin >> n >> m;
    //整个图初始化成无穷大，然后再输入
    memset(g,0x3f,sizeof g);
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    cout << dijkstra() << endl;
    return 0;
}