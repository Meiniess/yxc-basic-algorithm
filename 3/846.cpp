#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int n;
//邻接表：由N个单链表组成
//e[i]存的是node，ne[i]可以理解为图中的路
int h[N], e[M], ne[M], idx;
//最终答案
int ans = N;
//搜没搜过的标志位
bool st[N];

//图的加边
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
    st[u] = true;

    int size = 0, sum = 0;
    //从头i=h[u]开始，i!=-1,i=next[i]遍历u的这条路
    for (int i = h[u]; i != -1; i = ne[i])
    {
        //取这条路的第一个点
        int j = e[i];
        //如果搜索过这个点就找这条路上没搜过的点继续搜
        if (st[j])
            continue;

        int s = dfs(j);
        //取这这个节点所连通的所有连通块的点数的最大值
        size = max(size, s);
        //所有连通块的点数的和
        sum += s;
    }
    //取h[u]指向的连通块中的最大s和指向h[u]的连通块，这两者中的最大值
    size = max(size, n - sum - 1);
    //取所有ans中最小的那个
    ans = min(ans, size);
    //返回这条路上的sum加上自己
    return sum + 1;
}

int main()
{
    scanf("%d", &n);
    //头结点初始化
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        //a,b之间为一条无向边，图为无向图
        add(a, b), add(b, a);
    }
    //从1~n的节点
    dfs(1);

    printf("%d\n", ans);

    return 0;
}