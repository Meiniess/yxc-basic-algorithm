#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e5+10;
int n,m;
int h[N],e[N],w[N],ne[N],idx;
int dist[N],st[N];
void add(int a,int b,int c)
{
    w[idx]=c;
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//实际上是用队列优化的dijkstra算法
void spfa()
{
    
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    dist[1]=0;
    q.push(1);
    st[1]=true;
    while (q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;
        for (int i =h[t]; i !=-1; i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
        
    }
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while (m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    spfa();
    if(dist[n]==0x3f3f3f3f) puts("impossible");
    else cout<<dist[n];
    return 0;
    
}