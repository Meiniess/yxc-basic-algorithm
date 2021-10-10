#include<iostream>
#include<cstring>
using namespace std;
#define N 100010
#define M 200010

int  n,m;
int h[N],e[M],ne[M],idx;
int color[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//其原理在于，如果是二分图，则已经没有奇数环
//那么就利用深度搜索，首先从1~n遍历每一个点，对每一个点进行dfs并进行1和2的交替染色
//如果同一条边的两个点染了相同的颜色，return false
bool dfs(int t,int x)
{
    color[t]=x;

    for(int i=h[t];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!color[j])
        {
            if(!dfs(j,3-x)) return false;
        }
        else if(color[j]==x) return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
    }
    bool flag = true;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))
            {
                flag =false;
                break;
            }
        }
    }
    if(flag!=true) puts("No");
    else puts("Yes");
    return 0;
    
}

 