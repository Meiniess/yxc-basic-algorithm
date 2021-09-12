#include<iostream>
#include<algorithm>
using namespace std;
const int N=100000;
int n;
int q[N];
void quick_sort(int q[],int l, int r)
{
    if(l>=r) return;
    int mid=q[l + r >> 1],i=l-1,j=r+1;
    while(i<j)
    {
        do i++;while(mid>q[i]);
        do j--;while(mid<q[j]);
        if(i<j) swap(q[i],q[j]);
        
    }
    quick_sort(q,l,j),quick_sort(q,j+1,r);
}
int main()
{
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    int l=0, r=n-1;
    quick_sort(q,l,r);
    for(int i=0;i<n;i++) printf("%d ",q[i]);
    return 0;
}
