#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n,m;
const int N=1e5+10;
int d[N];
int h[N],e[N],ne[N],idx;
queue<int> t,q;
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//不断的找到入度为0的点，并将其指向边删去，最后若全部入队，则为拓扑序
bool bfs()
{
    //一个拓扑图至少存在一个点入度为0
    //遍历所有点，将入度为0的点入队
    for (int i = 1; i <= n; i++)
    {
        if(!d[i]) t.push(i);
    }
    
    while (t.size())
    {
        int temp=t.front();
        q.push(temp);
        t.pop();
        //遍历当前节点所有指向的节点，将其入度-1，若为0，入队
        for (int i = h[temp]; i!=-1; i=ne[i])
        {
            int j=e[i];
            if(--d[j]==0) t.push(j);
        }

    }
    //若队中有n个点，说明为拓扑图
    return q.size()==n;
    
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
       //通过d数组来记录有向图中点的入度
       d[b]++;
    }
    if(!bfs()) puts("-1");
    else 
    {
        for (int i = 0; i < n; i++)
        {
            cout<<q.front()<<' ';
            q.pop();
        }
        
    }
    
    return 0;
}