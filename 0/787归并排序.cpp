#include<iostream>

using namespace std;

int n;
const int N=1e5+10;
int q[N],tmp[N];
void merge_sort(int q[],int l ,int r)
{
    if(l>=r) return;
    int mid = l+r>>1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        tmp[k++]=q[i]>q[j]?q[j++]:q[i++];
    }
    while(i<=mid)
    {
        tmp[k++]=q[i++];
    }
    while(j<=r)
    {
        tmp[k++]=q[j++];
    }
     j=0;
    for(int i=l;i<=r;i++)
    {
        q[i]=tmp[j++];
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    merge_sort(q,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<q[i]<<' ';
    }
    return 0;
}