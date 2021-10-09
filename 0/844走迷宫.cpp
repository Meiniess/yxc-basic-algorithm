#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int N = 110;
int n, m;
int s[N][N], st[N][N];

//与dfs的竖向遍历不同，bfs讲究的是横向遍历
//也就是一层一层的遍历
//在每一层，必须尝试过这一层的所有可能，才进入到下一层
//队列的先进先出机制就很好的维护了遍历一层的可能
int bfs()
{
    int col[] = {0, 1, 0, -1}, row[] = {1, 0, -1, 0};
    //st初始化-1，表示都没走过
    memset(st, -1, sizeof st);
    queue<pii> q;
    q.push({0, 0});
    //st用来记录走到当前点的步数
    st[0][0] = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        //遍历当前点位的上下左右四种可能
        for (int i = 0; i < 4; i++)
        {
            auto a = t.first + col[i], b = t.second + row[i];
            //确定某种可能的条件时，1.没走过 2.能走 3.不超上下左右的边界
            if (st[a][b] == -1 && s[a][b] == 0 && a >= 0 && a < n && b >= 0 && b < m)
            {
                st[a][b] = st[t.first][t.second]+1;
                q.push({a, b});
            }
        }
    }
    return st[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
        }
    }
    int res = bfs();
    cout << res;
    return 0;
}