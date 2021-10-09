#include<iostream>

using namespace std;

const int N=1e5+10,M=31e5+10;
int n;
int a[N],son[M][2],idx;

void insert(int x)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int t=x>>i&1;
        if(!son[p][t]) son[p][t]=++idx;
        p=son[p][t];
    }
}

int query(int x)
{
    int p=0,res=0;
    for (int i = 30; i >=0; i--)
    {
        int t=x>>i&1;
        if(son[p][!t]) res+=1<<i,p=son[p][!t];
        else p=son[p][t];
    }
    return res;
}

int main()
{
    int x,res=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        res=max(query(a[i]),res);
    }
    cout<<res;
    return 0;
}