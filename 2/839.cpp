#include<iostream>

using namespace std;

//错误的代码
const int N=1e5+10;
int n,idx;
int q[N],hp[N],ph[N];
void down(int x)
{
    int t=x;
    if(t*2<=idx-1&&q[t]>q[t*2]) t=x*2;
    if(t*2+1<=idx-1&&q[t]>q[t*2+1]) t=x*2+1;
    if(x!=t)
    {
        heap_swap(q[x],q[t]);
        down(t);
    }
}
void heap_swap(int x,int y)
{
    swap(ph[hp[x]],ph[hp[y]]);
    swap(hp[x],hp[y]);
    swap(q[x],q[y]);
    
}
void up(int x)
{
    int t=x;
    if(t&&q[t]<q[t/2]) t=x/2;
    if(t&&q[t]<q[(t-1)/2]) t=(x-1)/2;
    if(x!=t)
    {
        heap_swap(q[x],q[t]);
        up(t);
    }
}

int main()
{
    string op;
    cin>>n;
    while(n--)
    {
        cin>>op;
        if(op=="I")
        {
            int x;
            cin>>x;
            q[idx++]=x;
            hp[idx-1]=x;
            ph[x]=idx-1;
            down(x),up(x);
            
        }
        else if(op=="PM") printf("%d",q[0]);
        else if(op=="DM")
        {
            q[0]=q[--idx];
            down(0);
        }
        else if(op=="D")
        {
            int k;
            cin>>k;
            k=hp[k];
            k=ph[k];
            swap(k,--idx);
            down(k),up(k);
        }
        else
        {
            int k,x;
            cin>>k>>x;
            k=hp[k];
            k=ph[k];
            q[k]=x;
            down(k),up(k);

        }
    }
}