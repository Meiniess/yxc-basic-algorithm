#include<iostream>
#include<algorithm>
using namespace std;
#define N  200010
int n,m;
int q[N/2];
struct Edge
{
    int a,b,c;
    
    bool operator< (const Edge &x) const 
    {
        return c< x.c;
    }
}edge[N];

int find(int x)
{
    if(q[x]!=x) q[x]=find(q[x]);
    return q[x];
}
//类似于prim算法找最小边的思路,引入了并查集结构
//将所有的边先排序，然后从头到尾依次
//通过并查集，如果两个边不连通，则将其联通，并且将边加入res
int main()
{
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[i]={a,b,c};
    }
    sort(edge,edge+m);
    for (int i = 1; i <= n; i ++ )q[i] = i; 
    int res=0,cnt=0;
    for (int i = 0; i < m; i++)
    {
        int a=edge[i].a,b=edge[i].b,c=edge[i].c;
        if(find(a)!=find(b)) 
        {
            q[find(a)]=find(b);
            res+=c;
            cnt++;
        }
    }
    if(cnt<n-1) puts("impossible");
    else cout<<res;
    return 0;
    
}