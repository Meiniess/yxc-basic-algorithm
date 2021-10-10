#include<iostream>

using namespace std;

const int N=210,INF=0x3f3f3f3f;
int n,m,k;
int g[N][N];
//floyd算法就是三重循环，遍历更新图的最小值
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++)
    {
        for(int j=1;j<=n;j++)
        //处理自环
        if(i==j) g[i][j]=0;
        else g[i][j]=INF;
    }
    while (m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        //处理重边
        g[x][y]=min(g[x][y],z);
    }

    floyd();
    while (k--)
    {
        int x,y;
        cin>>x>>y;
        //处理负权边
        if(g[x][y]>INF/2) puts("impossible");
        else cout<<g[x][y]<<endl;
    }
    return 0;
    
}