#include<iostream>

using namespace std;
int n,m;
const int N=1e5+10;
int q[N],cnt[N];

int find(int x)
{
    if(q[x]!= x) q[x]=find(q[x]);
    return q[x];
}
int main()
{
    string op;
    int x,y;
    cin>>n>>m;
    for(int i=0;i< n; i++)
    {
        q[i]=i;
        cnt[i]=1;
    }
    while(m--)
    {
        cin>>op;
        if(op=="C")
        {
            cin>>x>>y;
            x=find(x),y=find(y);
            if(x!=y)
            {
                q[x]=y;
                cnt[y]+=cnt[x];
            }
            
        }
        else if(op=="Q1")
        {
            cin>>x>>y;
            if(find(q[x])==find(q[y])) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else
        {
            cin>>x;
            cout<<cnt[find(x)]<<endl;
        }
    }
}