#include <algorithm>
#include <iostream>

using namespace std;

const int N=100000;
int q[N];
int n,k;

void quick_sort(int q[],int l,int r)
{
    if(l>=r) return;
    int i=l-1,j=r+1;
    int mid=q[l+r>>1];//l+r>>1是对的  l+((r-l)>>1)是对的，l+(r-l)>>1是错的
    
    while (i<j)
    {
        do i++; while(mid>q[i]);
        do j--; while(mid<q[j]);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j),quick_sort(q,j+1,r);
    
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    quick_sort(q,0,n-1);
    printf("%d",q[k-1]);
}