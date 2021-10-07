#include<iostream>
using namespace std;

const int N=1e5+10;
int m,head=-1,idx;
int e[N],ne[N];
void insert_head(int x)
{
    ne[++idx]=head;
    head=idx;
    e[idx]=x;
}
void insert(int k,int x)
{
    ne[++idx]=ne[k];
    ne[k]=idx;
    e[idx]=x;
}
void remove(int k)
{
    ne[k]=ne[ne[k]];
}

int main()
{
    cin>>m;  
    while (m--)
    {
        char op[2];
        cin>>op;
        if(op[0]=='H')
        {
            int x;
            cin>>x;
            insert_head(x);
        }
        else if(op[0]=='D')
        {
            int k;
            cin>>k;
            if(!k) head=ne[head];
            else remove(k);
        }
        else
        {
            int x,k;
            cin>>k>>x;
            insert(k,x);
        }
    }
    int x=1;
    for(int i=head;i!=-1;i=ne[i])
    {
        cout<<e[i]<<' ';
    }
    return 0;
    
}