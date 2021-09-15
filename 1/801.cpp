#include<iostream>

using namespace std;

const int N=1e5+10;
int n,m;
int s[N];


int lowbit(int x)
{
    return x&-x;
}
int main()
{
    scanf("%d",&n);
    
    
    while(n--)
    {   
        int res=0;
        scanf("%d",&m);
        while(m) m-=lowbit(m),res++;
        cout<< res<<' ';
    }
    return 0;
}