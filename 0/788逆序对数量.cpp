#include<iostream>

using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
int q[N],tmp[N];
ll res;

ll merge_sort(int q[],int l, int r)
{
    if(l>=r)  return 0;
    int mid=l+r>>1;
    ll res= merge_sort(q,l,mid)+merge_sort(q,mid+1,r);
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])
        {   
            tmp[k++]=q[i++];
        }
        else 
        {
            tmp[k++]=q[j++];
            res+=mid-i+1;
        }
    }
    while(i<=mid)
    {
        tmp[k++]=q[i++];
    }
    while(j<=r)
    {
        tmp[k++]=q[j++];
    }
    for(int i=l,j=0;i<=r;i++,j++)
    {
        q[i]=tmp[j];
    }
    return res;
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    ll res=merge_sort(q,0,n-1);
    cout<<res;
    return 0;

}