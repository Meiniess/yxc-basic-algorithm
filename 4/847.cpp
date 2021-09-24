#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
//邻接表
int h[N], e[N], ne[N], idx;
//记录路径距离
int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs()
{
    memset(d, -1, sizeof d);
    //先把第一个点入队当做引子
    queue<int> q;
    d[1] = 0;
    q.push(1);

    while (q.size())
    {
        //队列中取出一个点
        int t = q.front();
        q.pop();
        //枚举这个点的所有出边
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            //如果当前点没有更新过，则当前点等于出发点的距离+1，并且把当前点进队
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }

    return d[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}