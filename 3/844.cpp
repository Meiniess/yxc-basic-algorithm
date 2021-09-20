#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;

int n, m;
int g[N][N], r[N][N];

int bfs()
{
    queue<PII> q;
    q.push({0, 0});
    memset(r, -1, sizeof r);
    r[0][0] = 0;
    int col[] = {1, -1, 0, 0}, row[] = {0, 0, -1, 1};

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {

            int a = t.first + col[i], b = t.second + row[i];
            if (r[a][b] == -1 && g[a][b] == 0 && a >= 0 && a < n && b >= 0 && b < m)
            {
                r[a][b] = r[t.first][t.second] + 1;
                q.push({a, b});
            }
        }
    }
    return r[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}