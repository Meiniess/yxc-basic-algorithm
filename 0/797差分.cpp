#include <iostream>
using namespace std;

const int N=1e5+10;
int n,m;
int q[N],s1[N],s2[N];


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>q[i];
    }
    for(int i=1;i<=n;i++)
    {
        s2[i]=q[i]+s2[i-1];
    }
    while (m--)
    {
        int l ,r ,c;
        cin>>l>>r>>c;
        q[l]+=c,q[r+1]-=c;

    }
    for(int i=1;i<=n;i++)
    {
        s1[i]=q[i]+s1[i-1];
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<s1[i]-s2[i-1]<<' ';
    }
    
}