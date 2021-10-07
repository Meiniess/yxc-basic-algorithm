#include<iostream>

using namespace std;
const int N=1e5+10;

int n,m;
int q[N];
int find(int x)
{
    if(q[x]!=x) q[x]=find(q[x]);
    return q[x];
}
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        q[i]=i;
    }
    while (m--)
    {
        string op;
        int x,y;
        cin>>op>>x>>y;
        if(op=="M") q[find(x)]=find(y);
        else 
        {
            if(find(x)==find(y)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
    
    
}