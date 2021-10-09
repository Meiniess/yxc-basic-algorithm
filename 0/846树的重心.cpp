#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10,M=N*2;
int n;
int h[N], e[M], ne[M], idx;
int st[N],ans=N;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int x)
{
    st[x] = 1;
    int size = 0, sum = 0;
    //遍历当前节点的所有子节点的连通块
    //找到所有子连通块的节点数目的最大值，同时取得子连通块的节点数的sum
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (st[j])
            continue;
        //取得子连通块的节点数
        int s = dfs(j);
        //size记录当前节点所有连通块的节点数的最大值
        size = max(size, s);
        sum += s;
    }
    //如果不是头结点，而是半路走到的节点，那是无法往回走的
    //也就是说，当前节点的父节点是遍历不到的
    //所以需要借助n-sum-1来求得
    size = max(size, n - sum - 1);
    //ans记录最小
    ans = min(ans, size);
    //返回当前连通块的节点数=子块总数+自身
    return sum + 1;
}

int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;

    return 0;
}