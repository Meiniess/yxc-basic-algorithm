#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int n,m;
const int N=1e5+10;
int d[N];
int h[N],e[N],ne[N],idx;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int bfs()
{
    memset(d,-1,sizeof d);
    queue<int> q;
    q.push(1);
    d[1]=0;
    while (q.size())
    {
        
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(d[j]==-1)
            {
                d[j]=d[t]+1;
                q.push(j);
            }
        }
    }
    return d[n];
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for (int i = 0; i < m; i++) 
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs()<<endl;
    return 0;
}