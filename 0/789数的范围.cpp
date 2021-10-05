#include<iostream>

using namespace std;
const int N=1e5+10;
int n,q;
int s[N];
int main()
{
    cin>>n>>q;
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    while (q--)
    {
        int k;
        cin>>k;
        int l=0,r=n-1;
        //取左边界，相等时r=mid
        while (l<r)
        {
            int mid=l+r>>1;
            if(s[mid]<k) l=mid+1;
            else r=mid;
        }
        if(s[l]!=k) cout<<"-1 -1"<<endl;
        else 
        {
            cout<<l<<' ';
            l=0,r=n-1;
            //取右边界，相等时l=mid
            while (l<r)
            {
                int mid=l+r+1>>1;
                if(s[mid]<=k) l=mid;
                else r=mid -1;
            }
            cout<<r<<endl;
            
        }

        
    }
    return 0;
    
    
    
}