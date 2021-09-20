#include<iostream>

using namespace std;

const int N=10;
int n,idx;
int q[N];
bool st[N];
void dfs(int x)
{
    if(x==n) 
    {
        for(int i=0;i<n;i++)  printf("%d ",q[i]);
        cout<<endl;
        return;

    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            q[x]=i;
            st[i]=true;
            dfs(x+1);
            st[i]=false;
            

        }
    }

}

int main()
{
    cin>>n;
    dfs(0);
    return 0;
}