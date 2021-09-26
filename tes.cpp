#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;

const int N = 510;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dij(int x, int y)
{
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        st[t] = true;
    }
    return dist[y];
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(g, 0x3f, sizeof g);
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a][b] = g[b][a] = c;
        }
        int x, y;
        cin >> x >> y;
        int t = dij(x, y);
        if (t == 0x3f3f3f3f)
            printf("No path\n");
        else
            cout << t << endl;
    }
    return 0;
}
