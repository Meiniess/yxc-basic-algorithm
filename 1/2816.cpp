#include<iostream>


using namespace std;

const int N=1e5+10;

int n,m;


int main()
{
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)  cin>>a[i];
    for(int i=0;i<m;i++)  cin>>b[i];
    int i=0,j=0;
    for(;j<m;j++)
    {
        if(a[i]==b[j]) i++;
        
    }
  
    if(i==n) printf("Yes");
    else printf("No");
    return 0;
}