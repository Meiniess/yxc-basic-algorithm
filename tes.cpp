#include<iostream>

using namespace std;
int n;
const int N=1e5+10;
int q[N],tmp[N];
void mergesort(int q[],int l,int r)
{
    if(l>=r) return;
    int mid=l+r>>1;
    mergesort(q,l,mid);
    mergesort(q,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i <=mid&& j<=r)
    {
        tmp[k++]=q[i]>q[j]?q[i++]:q[j++];

    }
    while(i<=mid)
    {
        tmp[k++]=q[i++];
    }
    while(j<=r)
    {
        tmp[k++]=q[j++];
    }
    for(int i=0;i<n;i++)
    {
        q[i]=tmp[k++];
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    mergesort(q,0,n-1);
    for(int i=0;i<n;i++)  printf("%d",q[i]);
    return 0;
}